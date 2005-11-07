<?php 
include("library.php");
$imgapp = getImageAppend();

$scellContent = <<< END_TEXT
<div>
	<a name="questionindex"></a>
	<img src="images/text_faq$imgapp.png" alt="Frequently Asked Questions" />
	<ol class="questions">
	  <li><a href="#question1">When does the Win32 version come out?</a></li>
	  <li><a href="#question2">An annoying bug is getting at me and I can't shake him off, They're everywhere!! Back to the shuttlepod!</a></li>
	  <li><a href="#question3">I want to help but I dont know how, am I too stupid? (Short Answer: No, you're not)</a></li>
	  <li><a href="#question4">Please please please add this feature!</a></li>
	  <li><a href="#question5">What are the goals of this project?</a></li>
	  <li><a href="#question6">What version of WINE do you use?</a></li>
	  <li><a href="#question7">I'd like to add a new item to the FAQ cause I think i'ts important</a></li>
	  <li><a href="#question8">I've downloaded SolarCell, so where is my free Suntan?</a></li>
	</ol>
</div>
<div>
	<p class="title">Answers</p>
	<ol>
		<li><a name="question1"></a><p class="questions">When does the Win32 version come out?</p>
		<p>As you no doubt read from the front page, the initial version was 
			  written on Win32, painstakingly hand coded and based upon the popular Lightwave Network Render 
			  Controller, Lightnet. I decided that my app would be similar, but not identical to this application 
			  since I believed that some functionality of that app was either badly set out or I just didnt 
			  think it was a good idea. This is my personal opinion of course and I extend every courtesy 
			  to </p>
		<p>Schoenmaekers Raf (www.komkomdoorn.com)</p>
		<p>Joe Justice for making Lightnet a continuing success.</p>
		<p>However, back to when does it come out. I intend to setup my other box with a gcc compiler 
			  and then it's just a case of compilation. I can't give you a timeframe since I dont have one 
			  myself, I also have no indication of how much a Win32 build would be of use to people, perhaps 
			  thats because instead of people asking for the Win32 build and therefore giving me an indication 
			  of how many people would use it. They read that it's a Linux application and close explorer, 
			  moving onto their next webpage.</p>
		<p>How about this. When my website design has completed and I get back to coding SolarCell, I'll 
			  make a push for a Win32 version, can't say fairer than that can I.</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question2"></a><p class="questions">An annoying bug is getting at me and I can't shake him off, They're everywhere!! 
		Back to the shuttlepod!</p>
		<p>If you find a bug which really gets to you, the best thing to do 
			  is first to attempt to contact a developer somehow. You can do this by posting a message to 
			  a mailing list, a forum or even to send an E-Mail to me personally. You can find this information, 
			  the forums and mailing list information from the SourceForge page. If you know more information 
			  about the bug then you could register with SourceForge and add a bug to the list yourself.</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question3"></a><p class="questions">I want to help but I dont know how, am I too stupid? (Short Answer: No, 
		you're not)</p>
		<p>Excellant. The more the merrier in my opinion. If you want to help 
			  then the best thing you can do is offer your help, or download the source and offer a patch. 
			  Some people are happier coming forward first and making it official while some other people 
			  like to lurk around and help without being too &quot;visible&quot; to the other people around 
			  them. As for knowing when the next source will be released and what was patched, I'm learning 
			  this as I go along and some people know the best way, I don't. If your idea of helping me is 
			  to show me a better way of organising this project, then I'll be grateful for all your help.</p>
			<p>As a rule I usually release a binary and source distribution at the same time. As for when 
			  I release them, I have a job and a social life, please dont kill me if I tell you just to wait 
			  until I get around to it. I'd like to automate as much as possible, but some things are not 
			  possible without a human to do it.</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question4"></a><p class="questions">Please please please add this feature!</p>
		<p>Ok, Ok, hold your horses. The best place to suggest new features 
			  are the mailings lists and forums. This FAQ is starting to sound like a broken record. I guess 
			  the best thing to do is to think about your new feature, flesh it out a bit, think about how 
			  it would work within the SolarCell application and if you are a developer, you could think about 
			  how your feature would be implemented and perhaps try to make a working, if not basic version 
			  of what you had in mind and show it to any SolarCell developer.</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question5"></a><p class="questions">What are the goals of this project?</p>
		<p>The final goal of SolarCell is to produce a Lightwave Render Controller 
			  with all the features of a commercial client, except the couple of hundred pounds you'd have 
			  to spend to aqcuire one. I'd like to be able to support secure FTP transfers of content data 
			  between Nodes (this would eliminate the need for sharing of folders between machines), automatic 
			  frame splitting and even breaking a scene up into layers so that each object can be rendered 
			  at a time and composited at a later date. I'm sure there is more but I could just run into pages 
			  and pages. Basically every requirement you would like and can find in a typical commerical client 
			  (Spider is one said example)</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question6"></a><p class="questions">What version of WINE do you use?</p>
		<p>Are you asking so you can download the same, or because you are 
			  just interested? Well anyway, I'm using this rpm</p>
			<p><a href="http://mecano.gme.usherb.ca/%7Evberon/wine/wine-20030115-1rh8winehq.athlon.rpm">wine-20030115-1rh8winehq.athlon.rpm</a></p>
			<p>which is pretty much the newest WINE I could get at this time. It does require some extra drive 
			  letters to be setup in the /home/usr/.wine/config file that allows SolarCell to automatically 
			  resolve unix paths into windows paths so they can be passed to SolarCell when it runs the windows 
			  version of ScreamerNet. A major step forward will be when you dont actually need to run ScreamerNet 
			  under WINE. The interesting thing I thought about, was that some people, even if they have access 
			  to a Linux ScreamerNet system, would still want to run the windows version through WINE, you 
			  know why? Plugins.</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
		<li><a name="question7"></a><p class="questions">I'd like to add a new item to the FAQ cause I think i'ts important</p>
		<p>Email it to me and I'll take a look at it.</p>
		<a href="#questionindex" class="linkTop">To the Top</a>
		</li>
		<li><a name="question8"></a><p class="questions">I've downloaded SolarCell, so where is my free Suntan?</p>
		<p>You are so gullable</p>
		<a href="#questionindex" class="linkTop">
			<img src="images/text_top$imgapp.png" alt="Goto top of page" />
		</a>
		</li>
	</ol>
</div>
END_TEXT;

$pageTitle = "SolarCell: Frequently Asked Questions";
include("skeleton.php"); 
?>
