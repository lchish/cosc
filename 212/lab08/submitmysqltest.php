<?php
$connection = mysql_connect('sapphire','lchisholm','Tduvxanm42wq');
mysql_select_db('lchisholm_dev',$connection);
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
   "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Submit Mysql test 2</title>
</head>
<body>
<?php
echo '<dl>';
$last_name = "";
$first_name = "";
$match_lastname = '%';
$match_firstname = '%';
if(isset($_GET['lastname'])){
  $clean_lastname = mysql_real_escape_string($_GET['lastname']);
  $match_lastname = '%' . $clean_lastname . '%';
 }

if(isset($_GET['firstname'])){
  $clean_firstname = mysql_real_escape_string($_GET['firstname']);
  $match_firstname = '%' . $clean_firstname . '%';
 }

$query = "select lastname,firstname,subjname from students,gotowls,subjects
         where firstname like '$match_firstname'
         and lastname like '$match_lastname' and
         students.studid = gotowls.studid and subjects.subjcode = gotowls.subjcode
         order by lastname,firstname,subjname";
echo '<h1> got owls in:</h1>';
$result = mysql_query($query, $connection);
while($row = mysql_fetch_array($result, MYSQL_ASSOC)){
  if($last_name != $row['lastname'] || $first_name != $row['firstname']){
    $last_name = $row['lastname'];
    $first_name = $row['firstname'];
    echo "<dt>{$row['firstname']} {$row['lastname']}:</dt>";
  }
  echo "<dd>{$row['subjname']}</dd>";
 }
echo '</dl>';
?>
</body>
</html>