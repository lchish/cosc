<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
	  "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
   <title>Pictures</title>
</head>
<body>
<div>
<?php
$images = glob("otagoimages/*.jpg");
// $lines = file("imagedescriptions/*.txt");
if(!empty($images)){
  foreach($images as $key => $value){
    $subvalue = substr($value,12,-4);
    echo "<a href=$value>Link to $subvalue picture</a>";
    echo "<br>";
  }
}
?>
</div>
</body>
</html>