<?php
session_start();
if(!isset($_SESSION['PAGE TWO'])){
  $_SESSION['PAGE TWO'] = 1;
 }else{
  $_SESSION['PAGE TWO']++;
 }
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
"http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Page for testing PHP sessions: PAGE TWO</title>
</head>
<body>
    <h1>Page for testing PHP sessions: PAGE TWO</h1>
    <p>You have visited:</p>
   <?php
    foreach ($_SESSION as $key => $value){
  echo '<p>';
  echo $key;
  echo ' ';
  echo $value;
  if($value > 1){
  echo ' times';
  }else{
    echo ' time';
  }
echo '</p>';
}
?>
    <hr>
    <p>You can go to <a href="sessiontest1.php">PAGE ONE</a></p>
    <p>You are on PAGE TWO</p>
<p>You can go to <a href="sessiontest3.php">PAGE THREE</a></p>
</body>
</html>