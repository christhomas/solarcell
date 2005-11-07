<?php

// Bugs I am aware of:

//	1.
//	here is I'm not entirely sure how to tell the new page to display
//	the comment for the screenshot, without passing it through the URL, or a session variable

class Gallery
{
	var $html,$open,$column,$maxColumn;
	var $url,$tag,$width;
	
	function Gallery($maxColumn){
		$this->html = "";
		$this->open = false;
		$this->column = 0;
		$this->maxColumn = $maxColumn;
		$this->url = "#";
		$this->tag = "";
		$this->width = -1;
	}
	
	function setupWidth($width)
	{
		$this->width = $width;
	}
	
	function setupURL($url,$tag="")
	{
		$this->url = $url;
		$this->tag = $tag;
	}
	
	function addImage($img,$file,$desc){
		$imgDimensions = "";
		
		if(isset($_GET["screenShot"])){
			$imgClass = "screenShot";
		}else{
			$imgClass = "galleryImage";
		}
		$info = getimagesize($img);		
		if($this->width > 0 && $info[0] > $this->width) $imgDimensions = "width=\"".$this->width."\"";
		
		
		$href1 = $href2 = "";
		if($file != "#"){
			//	Only build a href statement if the url is NOT # (which means ignore me)
			if(strpos($this->url,"?")==false){ $app="?"; }else{ $app="&"; }
			$href1 = "<a href=\"".$this->url.$app.$this->tag."=".$file."\">";
			$href2 = "</a>";
		}
		
		$this->openRow();		
		
$this->html .= <<<END_IMAGE
<div class="$imgClass">
	<div>$href1<img src="$img" $imgDimensions alt="screenshot" />$href2</div>
	<div>$desc</div>
</div>
END_IMAGE;

		$this->closeRow();
	}
	
	function showBackButton($img,$url){
$this->html .= <<< END_TEXT
<div class="nav">
	<a class="galleryBack" href="$url"><img src="$img" alt="Back button" /></a>
</div>
END_TEXT;
	}
	
	function openRow(){
		if($this->open == false){
			$this->html .= "<div class=\"floatFix\">";
			$this->open = true;
		}
		$this->column = $this->column+1;	
	}
	
	function closeRow(){
		if($this->open == true && $this->column == $this->maxColumn){
			$this->html = $this->html."</div>";
			$this->open = false;
			$this->column = 0;
		}
	}
	
	function getHTML(){
		$this->maxColumn = $this->column; // force the row to close
		
		$this->closeRow();
		return $this->html;
	}
}
?>