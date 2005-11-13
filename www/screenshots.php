<?php 
include("phpbase/gallery.php");

include("library.php");
$imgapp = getImageAppend();

$description = "There is no RSS Feed information: Try refreshing the page";

// Displaying a gallery or a single screenshot?
	$g = new Gallery();
	
if(!isset($_GET["screenShot"])){
	$g->setupColumns(2);
	$g->setupURL("screenshots.php","screenShot");
	$g->setupWidth(400);

	// Setup the gallery data 
	include("localFeed.php");
	if($rss && ($rss->channel['link'] == "http://kosh.kmem.org/projects/solarcell/")){
		$description = "Select a screenshot to see a larger image";

		foreach($rss->items as $item){
			if($item["ams"]["category"] == "screenshot"){
				$g->addImage($item["link"],$item["ams"]["full"],$item["title"]);
			}
		}
	}
}else{
	// Setup an individual screenshot to display instead 
	$g->setupColumns(1);
	$g->setupWidth(800);
	$g->addImage($_GET["screenShot"],"#","");
	$g->showBackButton("images/text_back".$imgapp.".png","screenshots.php");
	
	$description = "Click the back button to return to the gallery";
}

$imageData = $g->getHTML();

$scellContent = <<< END_TEXT
<img src="images/text_shots$imgapp.png" alt="Screenshot selection" />
<p>$description</p>
<div id="gallery" class="floatFix">$imageData</div>
END_TEXT;

$pageTitle = "SolarCell: Screenshots";
include("skeleton.php");
?>
