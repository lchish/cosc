<?php

require 'private/session.php';
require 'private/config.php';

$connection = mysql_connect($config['host'],$config['username'],$config['password']);

mysql_select_db($config['database'],$connection);
$clean_username = mysql_real_escape_string($_SESSION['username']);
$query = "SELECT title,auction_number FROM auctions WHERE seller_username = '$clean_username'";
$result = mysql_query($query,$connection);
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Sell it - The best online auctions. Browse, buy and sell on Sell It
</title>
<link href="style.css" rel="stylesheet" type="text/css">
<link href="myauctions.css" rel="stylesheet" type="text/css">
<link rel="icon" type="image/png" href="favicon.png">
</head>
<body>
<div id="bodydiv">
<?php
include 'private/topnav.php';
include 'private/sidenav.php';
?>
<div id="content">
<h1>Your auctions</h1>
<?php
 while($row = mysql_fetch_array($result)){
  $title = $row['title'];
  $num = $row['auction_number'];
  echo "<h2>$title</h2>";
  echo "<p class=\"auctionp\"><a href=\"uploadimage.php?id=$num\">Upload image <a></p>";
  echo "<p class = \"auctionp\"><a href=\"deleteauction.php\"id=$num\">Delete auction</a></p>";
  }
?>
</div>
</div>
</body>
</html>
