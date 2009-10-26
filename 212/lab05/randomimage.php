<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
	  "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
   <title>Random Pictures</title>
</head>
<body>
<div>
<?php
$images = glob("otagoimages/*.jpg");
// $lines = file("imagedescriptions/*.txt");
if(!empty($images)){
  $randomimage = $images[array_rand($images)];
  $text = substr($randomimage,12,-4);
  $myfile = file("imagedescriptions/$text.txt");
  //echo $myfile[0];
  echo '<img src="';
  echo $randomimage;
  echo '" alt ="';
  if(!empty($myfile)){
    echo $myfile[0];
  }else{
    echo "A Photograph taken at Otago";
  }
  echo '">';
 }
?>
</div>
</body>
</html>