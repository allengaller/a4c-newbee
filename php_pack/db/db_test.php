<?php
$db_user = "root";
$db_pass = "";

// return BOOLE value
$connect = mysql_connect("localhost", $db_user, $db_pass);

if($connect) {
	echo "Success!";
} else {
	echo "Fail!";
}
?>