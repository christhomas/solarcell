<?php
function getImageAppend(){
	if(strpos($_SERVER['HTTP_USER_AGENT'], "MSIE") !== false){
		return "_ie";
	}
}
?>