<?php
session_name("MYSESSION");
session_set_cookie_params(0, '/lchisholm/lab09/');
session_start();
$_SESSION = array();
session_destroy();
setcookie('MYSESSION',"",time()-3600,'/lchisholm/lab09/');
header("Location: login.php");
exit;