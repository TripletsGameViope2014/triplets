function callWebSocket(a) {
	var socket = new WebSocket("ws://127.0.0.1:1234/"+a);
}


$("a").click(function() {
	callWebSocket($("td").attr("id"));
});

$(document).on('click', 'td', function(){
	callWebSocket($(this).attr("id"));
});