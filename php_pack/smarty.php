<?
/*
smarty 中引入widget

官网上面有一个实现了 可以参考之（http://www.smarty.net/forums/viewtopic.php?p=74711）
widget 是一个比较完整的功能单元,它封装了贯穿视图层到逻辑层，数据访问层的逻辑，可以在别的视图中反复使用；
常见的用途比如：页脚下的网站链接（可以从数据库中增删），最近上传的图片，最热门的评论。这样的逻辑可以被
其他视图包含，你可以在多处以黑盒的方式使用它；

使用方式：
  {widget class='TopComments' maxDisplay='15'}

实现思路：
首先定义一个smarty插件函数，  在插件函数中实例化指定的类， 并调用“虚”方法run

*/

function smarty_function_widget($params, $template) {
	if(empty($params['class'])) {
		throw new Exception('Please input Widget classname!');
	}
	//这个要求预定义widgets存放的路径 如果不存在用eval动态生成子类 此处不用它
	if(file_exists($widgetClassfile = sprintf('%s.php'), CONF_DIR_WIDGETS.strtolower($params['class']))) {
		require_once($controller);
	} else {
		eval(sprintf('class %s extends SmartyWidget{}', $params['class']));
	}

}


//1、smarty的模板文件以.tpl为结尾。

//2、在配置文件“config.inc.php” 中来设定文件及页面输出方式等。

// 例如：变量在.tpl文件中的输出格式的设定： $smarty_delimiter     = explode("|","{{|}}");

//         那么，.tpl文件中，变量的输出方式为：{{$res}}

//         如果$res为一个数组，则打印方法为：

//        {{foreach key=key2 item=item1 from=$res}}
//              {{$key2}}{{$key2}}
//       {{/foreach}}

// 验证这些文件的时候，可以通过查看缓存文件中的代码来确认。

//3、if 判断

{{if $item['created_at']}}
        {{date('Y-m-d H:i:s',$item['created_at'])}}
{{else}}
        时间记错了
    {{/if}}    

//4、smarty 中 应用cache 例子：

$smarty->caching      = true;
//缓存5分钟
$smarty->cache_lifetime  = 300;      //这里要注意，时间的设定一定要在$smarty->is_cached之前，否则，缓存设定的时间仍然为默认的3600s。
if($smarty->isCached('weibolist.tpl')) {
       $smarty->display('weibolist.tpl');
      exit;
}


//1.smarty 里面使用foreach循环

<ul class="list"> 
                <!--{if $list==''}-->
     <li>抱歉,没有相关数据!</li> 
    <!--{else}-->
     <!--{foreach from=$list item=val key=key}-->
   
      <li><em><!--{$val.time}--></em>·[<span style="color:#B0171A;"><a href="<!--{$val.col_url}-->" target="_blank"><!--{$val.column}--></a></span>] <a href="<!--{$val.url}-->" target="_blank"><!--{$val.title}--></a></li> 
   
     <!--{if ($key+1)%5==0}-->
      <div class="line"></div> 
     <!--{/if}-->
     <!--{/foreach}-->
    <!--{/if}-->
</ul>

//2.smarty 里面使用section循环
	
<!--{if $list==''}-->
           <ul class="ztli clearfix f_simsun mt10"> 
                <li>抱歉,没有相关数据!</li> 
           </ul> 
        <!--{else}-->
            <ul class="ztli clearfix f_simsun mt10"> 
                <!--{section name=temp loop=$list}-->
                    <li><span class="fr"><!--{$list[temp].time}--></span>· 
                        [<a href="<!--{$list[temp].col_url}-->" target="_blank" class="col_2"><!--{$list[temp].column}--></a>]  
                        <a href="<!--{$list[temp].url}-->" target="_blank"><!--{$list[temp].title}--></a> 
                    </li> 
                <!--{if ($smarty.section.temp.iteration)%5 eq 0}-->
                    </ul> 
                    <div class="line-solid mt20 mb20"></div> 
                    <!--{if ($smarty.section.temp.iteration)%60 neq 0}-->
                        <ul class="ztli clearfix f_simsun mt10"> 
                    <!--{/if}-->
                <!--{/if}-->
            <!--{/section}-->
        <!--{/if}-->