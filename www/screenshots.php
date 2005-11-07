<?php 
include("gallery.php");

include("library.php");
$imgapp = getImageAppend();

// Displaying a gallery or a single screenshot?

if(!isset($_GET["screenShot"])){
	// Setup the gallery data 
	
	$g = new Gallery(2);
	$g->setupURL("screenshots.php","screenShot");
	$g->setupWidth(400);
	$g->addImage(	"images/screenshot1_thumb.png",
					"images/screenshot1.png",
					"");
			
	$g->addImage(	"images/screenshot2_thumb.png",
					"images/screenshot2.png",
					"");
								
	$g->addImage(	"images/screenshot3_thumb.png",
					"images/screenshot3.png",
					"");
								
	$g->addImage(	"images/screenshot4_thumb.png",
					"images/screenshot4.png",
					"");

	$imageData = $g->getHTML();
}else{
	// Setup an individual screenshot to display instead 
	$g = new Gallery(1);
	$g->setupWidth(800);
	$g->addImage($_GET["screenShot"],"#","");
	$g->showBackButton("images/text_back".$imgapp.".png","screenshots.php");
	$imageData = $g->getHTML();
}

$scellContent = <<< END_TEXT
<img src="images/text_shots$imgapp.png" alt="Screenshot selection" />
<p>Select a screenshot to see a larger image</p>
<div id="gallery" class="floatFix">$imageData</div>
END_TEXT;

$pageTitle = "SolarCell: Screenshots";
include("skeleton.php");
?>
