<?php 
ini_set("display_errors", "On"); error_reporting(E_ALL);
//	Depending on the browser, will alter URL's for images 
//	so IE doesnt see PNG's with transparent backgrounds
include("library.php");
$imgapp = getImageAppend();

$description = "There is no RSS Feed information: Try refreshing the page";

include("localFeed.php");
if($rss && ($rss->channel['link'] == "http://solarcell.sf.net/")){
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

	$description = "Select either the source or an executable to download";

	foreach ($rss->items as $item) {		
		if($item["ams"]["category"] == "file"){
			
			if($item["ams"]["type"] == "source")	$updateRow = &$srcRow;
			if($item["ams"]["type"] == "binary")		$updateRow = &$exeRow;		
			
			//	Create a HTML link
			$link = "http://prdownloads.sourceforge.net/solarcell/".$item["title"]."?download";
			$link = "<a class=\"dlink\" href=\"".$link."\">".$item["title"]."</a>";
			
			$updateRow .= "<tr><td>".$item["ams"]["date"]."</td> <td>".$link."</td></tr>";
		}
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
	print("<pre>"); print_r($r); print("</pre>");	
	die("quitting");
}

/* Actual page content now */
$scellContent = <<< END_TEXT
<img src="images/text_dl$imgapp.png" alt="Download links" />
<p>$description</p>
$dlTable
END_TEXT;

$pageTitle = "SolarCell: Download";
include("skeleton.php");
?>