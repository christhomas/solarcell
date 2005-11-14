<?php
/*
 * Project:     MagpieRSS: a simple RSS integration tool
 * File:        rss_cache.inc, a simple, rolling(no GC), cache 
 *              for RSS objects, keyed on URL.
 * Author:      Kellan Elliott-McCrea <kellan@protest.net>
 * Version:     0.51
 * License:     GPL
 *
 * The lastest version of MagpieRSS can be obtained from:
 * http://magpierss.sourceforge.net
 *
 * For questions, help, comments, discussion, etc., please join the
 * Magpie mailing list:
 * http://lists.sourceforge.net/lists/listinfo/magpierss-general
 *
 */

class RSS_Cache {
	var $MAX_AGE    = 3600;	// when are files stale, default one hour
    var $ERROR      = "";	// accumulate error messages
    var $BASE_CACHE = "";	// where the cache files are stored
 
/*=======================================================================*\
    Function:   serialize
\*=======================================================================*/     
    function serialize ( $rss ) {
        return serialize( $rss );
    }

/*=======================================================================*\
    Function:   unserialize
\*=======================================================================*/     
    function unserialize ( $data ) {
        return unserialize( $data );
    }
	
/*=======================================================================*\
    Function:   error
    Purpose:    register error
\*=======================================================================*/         
    function error ($errormsg, $lvl=E_USER_WARNING) {
        // append PHP's error message if track_errors enabled
        if ( isset($php_errormsg) ) { 
            $errormsg .= " ($php_errormsg)";
        }
        $this->ERROR = $errormsg;
        if ( MAGPIE_DEBUG ) {
            trigger_error( $errormsg, $lvl);
        }
        else {
            error_log( $errormsg, 0);
        }
    }
    
    function debug ($debugmsg, $lvl=E_USER_NOTICE) {
        if ( MAGPIE_DEBUG ) {
            $this->error("MagpieRSS [debug] $debugmsg", $lvl);
		}
    }
}

?>
