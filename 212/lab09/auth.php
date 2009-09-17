<?php
session_name("MYSESSION");
session_set_cookie_params(0, '/lchisholm/lab09/');
session_start();
if($_SESSION['authorisation'] != 'knownuser'){
  header("Location: login.php");
  exit;
}
?>