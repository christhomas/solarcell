<?php

// $Id$
//
// A convenience class to make it easy to write RSS classes
// Edd Dumbill <mailto:edd+rsswriter@usefulinc.com>
//
// $Log$
// Revision 1.1  2005/11/12 00:52:06  chris_a_thomas
// huge commit to convert the website into a feed based site where the content is created dynamically from the output of the RSS feeds, works quite well and means I can link sites together and share information dynamically
//
// Revision 1.3  2001/05/20 17:58:02  edmundd
// Final distribution tweaks.
//
// Revision 1.2  2001/05/20 17:41:30  edmundd
// Ready for distribution.
//
// Revision 1.1  2001/05/20 17:01:43  edmundd
// First functional draft of code working.
//
// Revision 1.1  2001/05/17 18:17:46  edmundd
// Start of a convenience library to help RSS1.0 creation
//

class RSSWriter {

function RSSWriter($uri, $title, $description, $meta=array()) {
	$this->chaninfo=array();
	$this->website=$uri;
	$this->chaninfo["link"]=$uri;
	$this->chaninfo["description"]=$description;
	$this->chaninfo["title"]=$title;
	$this->items=array();
	$this->modules=array("dc" => "http://purl.org/dc/elements/1.1/");

	$server_name = $_SERVER["SERVER_NAME"];
	$request_uri = $_SERVER["REQUEST_URI"];
	if(isset($GLOBALS["SERVER_NAME"]) && isset($GLOBALS["REQUEST_URI"])){
		$server_name = $GLOBALS["SERVER_NAME"];
		$request_uri = $GLOBALS["REQUEST_URI"];
	}
	
	// thanks James Mills for bugfix to this line	
	$this->channelURI=str_replace("&", "&amp;", "http://" . $server_name . $request_uri);
	foreach ($meta as $key => $value) {
		$this->chaninfo[$key]=$value;
	}
}

function useModule($prefix, $uri) {
	$this->modules[$prefix]=$uri;
}

function setImage($imgURI, $imgAlt, $imgWidth=88, $imgHeight=31) {
	$this->image=array(
		"uri" => $imgURI, "title" => $imgAlt, "width" => $imgWidth,
		"height" => $imgHeight);
}

function addItem($uri, $title, $meta=array()) {
	$item=array("uri" => $uri, "link" => $uri, 
		"title" => $this->deTag($title));
	foreach ($meta as $key => $value) {
		if ($key == "description" || $key == "dc:description") {
			$value=$this->deTag($value);
		}
		$item[$key]=$value;
	}
	$this->items[]=$item;
}

function serialize() {
	$this->preamble();
	$this->channelinfo();
	$this->image();
	$this->items();
	$this->postamble();
}

function deTag($in) {
  while(ereg('<[^>]+>', $in)) {
	$in=ereg_replace('<[^>]+>', '', $in);
  }
  return $in;
}

function preamble() {
	header("Content-type: text/xml");
	print '<?xml version="1.0" encoding="iso-8859-1"?>
<rdf:RDF 
         xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
         xmlns="http://purl.org/rss/1.0/"
         xmlns:mn="http://usefulinc.com/rss/manifest/"
';
	foreach ($this->modules as $prefix => $uri) {
		print "         xmlns:${prefix}=\"${uri}\"\n";
	}
	print ">\n\n";
}

function channelinfo() {
	print '  <channel rdf:about="' .  $this->channelURI . '">';
	/*$i=$this->chaninfo;
	foreach (array("title", "link", "dc:source", "description", "dc:language", "dc:publisher",
		"dc:creator", "dc:rights") as $f) {
		if (isset($i[$f])) {
			print "    <${f}>" . htmlspecialchars($i[$f]) . "</${f}>\n";
		}
	}*/
	//	chris.alex.thomas@gmail.com: 
	//	fix to let me add my namespace items to the channel info (previously was blocked)
	$keys = array_keys($this->chaninfo);
	foreach($keys as $k){
		print "    <${k}>" . htmlspecialchars($this->chaninfo[$k]) . "</${k}>\n";
	}
	
	if (isset($this->image)) {
		print "    <image rdf:resource=\"" . htmlspecialchars($this->image["uri"]) . "\" />\n";
	}
	print "    <items>\n";
	print "      <rdf:Seq>\n";
	foreach ($this->items as $i) {
		print "        <rdf:li rdf:resource=\"" . htmlspecialchars($i["uri"]) . "\" />\n";
	}
	print "      </rdf:Seq>\n";
	print "    </items>\n";
	print "  </channel>\n\n";
}

function image() {
	if (isset($this->image)) {
	print "  <image rdf:about=\"" . htmlspecialchars($this->image["uri"]) . "\">\n";
    print "     <title>" . htmlspecialchars($this->image["title"]) . "</title>\n";
    print "     <url>" . htmlspecialchars($this->image["uri"]) . "</url>\n";
    print "     <link>" . htmlspecialchars($this->website) . "</link>\n";
    if ($this->chaninfo["description"]) 
   	 print "     <dc:description>" . htmlspecialchars($this->chaninfo["description"]) . 
   	 	"</dc:description>\n";
	print "  </image>\n\n";
	}
}

function postamble() {
	print '  <rdf:Description rdf:ID="manifest">
    <mn:channels>
      <rdf:Seq>
        <rdf:li rdf:resource="' . $this->channelURI . '" />
      </rdf:Seq>
    </mn:channels>
  </rdf:Description>

</rdf:RDF>
';
}

function items() {
	foreach ($this->items as $item) {
		print "  <item rdf:about=\"" .  htmlspecialchars($item["uri"]) . "\">\n";
		foreach ($item as $key => $value) {
			if ($key!="uri") {
				if (is_array($value)) {
					foreach ($value as $v1) {
						print "    <${key}>" . htmlspecialchars($v1) . "</${key}>\n";
					}
				} else {
					print "    <${key}>" . htmlspecialchars($value) . "</${key}>\n";
				}
			}
		}
		print "  </item>\n\n";
	}
}

}

?>
