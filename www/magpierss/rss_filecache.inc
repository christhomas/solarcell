<?php
/*
 * Project:     MagpieRSS: a simple RSS integration tool
 * File:        rss_filecache.inc, a file based caching component for RSS feeds
 * Author:      Christopher Thomas <chris.alex.thomas@gmail.com>
 * Version:     0.1
 * License:     GPL
 *
 */
 
require_once(MAGPIE_DIR.'rss_cache.inc');

function create_cache()
{
	return new RSS_FileCache();
}
 
class RSS_FileCache extends RSS_Cache{
 	function init($base,$age){
		if($age) {
			$this->MAX_AGE = $age;
		}else{
			$this->MAX_AGE = MAGPIE_CACHE_AGE;
		}
		
		if($base) {
			$this->BASE_CACHE = $base;
		}else{
			$this->BASE_CACHE = "./cache";
		}
		
        // attempt to make the cache directory
        if ( ! file_exists( $this->BASE_CACHE ) ) {
            $status = @mkdir( $this->BASE_CACHE, 0755 );
            
            // if make failed 
            if ( ! $status ) {
                $this->error(
                    "Cache couldn't make dir '" . $this->BASE_CACHE . "'."
                );
            }
        }	
	}
	
/*=======================================================================*\
    Function:   set
    Purpose:    add an item to the cache, keyed on url
    Input:      url from wich the rss file was fetched
    Output:     true on sucess  
\*=======================================================================*/	
	function set($url,$rss){
        $this->ERROR = "";
		
        $cache_file = $this->cache_name( $url );
        $fp = @fopen( $cache_file, 'w' );
        
        if ( ! $fp ) {
            $this->error(
                "Cache unable to open file for writing: $cache_file"
            );
            return 0;
        }
        
        
        $data = $this->serialize( $rss );
        fwrite( $fp, $data );
        fclose( $fp );	
		
		return $cache_file;
	}
	
/*=======================================================================*\
    Function:   get
    Purpose:    fetch an item from the cache
    Input:      url from wich the rss file was fetched
    Output:     cached object on HIT, false on MISS 
\*=======================================================================*/ 
	function get($url){
        $this->ERROR = "";
		
		$cache_name = $this->cache_name( $url );
        
        if ( ! $this->cache_exists($cache_name) ) {
            $this->debug( 
                "Cache doesn't contain: $url (cache file: $cache_name)"
            );
            return 0;
        }
        
        $fp = @fopen($cache_name, 'r');
        if ( ! $fp ) {
            $this->error(
                "Failed to open cache file for reading: $cache_name"
            );
            return 0;
        }
        
        $data = fread( $fp, filesize($cache_name) );
        $rss = $this->unserialize( $data );	
		
		return $rss;
	}
	
/*=======================================================================*\
    Function:   check_cache
    Purpose:    check a url for membership in the cache
                and whether the object is older then MAX_AGE (ie. STALE)
    Input:      url from wich the rss file was fetched
    Output:     cached object on HIT, false on MISS 
\*=======================================================================*/  
	function check_cache($url){
        $this->ERROR = "";
		
        $cache_name = $this->cache_name( $url );
        
        if ( $this->cache_exists( $cache_name ) ) {
            // find how long ago the file was added to the cache
            // and whether that is longer then MAX_AGE
            $age = time() - $this->cache_timestamp($cache_name);
            if ( $this->MAX_AGE > $age ) {
                // object exists and is current
                return 'HIT';
            }
            else {
                // object exists but is old
                return 'STALE';
            }
        }
        else {
            // object does not exist
            return 'MISS';
        }	
	}
	
	function cache_name($url){
		$filename = md5( $url );
        return join( DIRECTORY_SEPARATOR, array( $this->BASE_CACHE, $filename ) );
	}
	
	function cache_exists($cache_name){
		return file_exists($cache_name);
	}
	
	function cache_timestamp($cache_name){
		return filemtime( $cache_name );
	}
}

?>
