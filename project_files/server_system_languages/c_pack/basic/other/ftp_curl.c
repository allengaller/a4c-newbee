#include <curl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curl/types.h>
#include <curl/easy.h>
#define TRUE	1
FILE *fp;
//回调函数，其形式是为了符合CURLOPT_WRITEFUNCTION      的需要
size_t
write_data (void *ptr, size_t size, size_t nmemb, void *stream)
{
  int flag = fwrite (ptr, size, nmemb, (FILE *) fp);
  return flag;
}

int
main (int argc, char **argv)
{
  CURL *curl_ftp;
//CURLcode curl_global_init(long flags);
  curl_global_init (CURL_GLOBAL_ALL);	//初始化curl库
//CURL *curl_easy_init( );
  curl_ftp = curl_easy_init ();	//得到一个初始化后的curl标识符
  if ((fp = fopen (argv[2], "w")) == NULL)
    {
      printf ("please input right filename\n");
//void curl_easy_cleanup(CURL *handle);
      curl_easy_cleanup (curl_ftp);	//清除curl内存空间
      _exit (1);
    }
  if (curl_ftp)
    {
//CURLcode curl_easy_setopt(CURL *handle, CURLoption option, parameter);
      curl_easy_setopt (curl_ftp, CURLOPT_URL, argv[1]);	//设置curl工作参数:要访问的服务器url域名，通过argv［1］传递
      curl_easy_setopt (curl_ftp, CURLOPT_USERPWD, "aaa:aaa");	//服务器帐户的用户名和密码
      curl_easy_setopt (curl_ftp, CURLOPT_WRITEFUNCTION, write_data);	//配置回调函数名称
      curl_easy_setopt (curl_ftp, CURLOPT_VERBOSE, TRUE);	//显示状态信息
//CURLcode curl_easy_perform(CURL *handle);
      curl_easy_perform (curl_ftp);	//curl开始工作
    }
  fclose (fp);
  curl_easy_cleanup (curl_ftp);
  _exit (0);
}
