function setup()
{
var myButton = document.getElementById("press");
myButton.onClick = saySomething;
}

function saySomething()
{
alert("Hello World");
}

if (document.getElementById)
{
window.onload = setup;
}