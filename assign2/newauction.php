<?php
require 'private/session.php';
if(!isset($_SESSION['auth']) || $_SESSION['auth'] == 'unknownuser'){
  header("Location: index.php");
  exit();
 }
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Sell it - The best online auctions. Browse, buy and sell on Sell It
</title>
<link href="style.css" rel="stylesheet" type="text/css">
<link href="forms.css" rel="stylesheet" type="text/css">
<link rel="icon" type="image/png" href="favicon.png">
</head>
<body>
<div id="bodydiv">
<?php
include 'private/topnav.php';
include 'private/sidenav.php';
?>
<div id="content">
<h1>Create a new auction</h1>
<p id="mandatory">Mandatory fields are marked with a (
	       <span class="mandatoryStar">*</span>)</p>
<?php
if(isset($_GET['error'])){
  $error = $_GET['error'];
  echo "<p><strong>Error: $error</strong></p>";
}
?>
      <form enctype="multipart/form-data" "action="createauction.php" method="post"
 id="createaccountform">
        <div class="textinput">

  <label for="title" class="textlabel">Auction title:
          <span class="mandatoryStar">*</span></label>
          <input id="title" name="title" class="textfield"
                 maxlength="32" size="20">

<p id="contentbox">City/Province: <span class="mandatoryStar">*</span></p>

<select name="area" class="dropdown">
<option value="Northland">Northland</option>
<option value="Auckland">Auckland</option>
<option value="Hamilton">Hamilton</option>
<option value="Wellington">Wellington</option>
<option value="Christchurch">Christchurch</option>
<option value="Dunedin">Dunedin</option>
<option value="Gore">Gore</option>
<option value="Invercargill">Invercargill</option>
</select>
 
<p id="contentbox">Category: <span class="mandatoryStar">*</span></p>

<select name="category" class="dropdown">
<option value="antiques">Antiques &amp; collectables</option>
<option value="building">Building and renovation</option>
<option value="servers">Broken Servers</option>
<option value="assignments">Entended assignments</option>
<option value="electrical">Electrical</option>
<option value="farming">Farming</option>
<option value="furniture">Furniture</option>
<option value="instruments">Instruments</option>
<option value="lecturers">Lecturers</option>
</select>

 <p id="contentbox">Content:</p><textarea name="content" rows="5" cols="20" class="textarea">
Enter important information about your auction here.</textarea>

  <label for="reserve" class="textlabel">Reserve price:
          <span class="mandatoryStar">*</span></label>
          <input id="reserve" name="reserve"
                 class="textfield" maxlength="32" size="20">
  </div><!--//textinput div-->
        <div>
          <button type="submit" class="create">Create</button>
        </div>
      </form>
</div>
</div>
</body>
</html>
