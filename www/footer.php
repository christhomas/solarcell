<?php
	$site = "http://".$_SERVER['SERVER_NAME'].$_SERVER['PHP_SELF'];
	$validateXHTML	= "http://validator.w3.org/check?uri=".$site;
	$validateCSS	= "http://jigsaw.w3.org/css-validator/validator?uri=".$site;
?>
<div id="footer">
	<div class="footerLeft">
		<a href="<?php print($validateXHTML); ?>">
		<img src="http://www.w3.org/Icons/valid-html401"
        alt="Valid XHTML 1.0 Strict" height="31" width="88"></a>
	</div>
	<div class="footerLeft">
		<a href="<?php print($validateCSS); ?>">
		<img style="border:0;width:88px;height:31px"
		src="http://jigsaw.w3.org/css-validator/images/vcss" alt="Valid CSS!"></a>
	</div>
	<div class="footerRight">
		<a href="http://kosh.kmem.org/antimatter">
		<img src="images/AntimatterLogoTiny.png" alt="Antimatter Studios Logo">
		</a>
	</div>
	<div>Website is copyright: <a href="http://kosh.kmem.org/antimatter/">Antimatter Studios Ltd 2005</a></div>
	<div>The Lightwave logo is copyright of Newtek</div>
</div>

