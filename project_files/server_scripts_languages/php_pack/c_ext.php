<?
用c为php写扩展函数

 前几天在虚拟机上面搭配了php运行环境，这两天就在捉摸着用C为PHP写扩展。

感觉自己有点傻，不过笨鸟先飞，加油加油！


首先选择php的源码包ext目录

一、cd ~/php.5.4.9/ext/

./ext_skel --extname=firstapp    //firstapp就是我需要创建的一个模块名   这时在ext文件下生成一个firstapp文件夹

cd firstapp

（1）修改config.m4文件

vi config.m4

查找一下字符串，并去掉行前面的 dnl ，如下这样，保存退出

PHP_ARG_ENABLE(firstapp, whether to enable firstapp support,

Make sure that the comment is aligned:

[  --enable-firstapp           Enable firstapp support])

 

（2）修改php-firstapp.h

vi php-firstapp.h

查找如下字符串，并在其下添加如下方法（蓝色为添加项）

PHP_FUNCTION(confirm_firstapp_compiled);        /* For testing, remove later. */

PHP_FUNCTION(firstapp);

 

（3）修改firstapp.c文件

vi firstapp.c

查找如下字符串，并添加如下方法：（蓝色为添加项）

zend_function_entry firstapp_functions[] = {

        PHP_FE(confirm_firstapp_compiled, NULL) /* For testing, remove later. */

        PHP_FE(firstapp,NULL)

        {NULL, NULL, NULL} /* Must be the last line in firstapp_functions[] */

};

在firstapp.c文件的最后添加如下方法：

PHP_FUNCTION(firstapp){

        printf("hello world!");

}


二、此时扩展文件新建完成，下面就对其进行编译

这里注意是进入到你的扩展目录哦~~~

 

[root@localhost firstapp]# /usr/local/php/bin/phpize        //如果你不知道在哪里，可以find / -name phpize然后执行

[root@localhost firstapp]# ./configure --with-php-config=/usr/bin/php-config   //这个是必须的，不然会报错！如果你不知道在哪里也可以搜索一下

[root@localhost firstapp]# make

[root@localhost firstapp]# make install

此时firstapp.so文件已经在/usr/local/php/lib/php/extensions/no-debug-non-zts-20060613/      //这个不一定，如果不知道，照样可以搜索


注意了，童鞋们，你现在只是生成了.so文件，你必须放到PHP的扩展的目录里面去，不然PHP怎么去加载呢！！如果不知道php的extension_dir是啥，可以查看你的php.ini文件，然后搜索extension_dir，最后把你的so文件放到这个目录下面。


[root@localhost firstapp]# cp /usr/local/php/lib/php/extensions/no-debug-non-zts-20060613/firstapp.so /usr/lib/php/modules/

 

三、此时动态库已经生成了，最后进行php.ini 文件的配置

vi /usr/local/php/lib/php.ini

添加 动态库路径和模块名

extension_dir="/usr/lib/php/modules"

extension=firstapp.so

 

四、输入: php -m查看是否已经加入了firstapp扩展，如果没有，那很可能是php读取的配置文件不是你刚刚修改过的那个，你可以这样：新建php文件，输出phpinfo();  如:php 1.php > study      然后 vim study  ，搜索php.ini。如果不是你修改的那个，你就把配置文件移到php读取的那个目录，一切就ok了！


五.测试firstapp.so模块

[root@localhost firstapp]# php -m

[PHP Modules]

ctype

date

dom

filter

firstapp

hash

iconv

.........

新建firstapp.php文件

<?

    firstapp();

?>

 

[root@localhost firstapp]# php firstapp.php

  hello world!

[root@localhost firstapp]# 

 

在此表示firstapp.so模块添加成功并正常运行
现主要从事PHP、Uinx/Linux等方面的项目开发。


