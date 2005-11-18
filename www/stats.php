<?php

function updateStats()
{
	global $visitor;
	
	$filename = "/home/kosh/stats.solarcell";
	if(is_file($filename)){
		$handle = @fopen($filename, "r+");
		if($handle){
			$data = fgets($handle, 4096);
			
			$data = $data+1;
			
			@fseek($handle, 0);
			fputs($handle, $data);
			fclose($handle);
						
			$visitor = $data;								
		}
	}
}

?>