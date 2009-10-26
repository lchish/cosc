<?php
$connection = mysql_connect('sapphire','lchisholm','Tduvxanm42wq');
mysql_select_db('lchisholm_dev',$connection);
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Mysql test</title>
</head>
<body>
<dl>
<?php
$previous_subject = "";
$query = "select subjname,firstname,lastname from staff,subjects,taught where staff.staffid = taught.staffid and taught.subjcode = subjects.subjcode order by subjname,lastname";
$result = mysql_query($query, $connection);
while($row = mysql_fetch_array($result, MYSQL_ASSOC)){
  if($previous_subject != $row['subjname']){
    $previous_subject = $row['subjname'];
    echo "<dt>{$row['subjname']}:</dt>";
  }
  echo "<dd>{$row['firstname']} {$row['lastname']}</dd>";
 }
?>
</dl>
</body>
</html>