<?php
session_name("MYSESSION");
session_set_cookie_params(0, '/lchisholm/lab09/');
session_start();

$connection = mysql_connect('sapphire','lchisholm','Tduvxanm42wq');
mysql_select_db('lchisholm_dev',$connection);
if(isset($_POST['username'])){
  $clean_username = mysql_real_escape_string($_POST['username']);
 }
if(isset($_POST['password'])){
  $clean_password = mysql_real_escape_string($_POST['password']);
 }
$query = "select username,passhash from users where username = '$clean_username' and 
  passhash = sha('$clean_password')";
$result = mysql_query($query, $connection);
$row = mysql_fetch_array($result);

if(mysql_num_rows($result) == 1){
  $_SESSION['authorisation'] = 'knownuser';
  echo 'authed';
  header("Location: entryhall.php");
  exit;
}else{
  $_SESSION['authorisation'] = 'unknownuser';
  header("Location: login.php");
  exit;
  }
?>

