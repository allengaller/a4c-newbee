<?php
bool apache_child_terminate();
array apache_get_modules();
string apache_get_version();
string apache_getenv("SERVER_ADDR");//获取服务器IP

//获取特定URL有关信息
$url_info = apache_lookup_uri('xx.php'); //对URL执行请求并返回信息
print_r($url_info);
if(file_exists($url_info->filename)) {
	echo "File exists!";
}

//获取或设置Apache请求记录
apache_note('name','123');
echo apache_note('name');

//获取HTTP请求的标头
$headers = apache_request_headers();
foreach($headers as $header=>$value) {
	echo "$header:$value<br/>\n";
}

//获取所有HTTP回应标头
$headers = apache_response_headers();
foreach($headers as $header=>$value) {
	echo "$header:$value<br/>\n";
}

//获取所有HTTP变数值
array getallheaders();

##Apache配置类函数##
//设置Apache环境变量
if(apache_setenv("EXAMPLE_VAR", "TESTVALUE")); {
	echo "Done!";
} else {
	echo "Failed!";
}

//执行Apache的子请求
virtual("config.php") //mod_php下,需要有效HTTP文档头

