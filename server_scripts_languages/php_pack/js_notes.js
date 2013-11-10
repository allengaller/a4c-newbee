1、今天碰到一个问题，就是js获取前一节点，用obj.previousSibling 确实可以获取前一节点，但是如果前面不是节点，就要判断obj.previousSibling.nodeType，这个nodeType有很多种，如下：

下面是nodeType对应的值和代表的东东：

1- ELEMENT 

2- ATTRIBUTE 

3- TEXT 

4- CDATA 

5- ENTITY REFERENCE 

6- ENTITY 

7- PI (processing instruction) 

8- COMMENT 

9- DOCUMENT 

10- DOCUMENT TYPE 

11- DOCUMENT FRAGMENT 

12- NOTATION 

这里面我们经常会碰到的就类型如下： 

节点类型 元素类型 

1 -元素element（比如我们经常见到的div,p等等）
2 -属性attribute（如id,class等）
3 -文本text
8 -注释comments
9 -文档document

通过对nodeType的判断，我们能轻易的过滤节点。如： 
1
2
3
	
if ( elem.nodeType === 3 || elem.nodeType === 8 ) {  
   return;  
}

2、如果前面不是node，则可以取obj.previousSibling.previousSibling获得节点。如果是jQuery的话，就这样：$(obj).prev().attr('value')，不过这里还没尝试，不知道会不会直接取他前面的东西。

 

3、注意obj.previousSibling获得是object text，如果要取得他的属性，则直接这样：var o = obj.previousSibling.previousSibling;      //alert(o.value);

 

4、获得当前的url并作出相应的处理，则这样：
1
2
3
4
5
6
7
8
9
	
var url = location.href;    
if (!(/page[\d]*/g.test(url)))  
{  
    //alert(url + "/page" + o.value;  做一些处理  
}else{  
    url = url.replace(/page[\d]*\//g,'');  
    alert(url);  
    //alert('22');  
}

5、原生的js里面没有获取class的，如果要做的话，就要做轮询，如下：
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
	
<script type="text/javascript">  
document.getElementsByClassName = function(){  
    var tTagName ="*";  
    if(arguments.length > 1){  
    tTagName = arguments[1];  
    }  
    if(arguments.length > 2){  
    var pObj = arguments[2]  
    }  
    else{  
    var pObj = document;  
    }  
    var objArr = pObj.getElementsByTagName(tTagName);  
    var tRObj = new Array();  
    for(var i=0; i<objArr.length; i++){  
    if(objArr[i].className == arguments[0]){  
    tRObj.push(objArr[i]);  
    }  
    }  
    return tRObj;  
}  
       
       
function test(){  
var obj=document.getElementsByClassName("qq");  
    for (var i=0;i<obj.length;i++){  
        obj[i].style.color="#cccccc";  
    }  
}  
       
</script>  
</head>  
<body>  
<div class="qq" onclick="test(this)">12331232</div>  
<div class="qq" onclick="test(this)">2</div>  
<div class="qq" onclick="test(this)">3</div>  
<div class="qq" onclick="test(this)">4</div>  
</body>

以上只是做一下笔记，以后就记得了。。 希望看到文章的你有所进步~~


还有一点，smarty 里面将时间戳转化成年-月-日 时：分：秒是 {$time|date_format:'%Y-%m-%d %H:%M:%S'}