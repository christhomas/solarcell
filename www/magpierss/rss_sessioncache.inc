<?php
/*
 * Project:     MagpieRSS: a simple RSS integration tool
 * File:        rss_sessioncache.inc, a file based caching component for RSS feeds
 * Author:      Christopher Thomas <chris.alex.thomas@gmail.com>
 * Version:     0.1
 * License:     GPL
 *
 */
 
/*
	Define a soft and hard limit for feed serialize length
	
	limits are computed as the ENTIRE feed array length, so if you have 
	a 50KB hard limit, one feed which is 49KB, you're quota is now 1KB

	so they accumulative for all feeds and only at this time apply to RSS_SessionCache
	since it's the one which has obvious limitations.
	(storing a 100MB feed in a session variable	you're nuts)

	soft:	is a limit where php won't complain there is a problem
			you can break this limit, but php will display an error
			
	hard:	is where you CANNOT and WILL NOT break under and circumstance
			you will get a error and the cache will refuse to store it if you 
			break this, sorry, but you can't go hammering other people's 
			webhosts with huge session data
*/
if(!defined('MAGPIE_CACHE_SOFTLIMIT') ) {
	define('MAGPIE_CACHE_SOFTLIMIT', 10 * 1024);
}
if(!defined('MAGPIE_CACHE_HARDLIMIT') ) {
	define('MAGPIE_CACHE_HARDLIMIT', 50 * 1024);
} 
 
require_once(MAGPIE_DIR.'rss_cache.inc');

function create_cache()
{
	return new RSS_SessionCache();
}
 
class RSS_SessionCache extends RSS_Cache{
	function init($base,$age){
		if($age) {
			$this->MAX_AGE = $age;
		}else{
			$this->MAX_AGE = MAGPIE_CACHE_AGE;
		}
		
		if($base) {
			$p = strrchr($base,"/");
			if($p !== false) $base = substr($base,$p+1);	
			$this->BASE_CACHE = $base;
		}else{
			$this->BASE_CACHE = "magpie";
		}
		
		session_start();
		
		//	Initialise size tracking session variables
		if( !isset($_SESSION[$this->BASE_CACHE]['size']) ){
			$_SESSION[$this->BASE_CACHE]['size'] = 0;
			$_SESSION[$this->BASE_CACHE]['soft'] = MAGPIE_CACHE_SOFTLIMIT;
			$_SESSION[$this->BASE_CACHE]['hard'] = MAGPIE_CACHE_HARDLIMIT;
		}
		
		//	Clean out the old items from the cache
		//	perhaps this should only run every x seconds 
		//	instead of every script/page load
		$this->clean();
	}
	
/*=======================================================================*\
    Function:   clean
    Purpose:    looks through the cache, for items which are STALE
    Input:      (none)
    Output:     (none)
\*=======================================================================*/
	function clean(){
		//	Obtain a list of array keys inside the BASE_CACHE array
		$keys = array_keys($_SESSION[$this->BASE_CACHE]);
	
		//	loop through the keys you have
		foreach($keys as $k){
			//	ignore size/soft/hard/_timestamp, they are control variables
			//	(	timestamp is ignored because it's paired with the key 
			//		for the cache and can't be treated singly )
			if($k != "size" && $k != "soft" && $k != "hard" && strpos($k,"_timestamp") === false){
				//	obtain the age of the cache
				$age = time() - $this->cache_timestamp($k);
				if($age > $this->MAX_AGE){
					//	TO OLD! time to kick the bucket
					$this->debug("Removing ".$k." from the cache");
					$this->remove($k);
				}
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
		
		//	There is a further optimisation here, if the data in the session is IDENTICAL
		//	to the data just arrived from the feed, update the timestamp and then just 
		//	drop out, it's already present
		
		//	Serialise the feed and obtain it's length
		$rss = $this->serialize($rss);
		$rsslen = strlen($rss);
		
		//	Obtain the cache name for this feed and the current size of the cache
		$cache_name = $this->cache_name($url);
		$newsize = $_SESSION[$this->BASE_CACHE]['size'];
		
		$this->debug("Current cache size: ".newsize);		
		
		//	Check if the feed is already cached, if so, reduce the cache size by the amount
		//	you're going to remove from the cache
		//	remember, you may remove 10KB of data, only to add it back later
		//	but this is still the right thing to do
		if($this->check_cache($cache_name) != "MISS"){
			$newsize -= strlen($_SESSION[$this->BASE_CACHE][$cache_name]);
		}

		//	Now add the amount of data you want to cache			
		$newsize += $rsslen;		
		
		//	Compute the new size of all the feed data
		if($newsize < $_SESSION[$this->BASE_CACHE]['hard']) {
			//	The amount of data does not break the hard limit
			
			if($newsize > $_SESSION[$this->BASE_CACHE]['soft']){
				//	soft limit broken, warn user of potential problems
				$this->debug("Cache warning, soft limit broken", E_USER_NOTICE);
			}
			
			$this->debug("Updated cache size is: ".$newsize);

			//	Remove the original cache, add the new one
			$this->remove($cache_name);
			$this->add($rss,$cache_name,$newsize);
						
			return $cache_name;
		}else{
			//	hard limit broken, impose barrier
			$this->debug("Cache warning: hard limit reached, caching prevented", E_USER_NOTICE);
		}
    		
		return "REFUSED";	
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
        
		if(!$this->cache_exists($cache_name) ) {
			$this->debug( 
                "Cache doesn't contain: $url (cache name: $cache_name)"
            );
            return 0;
        }

		$data = $_SESSION[$this->BASE_CACHE][$cache_name];
        
		if(strlen($data) == 0){
            $this->error(
                "Failed to open cache for reading: $cache_name"
            );
            return 0;
        }
        
        return $this->unserialize( $data );
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
			$this->debug("Found cache instance: ".$cache_name, E_USER_NOTICE);
            // find how long ago the file was added to the cache
            // and whether that is longer then MAX_AGE
            $age = time() - $this->cache_timestamp($cache_name);
			$this->debug("Age of cache item: ".$age);
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
	
	function add($rss, $cache_name, $len){
		//	Add the new data to the cache			
		$_SESSION[$this->BASE_CACHE]['size'] = $len;
		$_SESSION[$this->BASE_CACHE][$cache_name] = $rss;
		$_SESSION[$this->BASE_CACHE][$cache_name.'_timestamp'] = time();	
	}
	
	function remove($cache_name){
		if($this->cache_exists($cache_name)){
			$len = strlen($_SESSION[$this->BASE_CACHE][$cache_name]);
			$_SESSION[$this->BASE_CACHE]['size'] -= $len;
		
			unset($_SESSION[$this->BASE_CACHE][$cache_name]);
			unset($_SESSION[$this->BASE_CACHE][$cache_name.'_timestamp']);
		}
	}
	
	
	function cache_name($url){
		return md5( $url );
	}
	
	function cache_exists($cache_name){
		return isset($_SESSION[$this->BASE_CACHE][$cache_name] );
	}
	
	function cache_timestamp($cache_name){
		return $_SESSION[$this->BASE_CACHE][$cache_name.'_timestamp'];
	}
}

?>
