/*
 * webPage.h
 *
 * Created: 3/19/2016 10:31:48 AM
 *  Author: Nate
 */ 


#ifndef WEBPAGE_H_
#define WEBPAGE_H_


const String webPage = "<!doctype html>\n"
"<html>"
"<head>"
"<style>"
".onoffswitch {"
	"position: relative; width: 112px;"
	"-webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;"
"}"
".onoffswitch-checkbox {"
	"display: none;"
"}"
".onoffswitch-label {"
	"display: block; overflow: hidden; cursor: pointer;"
	"height: 36px; padding: 0; line-height: 36px;"
	"border: 2px solid #CCCCCC; border-radius: 36px;"
	"background-color: #FFFFFF;"
	"transition: background-color 0.3s ease-in;"
"}"
".onoffswitch-label:before {"
	"content: \"\";"
	"display: block; width: 36px; margin: 0px;"
	"background: #FFFFFF;"
	"position: absolute; top: 0; bottom: 0;"
	"right: 74px;"
	"border: 2px solid #CCCCCC; border-radius: 36px;"
	"transition: all 0.3s ease-in 0s; "
"}"
".onoffswitch-checkbox:checked + .onoffswitch-label {"
	"background-color: #49E845;"
"}"
".onoffswitch-checkbox:checked + .onoffswitch-label, .onoffswitch-checkbox:checked + .onoffswitch-label:before {"
	"border-color: #49E845;"
"}"
".onoffswitch-checkbox:checked + .onoffswitch-label:before {"
	"right: 0px; "
"}"
"</style>"
"<title>A blank HTML5 page</title>"
"<meta charset=\"utf-8\" />"
"</head>"
"<body>"
"<!-- generate the switches -->"
"<script>"
"var numSwitches = 3;"
"for (i = 1; i <= numSwitches; i++) {"
	"var label = document.createElement('LABEL');"
	"document.body.appendChild(label);"
	"label.innerHTML = \"<b>Switch \" + i.toString() + \"</b>\";"
	"var div = document.createElement('div');"
	"div.className=\"onoffswitch\";"
	"div.innerHTML = '<input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"myonoffswitch' + i.toString() + '\" onclick=\"clickEvent(' + i.toString() + ')\">';"
	"div.innerHTML += '<label class=\"onoffswitch-label\" for=\"myonoffswitch' + i.toString() + '\"></label>';"
	"document.body.appendChild(div);"
"}"
"function clickEvent(switchNumber) {"
	"var switchState = document.getElementById(\"myonoffswitch\" + switchNumber.toString()).checked;"
	"httpGet(\"/led\" + switchNumber.toString())"
	//"alert(\"Switch \" + switchNumber.toString() + \" changed states to: \" + switchState.toString());"
"}"
"function httpGet(theUrl) {"
	"var xmlHttp = new XMLHttpRequest();"
	"xmlHttp.open( \"GET\", theUrl, true );"
	"xmlHttp.send( null );"
	"return xmlHttp.responseText;"
"}"
"</script>"
"</body>"
"</html>";


#endif /* WEBPAGE_H_ */