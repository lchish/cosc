<?php
if(!isset($_POST['user'])){
  header("Location: form.html");
  exit;
 }?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
	  "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
   <title>Hello</title>
</head>
<body>
<p>Hello there,
<?php
$user = htmlentities($_POST['user']);
echo $user;
?>
</p>
</body>
</html>