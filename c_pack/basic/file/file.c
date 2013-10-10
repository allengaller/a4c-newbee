#include <sys/stat.h>
#include<stdio.h>
#include<time.h>
#include<sys/types.h>

int main()
{

//获取当前时间的函数
 time_t nowtime;
 struct tm *timeinfo;
  time(&nowtime);
 timeinfo=localtime(&nowtime);
 //int year,month,day;
 //year=timeinfo->tm_year+1900;
 //month=timeinfo->tm_mon+1;
 //day=timeinfo->tm_mday;
 
 char txtname[100];
 * txtname=*asctime(timeinfo);//这句将结果转变为字符串
  
 if(access("flow",0)==-1)//access函数是查看文件是不是存在
 {
   if (mkdir("flow",0777))//如果不存在就用mkdir函数来创建
  {
   printf("creat file bag failed!!!");
  }
 } 
 
  char pathname[100];
  pathname[0]='f';  pathname[1]='l';//这里是单引号，第一次的时候写成双引号了，
  pathname[2]='o';  pathname[3]='w';
  pathname[4]='/';  pathname[5]='/';
  
  int i;
  for(i=0;txtname[i]!='\0';i++)
  {
   int j=6+i;
   pathname[j]=txtname[i];
  } 
  pathname[i+6]='.'; //这几句是加上后缀 .txt的

  pathname[i+8]='t';
  pathname[i+9]='x';
  pathname[i+10]='t';
  pathname[i+11]='\0';//最后别忘记加上这个

  FILE  *fp;
  if((fp=fopen(pathname,"w"))==NULL)//打开文件 没有就创建
  {
   printf("can not creat txt file!\n");
 
  }

  fprintf(fp,"hello the first created txt! successed!!!");
  fclose(fp);
}　　　　　
