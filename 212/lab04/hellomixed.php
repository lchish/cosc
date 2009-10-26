<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
"http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
   <title>Hello</title>
</head>
  <body>
<?php

if(!isset($_POST['user'])){
  ?>
 <h1 style=" font-size: small; margin-left:360px;">Test out php processing</h1>
<FORM action="http://dev212.otago.ac.nz:8080<?php echo $_SERVER['PHP_SELF']?>" method="post">
<div style="width: 700px; margin-left: auto;margin-right: auto;border:2px solid;">
<p>Enter your name:<INPUT type="text" name="user"> <INPUT type="submit" value="Go!"></p>
  </div>
</FORM>
<?php
}else{
  echo '<p>Hello there, ';
  $user = htmlentities($_POST['user']);
  echo $user;
  echo "</p>";
 }
?>
</body>
</html>