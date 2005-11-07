<?php 
//	Default description (if rss is unavailable)
$description = <<<HTML
SolarCell is a GTK+ 2.0 application interface for the Lightwave ScreamerNet rendering subsystem. It 
  allows the control and rendering of a Lightwave scene through an easy to use graphical interface. Another 
  plus would be that it can run on linux, which enables people to build cheap renderfarms out of commodity 
  hardware and the absolutely free GNU/Linux Operating System.
HTML;

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

/* Debugging magpie stuff */
define('MAGPIE_DEBUG', 2);
//define('MAGPIE_CACHE_AGE', 20);
/* end debugging */
define('MAGPIE_CACHE_DIR', 'rsscache');
define('MAGPIE_CACHE_TYPE','session');
define('MAGPIE_CACHE_SOFTLIMIT',20*1024);
require_once('magpierss/rss_fetch.inc');

// load some RSS file
$rss = fetch_rss("http://sourceforge.net/export/rss2_projsummary.php?group_id=70906");

// here we can work with RSS fields
if($rss && ($rss->channel['title'] == "SourceForge.net: Project Summary: SolarCell (solarcell project)"))
{
	$newsData = "";
	foreach ($rss->items as $item) {
		$description = $item['description'];
		$tag = ": ";
		$description = substr($description,strpos($description,$tag)+strlen($tag));
		$newsData .= "<p>".$item['description']."</p>";		
	}
}else{
	//	Error
	print("Error: RSS Feed not found, here is a dump of the rss feed<br>");
	echo "<pre>";
	print_r($r);
	echo "</pre>";	
	die("quitting");
}

$scellContent .=<<<HTML
$newsData;
</div>
</div>
HTML;

$pageTitle = "SolarCell: Catch the lightwave";
include("skeleton.php");
?>

