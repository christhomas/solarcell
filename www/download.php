<?php 
ini_set("display_errors", "On"); error_reporting(E_ALL);

//	Depending on the browser, will alter URL's for images 
//	so IE doesnt see PNG's with transparent backgrounds
include("library.php");
$imgapp = getImageAppend();

//	Default description (if rss is unavailable)
$description = <<<HTML
SolarCell is a GTK+ 2.0 application interface for the Lightwave ScreamerNet rendering subsystem. It 
  allows the control and rendering of a Lightwave scene through an easy to use graphical interface. Another 
  plus would be that it can run on linux, which enables people to build cheap renderfarms out of commodity 
  hardware and the absolutely free GNU/Linux Operating System.
HTML;

//	Default table contents (if rss is unavailable, 
//	probably badly maintained and shouldnt be used)
$dlTable = <<<END_TEXT
<table border="1" cellspacing="0" cellpadding="0" class="dlTable">
<tr id="tableTitle" valign="top"> 
	<td colspan="2" ><img src="images/text_src$imgapp.png" alt="Source code Download links" /></td>
	<td colspan="2" ><img src="images/text_exe$imgapp.png" alt="Executable Download links" /></td>
</tr>
<tr valign="top"> 
	<td class="questions">Date released</td>
	<td class="questions">Filename</td>
	<td class="questions">Date Released</td>
	<td class="questions">Filename</td>
</tr>
<tr valign="top"><td class="smalltext">09.01.2003</td>
	<td class="smalltext">
	<a href="http://prdownloads.sourceforge.net/solarcell/solarcell-0.5.tar.gz?download">solarcell-0.5.tar.gz</a></td>
	<td class="smalltext">09.01.2003</td>
	<td class="smalltext">
	<a href="http://prdownloads.sourceforge.net/solarcell/solarcell_bin_0.5.tar.gz?download">solarcell_bin_0.5.tar.gz</a></td>
</tr></table>
END_TEXT;

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

/* Debugging magpie stuff */
//define('MAGPIE_DEBUG', 2);
//define('MAGPIE_CACHE_AGE', 20);
/* end debugging */
define('MAGPIE_CACHE_DIR', 'rsscache');
define('MAGPIE_CACHE_TYPE','session');
define('MAGPIE_CACHE_SOFTLIMIT',20*1024);
require_once('magpierss/rss_fetch.inc');

$rss = fetch_rss("http://sourceforge.net/export/rss2_projfiles.php?group_id=70906");

if($rss && ($rss->channel['title'] == "SourceForge.net: Project File Releases: SolarCell"))
{
$srcRow = <<<HTML
<tr><td colspan="2" >
	<img src="images/text_src$imgapp.png" alt="Source code Download links" />
</td></tr>
<tr>
	<td class="title">Date</td>
	<td class="title">Filename</td>
</tr>
HTML;

$exeRow = <<<HTML
<tr><td colspan="2" >
	<img src="images/text_exe$imgapp.png" alt="Executable code Download links" />
</td></tr>
<tr>
	<td class="title">Date</td>
	<td class="title">Filename</td>
</tr>
HTML;

	foreach ($rss->items as $item) {
		//	Grab the description and extract the filename from it
		$desc = $item['description'];
		/* painful lengthy extraction process cause of fucking sscanf is shit */
		//	Skip the Released by beginning
		parseChunk($desc,"<br />Released at ");
		//	grab the date
		$date = parseChunk($desc," by ");
		//	grab the submitter
		$user = parseChunk($desc,"<br />Includes files: ");
		//	grab the filename
		$file = parseChunk($desc," (");
		// grab the filesize
		$size = parseChunk($desc," bytes, ");
		// grab the number of downloads
		$dload = parseChunk($desc," downloads to date)<br /><a href=\"");
		//	grab the url
		$url = parseChunk($desc,"\">[Download]</a>  <a href=\"");
		//	grab the release notes
		$rnote = parseChunk($desc,"\">[Release Notes]</a>");
	
		if(strpos($item['title'],"source") !== false) $updateRow = &$srcRow;
		if(strpos($item['title'],"binary") !== false) $updateRow = &$exeRow;
		
		//	Convert the timestamp given in the rss feed into different format
		$date = date("l, d/m/Y",strtotime($date));
		//	Create a HTML link
		$link = "http://prdownloads.sourceforge.net/solarcell/".$file."?download";
		$link = "<a class=\"dlink\" href=\"".$link."\">".$file."</a>";
		
		$updateRow .= "<tr><td>".$date."</td> <td>".$link."</td></tr>";
	}
	
$dlTable2 = <<<HTML
<table class="dlTable" cellspacing="5" cellpadding="0">
	$srcRow
	$exeRow
</table>
HTML;

	$dlTable = $dlTable2;
}else{
	//	Error
	print("Error: RSS Feed not found, here is a dump of the rss feed<br>");
	echo "<pre>";
	print_r($r);
	echo "</pre>";	
	die("quitting");
}

/* Actual page content now */
$scellContent = <<< END_TEXT
<img src="images/text_dl$imgapp.png" alt="Download links" />
<p>Select either the source or an executable to download</p>
$dlTable
END_TEXT;

$pageTitle = "SolarCell: Download";
include("skeleton.php");
?>