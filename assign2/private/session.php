<?php
/*sets up the session for any page needing to use it*/
$cookiename = '/~leslie/assign2';
session_name("sellit");
session_set_cookie_params(0, $cookiename);
session_start();
?>