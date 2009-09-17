<?php
if(isset($_GET['bgcolour']))
{
   setcookie("bgcolour",$_GET['bgcolour'], time()+3600);
}else if(!isset($_COOKIE['bgcolour'])){
   setcookie("bgcolour","white",time()+3600);
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Cookie test</title>
<style type="text/css">
<!--
<?php
if(isset($_GET['bgcolour']))
{
   echo 'body{background-color:';
   echo $_GET['bgcolour'];
   echo ';}';
}else if(isset($_COOKIE['bgcolour']))
{
   echo 'body{background-color:';
   echo $_COOKIE['bgcolour'];
   echo ';}';
}
?>
p{
    font-weight:bold;
}

div{
    border-style: solid;
    border-width: 1px;
    margin-left: -1px;
    float:left;
}
.box{
    width: 70px;
    height: 70px;
    display: block;
}
h1{
    clear:left;
}
#box1{
    background-color: #ffffdd;
}

#box2{
    background-color: #ddffdd;
}
#box3{
    background-color: #ddddff;
}
#box4{
    background-color: #dfdfdf;
}
-->
</style>
</head>
<body>

<p>Choose a background colour:</p>
<div><a id="box1" class="box" href="cookies.php?bgcolour=yellow"></a></div>
<div><a id="box2" class="box" href="cookies.php?bgcolour=green"></a></div>
<div><a id="box3" class="box" href="cookies.php?bgcolour=blue"></a></div>
<div><a id="box4" class="box" href="cookies.php?bgcolour=grey"></a></div>
<h1>Some Content Here</h1>
<p>Lorem ipsum dolor etc.</p>
</body>
</html>
