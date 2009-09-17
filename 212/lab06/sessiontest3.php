<?php
session_start();
if(!isset($_SESSION['PAGE THREE'])){
  $_SESSION['PAGE THREE'] = 1;
 }else{
  $_SESSION['PAGE THREE']++;
 }
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
"http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Page for testing PHP sessions: PAGE THREE</title>
</head>
<body>
    <h1>Page for testing PHP sessions: PAGE THREE</h1>
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
<p>You can go to <a href="sessiontest2.php">PAGE TWO</a></p>
    <p>You are on PAGE THREE</p>

</body>
</html>