<?php
//	Default description and news text(if rss is unavailable) 
$description = "There is no RSS Feed information: Try refreshing the page";

include("localFeed.php");
//print("<pre>"); print_r($rss); print("</pre>");
if($rss && ($rss->channel['link'] == "http://solarcell.sf.net/")){
	$description = "";
	$scellContent = "<div class=\"newsBody\">";
	
	foreach ($rss->items as $item) {
		if($item["ams"]["category"] == "summary"){
			$description = $item['description'];
		}
		
		if($item["ams"]["category"] == "news"){
			$scellContent .= "<div><b>".$item["ams"]["date"]."</b></div>";
			$scellContent .= "<div><a name=\"".$item["description"]."\" href=\"".$item["link"]."\">".$item["description"]."</a></div>";
			$scellContent .= "<p>".$item["ams"]["body"]."</p>";
		}		
	}
	$scellContent .= "</div>";	
}

include("library.php");
$imgapp = getImageAppend();

$pageTitle = "SolarCell: Latest News";
include("skeleton.php");
?>

