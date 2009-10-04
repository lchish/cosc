<?php
require 'private/session.php';
require 'private/config.php';

$connection = mysql_connect($config['host'],$config['username'],$config['password']);
mysql_select_db($config['database'],$connection);

if(isset($_GET['id'])){
  $clean_auction_number  = mysql_real_escape_string($_GET['id']);
 }else{
  header("Location: index.php");
 }

$query = "SELECT seller_username FROM auctions WHERE auction_number = '$clean_auction_number'";
$result = mysql_query($query,$connection);
if(mysql_num_rows($result) > 0){
  $result_array = mysql_fetch_array($result);
  $auction_creater = $result_array['seller_username'];
 }else{
  header("Location: index.php");
  exit();
 }

if($_SESSION['username'] != $auction_creater){
  header("Location: index.php");
  exit();
 }

$_SESSION['auction_number'] = $clean_auction_number;
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <title>Sell it - The best online auctions. Browse, buy and sell on Sell It
</title>
<link href="style.css" rel="stylesheet" type="text/css">
<link rel="icon" type="image/png" href="favicon.png">
</head>
<body>
<div id="bodydiv">
<?php
include 'private/topnav.php';
include 'private/sidenav.php';
?>
<div id="content">
<?php
if(isset($_GET['success'])){
  $success = $_GET['success'];
  echo "<p>$success</p>";
}else if(isset($_GET['error'])){
  $error = $_GET['success'];
  echo "<p>$error</p>";
}
?>
  <p>Upload an image to go with your auction:</p>
<!-- note more than one image can be uploaded per auction -->
<form method="post" enctype="multipart/form-data" action="doupload.php">
<input type="file" name="incoming">
<br>
<input type="submit" value="upload">
</form>
</div>
</div>
</body>
</html>