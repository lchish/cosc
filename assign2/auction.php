<?php
require 'private/session.php';
require 'private/config.php';
require 'private/timeremaining.php';

$connection = mysql_connect($config['host'],$config['username'],$config['password']);
mysql_select_db($config['database'],$connection);

if(isset($_GET['id'])){
  $auction_number = mysql_real_escape_string($_GET['id']);
 }else{
  header("Location: index.php");
  exit();
 }
$query = "SELECT * FROM auctions WHERE auction_number = '$auction_number'";
$queryimages = "SELECT * FROM auction_images WHERE auction_number = '$auction_number'";
$querybidders = "SELECT * FROM auction_bidders WHERE auction_number = '$auction_number'";

$result = mysql_query($query,$connection);
$resultimages = mysql_query($queryimages,$connection);
$resultbidders = mysql_query($querybidders,$connection);

$row = mysql_fetch_array($result);
$x = 0;
while($rowimages = mysql_fetch_array($resultimages)){
  $images[$x] = $rowimages['auction_number']."_".$rowimages['image_number'].".jpg";
  $x++;
 }
$x = 0;
$title = $row['title'];
$area = $row['area'];
$category = $row['category'];
$content = $row['content'];
$reserve = $row['reserve'];
$reserve_met = $row['reserve_met'];
$highest_bid = $row['highest_bid'];
$highest_bidder = $row['highest_bidder'];
$seller_username = $row['seller_username'];
$date = mysql_query("SELECT TIMEDIFF(closing_time,NOW()) FROM auctions
WHERE auction_number = '$auction_number'");
$date_array = mysql_fetch_array($date);
$closing_time = substr(timeToText($date_array[0]),0,7);
$imagelocation = $config['images'];
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Sell it - The best online auctions. Browse, buy and sell on Sell It
</title>
<link href="style.css" rel="stylesheet" type="text/css">
<link href="auction.css" rel="stylesheet" type="text/css">
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
echo "<h1 id=\"auctiontitle\">$title</h1>";
//info bar containing current bid,and closing time
  echo "<div id=\"infobar\">";
if($reserve_met == 0){
  echo "<span>Start Price: \$$reserve</span>";
  echo "<span id=\"flag\"><img src=\"images/yellowflag.png\" alt=\"no reserve flag\"></span>";
  echo "<span id=\"reserve\">No reserve</span>";
 }else{
  echo "<span>Highest Bid:\$$highest_bid</span>";
  echo "<span><img src=\"images/redflag.png\" alt=\"reserve met flag\"></span>";
    echo "<span id=\"reserve\">Reserve Met</span>";
}
echo "<span>Closes: $closing_time</span>";
echo "</div>";//end infobar
echo "<form action=\"bid.php\" method=\"post\">";
echo "<div id=\"bidbar\">";
if($reserve_met == 0){
  echo "<span>Starting bid: $</span>";
}else{
  echo "<span>Min next bid: $</span>";
}
?>

<input id="bidinput" type="text" name="bid" value="<?php echo $reserve > $highest_bid ? $reserve : $highest_bid + 1;?>" size="4">
<input type="hidden" name="auction_number" value="<?php echo $auction_number;?>">
<input type="submit" id="bidbutton" value="click here to bid">
</div><!-- //bidbar -->
</form>

<?php
echo "<div class=\"auctioncontent\">";
for($x = 0; isset($images) && $x < count($images);$x++){
echo "<div class=\"auctionimages\">";
echo "<img src=\"$imagelocation$images[$x]\" alt=\"auction image\"></div>";
 }
echo "$content</div>";
?>
<div id="bidhistory">
<h2>Bid history</h2>
<?php
  $bidders_result = mysql_query("SELECT * FROM auction_bidders where auction_number = '$auction_number' ORDER BY bid DESC",$connection);
while($row = mysql_fetch_array($bidders_result)){
  echo "<div class=\"historyrow\">";
    echo "\$".$row['bid']."  ";
  echo $row['bidder'];
  echo "</div>";
  }
?>
</div>
</div>
</div>
</body>
</html>
