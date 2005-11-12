<?php
//	Default description and news text(if rss is unavailable) 
$description = "There is no RSS Feed information: Try refreshing the page";
$newsText = $description;

include("localFeed.php");
//print("<pre>"); print_r($rss); print("</pre>");
if($rss && ($rss->channel["link"] == "http://kosh.kmem.org/projects/solarcell/")){
	$description = "";
	$newsText = "";
	
	foreach ($rss->items as $item) {
		if($item["ams"]["category"] == "summary"){
			$description = $item["description"];
		}
		
		if($item["ams"]["category"] == "news"){
			$newsText .= "<div class=\"newsItem\">";			
			$newsText .= "<div><b>".$item["ams"]["date"]."</b></div>";
			$newsText .= "<div><a href=\"news.php#".$item["description"]."\">".$item["description"]."</a></div>";
			$newsText .= "</div>";
		}		
	}
}

include("library.php");
$imgapp = getImageAppend();

$scellContent = <<<HTML
<div class="desc">
<img src="images/text_what$imgapp.png" alt="What is solarcell" />
<p>$description</p>
<img src="images/text_where$imgapp.png" alt="Where can I run solarcell" />
<p>At the moment, it's only able to run on the Linux platform, support for windows is quite possible 
  and in fact was the first platform I originally developed this software on. However this is really version 
  2, since I redeveloped this version based on the knowledge I obtained through developing the original 
  win32 version. I will port to win32 eventually. You just have to wait. If you are really interested, 
  you could show it by posting a message on a forum, or signing up for the mailing lists and requesting 
  it.</p>
<img src="images/text_how$imgapp.png" alt="How can I proceed" />
<p>Because of the very early status of SolarCell I decided that any binary release would just run out 
  of the folder it's contained within, it's such a tiny piece of software I can't imagine having an install 
  routine or even the need for RPM/DEB files, it's pretty much just a folder with an executable within, 
  you run it, you set it up, you have a nice day. I think doing anything more than this, would just be 
  my perverse sense of humour.</p>
</div>
<div class="news">
<div><img src="images/text_news$imgapp.png" alt="News section" /></div>
<div class="newsBody">
HTML;

$scellContent .=<<<HTML
$newsText
</div>
</div>
HTML;

$pageTitle = "SolarCell: Catch the lightwave";
include("skeleton.php");
?>

