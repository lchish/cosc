<?php
require 'private/session.php';
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
<div id="categoriesdiv">
<p id="categories"><strong>Categories:</strong></p>
<ul id="categorieslist">
<li class="categoriesli"><a href="antiques.php">Antiques &amp; collectables</a>
</li>
<li class="categoriesli"><a href="lecturers.php">Lecturers</a></li>
<li class="categoriesli"><a href="servers.php">Broken servers</a></li>
<li class="categoriesli"><a href="assignments.php">Extended assignments</a>
</li>
<li class="categoriesli"><a href="building.php">Building &amp; renovation</a>
</li>
<li class="categoriesli"><a href="farming.php">Business, farming &amp; industry
</a></li>
</ul>
</div><!--end categories div-->
<?php
include 'auctions.php';
?>
</div><!--end content div-->
</div><!-- end body div-->
</body>
</html>
