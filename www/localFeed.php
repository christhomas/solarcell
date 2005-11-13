<?php
/* Debugging magpie stuff */
//define('MAGPIE_DEBUG', 2);
define("MAGPIE_CACHE_AGE", 3600);
/* end debugging */
require_once("phpbase/SourceForgeRSS.php");
require_once("rsswriter.php");

$server = "http://".$_SERVER["HTTP_HOST"].substr($_SERVER["PHP_SELF"],0,strrpos($_SERVER["PHP_SELF"],"/"));

if(isset($_GET["getFeed"]) && $_GET["getFeed"] == "please"){
	define("MAGPIE_CACHE_ON", false);
	require_once("magpierss/rss_fetch.inc");	
	
	$site = "http://kosh.kmem.org/projects/solarcell/";
		
	$feed["summary"] = fetch_rss("http://sourceforge.net/export/rss2_projsummary.php?group_id=70906");
	$feed["news"] = fetch_rss("http://sourceforge.net/export/rss2_projnews.php?group_id=70906&rss_fulltext=1");
	$feed["files"] = fetch_rss("http://sourceforge.net/export/rss2_projfiles.php?group_id=70906");
	
	$rss = new RSSWriter(	$site, 
											"RSS site feed linker",
											"Antimatter Studios", 
											array(	"ams:publisher" => "Antimatter Studios", 
														"ams:creator" => "Christopher Alexander Thomas",
														"ams:filecount" => count($feed["files"]->items),
														"ams:screenshotcount" => 4,
														"ams:newscount" => count($feed["news"]->items))
										);
													
	$rss->useModule("ams", "http://kosh.kmem.org/projectRSSModule/");
	
	/*	Insert all the summary elements
	 * 
	 */
	$description = SourceforgeRSS::parseChunk($feed["summary"]->items[0]["description"],"Project description: ");
	$rss->addItem($site,"SolarCell",array(	"description" => $description,
																	"ams:category" => "summary"	));
	if($feed["files"]){
		foreach($feed["files"]->items as $item){
			$rssData = SourceforgeRSS::parseFileRelease($item);
			
			$rss->addItem($rssData["url"],$rssData["file"], array(	"ams:category" => "file",
																									"ams:count" => $rssData["dlcount"], 
																									"ams:size" => $rssData["filesize"],
																									"ams:date" => $rssData["shortdate"],
																									"ams:type" => $rssData["type"]));
		}
	}
		
	/*	Insert all the screenshot information
	 * 
	 */
	$base = $server."/images/screenshot";
	for($a=1;$a<5;$a++){
		$rss->addItem($base.$a."_thumb.png","Screenshot ".$a, 
						array(	"ams:category" => "screenshot", 
									"ams:full" => $base.$a.".png"));
	}
	
	/*	Insert all the news text
	 * 
	 */
	 if($feed["news"]){
		$numItem = 0;
		foreach($feed["news"]->items as $item){
			$rssData = SourceforgeRSS::parseNews($item);
			
			$rss->addItem($rssData["url"],$rssData["author"],array(	"description" => $rssData["headline"],
																										"ams:category" => "news",
																										"ams:newsID" => $numItem++,
																										"ams:body" => $rssData["body"],
																										"ams:date" => $rssData["shortdate"]));
		}
	 }	
	/*	Serialise out to the feed reader
	 * 
	 */
	$rss->serialize();
}else{
	define("MAGPIE_CACHE_ON", true);
	define("MAGPIE_CACHE_LOC", $_SERVER["DOCUMENT_ROOT"]."/rsscache");
	define("MAGPIE_CACHE_TYPE","file");
	define("MAGPIE_CACHE_SOFTLIMIT",20*1024);
	require_once("magpierss/rss_fetch.inc");
	
	//print("<pre>"); print_r($_SERVER); print("</pre>");

	// load some RSS file
	$rss = fetch_rss($server."/localFeed.php?getFeed=please");
}
?>
