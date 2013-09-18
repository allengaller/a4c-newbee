<?php
$memcache = new Memcache;
$memcache->connect('127.0.0.1',11211) or die("Connect Failed!");
$id = $_REQUEST['name'];
$key = md5("SELECT * FROM memcache WHERE FirstName='{$id}'");
