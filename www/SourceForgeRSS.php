<?php
class SourceforgeRSS{
	//	Parse chunks from sourceforge rss
	function parseChunk(&$str,$token)
	{
		$pos = strpos($str,$token);
		if($pos !== false){
			if($pos) $match = substr($str,0,$pos);
			
			$str = substr($str,$pos+strlen($token));
			
			if(!$pos) $match = $str;
		}else{
			$match = "INVALID";
		}	
	
		return $match;
	}
	
	function parseTime(&$array, $time){
		$array['shortdate'] = date("D d/m/Y",strtotime($time));
		//	Convert the timestamp given in the rss feed into different format
		$array['time'] = date("g:i:s a", strtotime($time));
		$array['day'] = date("l",strtotime($time));
		$array['date'] = date("d",strtotime($time));
		$array['month'] = date("m",strtotime($time));
		$array['year'] = date("Y",strtotime($time));
		
	}

	function parseNews($item){
		$rssData['url'] = $item['link'];
		$rssData['author'] = $item['author'];
		$rssData['body'] = $item['description'];
		$rssData['fulldate'] = $item['pubdate'];
		$rssData['shortdate'] = date("D d/m/Y",strtotime($rssData['fulldate']));
		SourceforgeRSS::parseTime($rssData, $rssData['fulldate']);
		
		$rssData['headline'] = $item['title'];
		
		return $rssData;
	}
	
	function parseFileRelease($item){
		//	Grab the description and extract the filename from it
		$rssData['desc'] = $item['description'];
		/* painful lengthy extraction process cause fucking sscanf is shit */
		//	Skip the Released by beginning
		SourceForgeRSS::parseChunk($rssData['desc'],"<br />Released at ");
		
		//	grab the date and gather various sections of it separately
		$rssData['fulldate'] = SourceForgeRSS::parseChunk($rssData['desc']," by ");
		SourceforgeRSS::parseTime($rssData, $rssData['fulldate']);
				
		//	grab the submitter
		$rssData['user'] = SourceForgeRSS::parseChunk($rssData['desc'],"<br />Includes files: ");
		//	grab the filename
		$rssData['file'] = SourceForgeRSS::parseChunk($rssData['desc']," (");
		// grab the filesize
		$rssData['filesize'] = SourceForgeRSS::parseChunk($rssData['desc']," bytes, ");
		// grab the number of downloads
		$rssData['dlcount'] = SourceForgeRSS::parseChunk($rssData['desc']," downloads to date)<br /><a href=\"");
		//	grab the url
		$rssData['url'] = SourceForgeRSS::parseChunk($rssData['desc'],"\">[Download]</a>  <a href=\"");
		$rssData['url'] = str_replace("&","&amp;",$rssData['url']);
		//	grab the release notes
		$rssData['relnote'] = SourceForgeRSS::parseChunk($rssData['desc'],"\">[Release Notes]</a>");
	
		if(strpos($item['title'],"source") !== false) $rssData['binary'] = true;
		if(strpos($item['title'],"binary") !== false) $rssData['binary'] = false;
		
		unset($rssData['desc']);
				
		return $rssData;
	}
	
	function printFeedData($feed){
		print("<pre>");
		print_r($feed);
		print("</pre>");
	}
}
?>
