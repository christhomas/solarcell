<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<title><?php print($pageTitle); ?></title>
<link href="solarcell.css" rel="stylesheet" type="text/css">
</head>

<body>
<div id="page">
<?php /* header */ 
	/* stop php complaining about can't find variable */
	if(!isset($banner)) $banner = ""; 
?>
<div id="scellhead">
	<div><img src="images/nav_head.png" alt="main logo image"></div>
	<div id="sflogo">
		<a href="http://sourceforge.net/projects/solarcell"> 
		<img src="http://sourceforge.net/sflogo.php?group_id=70906&amp;type=5" alt="SourceForge.net Logo">		</a>
	</div>
	<div id="slogan"><img src="images/nav_slogan.png" alt="solarcell slogan"></div>
	<div id="navbar">
		<a href="index.php"><img src="images/nav_home.png" alt="home page link"></a>
		<a href="download.php"><img src="images/nav_dl.png" alt="download link"></a>
		<a href="screenshots.php"><img src="images/nav_shots.png" alt="screenshots link"></a>
		<a href="faq.php"><img src="images/nav_faq.png" alt="frequently asked questions link"></a>
		<a href="http://sourceforge.net/projects/solarcell"><img src="images/nav_sf.png" alt="Sourceforge link"></a>	</div>
	<div id="text"></div>
	<div id="banner"><?php print($banner); ?></div>
</div>

<?php /* surround */ ?>
<div id="surround">
	<img class="left" src="images/box_tleft.png" alt="corner">
	<img class="right" src="images/box_tright.png" alt="corner">
	<div class="stopCollapse"></div>
	<div class="top"></div>
	
	<div class="m1"><div class="m2">
	<div class="content floatFix">
	<?php 
		if(isset($scellInclude)){
			include($scellInclude);
		}else if(isset($scellContent)){
			print($scellContent);
		}
	?>
	</div>
	</div></div>
	
	<img class="left" src="images/box_bleft.png" alt="corner">
	<img class="right" src="images/box_bright.png" alt="corner">
	<div class="bottom"></div>
</div>
<div class="clear"></div>

<?php include("footer.php"); ?>

</div>
</body>
</html>
