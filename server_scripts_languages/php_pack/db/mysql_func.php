<?php
##MySQL函数##

##连接##
resource mysql_connect(...);

$hostname = "localhost";
$username = "root";
$password = "";

$link = mysql_connect($hostname, $username, $password);
if($link) {
	echo "Done!";
} else {
	echo "Failed!";
}

if(mysql_close($link)) {
	echo "Closed!";
} else {
	echo "Closed fail!";
}

//打开持久连接
//1. 连接时, 该函数将先尝试寻找一个在同一个主机上用相同的用户名和密码已经打开的持久连接.
//如果找到, 则返回此链接标识符而不打开新连接.
//2.当脚本执行完毕后到SQL服务器的连接不会被关闭, 此连接讲保持打开,以备以后使用.

$link = mysql_pconnect($hostname, $username, $password);
if(!$link) {
	die('Error!'.mysql_error());
	exit();
} else {
	echo "Pconnect Done!";
}

##操作##
//移动内部结果的指针
$link = mysql_connect($hostname, $username, $password) or die("Connect failed!".mysql_error());
mysql_query('SET NAMES gb2312;');
mysql_select_db("test") or die("Select failed!".mysql_error());
$query = "SELECT name FROM friends";
$result = mysql_query($query) or die("Query failed!".mysql_error());
for($i=mysql_num_rows($result)-1; $i>0; $i--) {
	if(!mysql_data_seek($result, $i)) {
		echo "Cannot seek to row $i:".mysql_error()."\n";
	}
	if(!($row=mysql_fetch_object($result))
		continue;
	echo "$row->name<>br/\n";
}
mysql_free_result($result);

//列出MySQL服务器中所有的数据库
$link = mysql_connect('localhost','root');
$mydb = mysql_list_db($link);
while($result=mysql_fetch_object($mydb)) {
	echo $result->Database."\n";
}

//列出MysQL结果中的字段
$conn = mysql_connect('localhost','root');
$fields = mysql_list_fields("test","friends",$conn); //列出test库friends表的信息
$cols = mysql_num_fields($fields); //获取结果数
for($i=0;$i<$cols;$i++) {
	echo mysql_field_name($fields, $i)."\n";
}

//列出Mysql进程
$conn = mysql_connect('localhost','root');
$pro_list = mysql_list_processes($conn);
while($result=mysql_fetch_array($pro_list)) {
	echo $result["id"].";";
	echo $result["host"].";";
	echo $result["db"].";";
	echo $result["commond"].";";
}
mysql_close($con);

//列出MySQL中的表
$conn = mysql_connect('localhost','root');
$mysql = mysql_list_tables("test",$conn); //列出test库中的所有表
while($rows=mysql_fetch_array($mysql, $conn)) {
	echo "Table:$rows[0]";
}
mysql_free_result($mysql); //释放结果
mysql_close($conn); //关闭连接

//Ping连接
$ping = Mysql_ping($conn);
if($ping){
	echo "Server works!";
} else {
	echo "Server down!";
}

//发送一条MySQL查询
//仅对SELECT, SHOW, EXPLAIN, DESCRIBE语句返回一个资源标识符,执行不正确返回False.
$hostname="localhost";
$username="root";
$password="";
$link = mysql_connect($hostname, $username, $password);
mysql_query('SET NAMES gb2312');
mysql_select_db("test");
$query="SELECT * FROM friends";
$result=mysql_query($query);
while($rows=mysql_fetch_array($result)){
	echo "id为: ".$rows[id];
	echo "name为: ".$rows[name];
}
mysql_free_result($result);//释放结果集

//转义SQL语句中的特殊字符
$link=mysql_connect($hostname,$username,$password);
$sql_str="Zak's and Derick's Laptop.";
$escaped_str=mysql_real_escape_string($sql_str);
printf("Escaped string: %s\n", $escaped_str);

//获取结果数据
$result = mysql_query($query);
echo mysql_result($result, 0, "name");

//选择MySQL数据库 bool
$conn = mysql_connect('localhost','root');
$sql_str = mysql_select_db("dbname", $conn);
if(!$sql_str) {
	die('Select db failed!'.mysql_error());
} else {
	echo "Select db done!";
}

//向MySQL发送一条SQL查询, 并不获取和缓存结果的行
$link=mysql_connect($hostname,$username,$password);
mysql_select_db("test");
$query = "SELECT * FROM friends WHERE id=1";
$result = mysql_unbuffered_query($query);
echo mysql_result($result, 0, "name");

##信息获取##
//获取前一次MySQL操作所影响的记录行数
$link=mysql_connect($hostname,$username,$password);
mysql_select_db('test',$link);
mysql_query('DELETE FROM friends WHERE id=2');
printf("Deleted %d rows", mysql_affected_rows());
mysql_close($link);

//获取字符集的名称
$link=mysql_connect($hostname,$username,$password);
$charset=mysql_client_encoding($link);

//获取数据库名
$link=mysql_connect($hostname,$username,$password);
$db_list=mysql_list_db($link);
$rows=mysql_num_rows($db_list);
$i=0;
while($i<$rows) {
	echo mysql_db_name($db_list, $i)."\n"
	$i++;
}
mysql_close($link);

//返回上一个MySQL操作中的错误信息的数字编码
mysql_connect($hostname,$username,$password);
mysql_select_db("nonexistentdb");
echo mysql_errno().":".mysql_error()."\n";

//...文本错误信息
string mysql_error();

//从结果集中获取一行作为关联数组或数字数组,或两者都有
array mysql_fetch_array(...);
//...关联数组
array mysql_fetch_assoc(...);
//...获取列信息并作为对象返回
object mysql_fetch_field(...);
$link=mysql_connect($hostname,$username,$password);
mysql_select_db("test");
$result=mysql_qeury("SELECT * FROM friends");
//获取字段信息
$i=0;
while($i<mysql_num_fields($result)) { //循环读取结果树
	$i++;
	echo "第".$i."列的信息:";
	$meta = mysql_fetch_field($result);
	if(!$meta) {
		echo "No info available!\n";
	}
	echo "max_length:".$meta->max_length;
	echo "name".$meta->name;
}
//获取结果集中每个输出的长度
$link=mysql_connect($hostname,$username,$password);
mysql_select_db("test", $link);
$sql_str="SELECT * FROM friends WHERE id=1";
$result=mysql_query($sql_str);
$re_a=mysql_fetch_array($reuslt);
$re_len=mysql_fetch_lengths($result);
for($i=0; $i<count($re_len);$i++) {
	echo "返回的结果的第".$i."列的长度为".$re_len[$i];
}
mysql_close($link);

//从结果集中获取一行作为对象
while ($row=mysql_fetch_object($result)) {
	echo $row->id;
	echo $row->name;
}
//...枚举数组
$row = mysql_fetch_row($result);
//...字段关联的标志

