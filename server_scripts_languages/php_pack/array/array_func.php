<?php
##新建##
$array=array(1,2,3,4=>2,5=>3);
print_r($array);

//用两个数组的值作为新数组的键与值来新建
$a=array('green','red','yellow');
$b=array('avocado','apple','banana');
$c=array_combine($a,$b);

//建立一个包含指定范围单元的数组
range();

##操作##
//将一个数组分割成多个数组
$input_array=array('a','b','c','d','e');
print_r(array_chunk($input_array, 2));
print_r(array_chunk($input_array, 2, True));

//统计数组中所有的值出现的次数
$array=array(1,'hello',1,'php');
print_r(array_count_values($array));

//带索引检查计算数组的差集
$result=array_diff_assoc($a1, $a2);//包含所有在a1中但是不在其他数组中的值.

//使用键名比较计算数组的差集
$result=var_dump(array_diff_key($a1,$a2));//包含所有在a1但是不在其他数组中的键名的值.

//用回调函数做索引检查来计算数组的差集
