/*
表头文件
	#include<unistd.h>
定义函数
	int getopt(int argc,char * const argv[ ],const char * optstring);

getopt()用来分析命令行参数。
参数argc和argv是由main()传递的参数个数和内容。
参数optstring 则代表欲处理的选项字符串。
此函数会返回在 argv 中下一个的选项字母，此字母会对应参数 optstring 中的字母。
如果选项字符串里的字母后接着冒号“:”，则表示还有相关的参数，全域变量 optarg 即会指向此额外参数。
如果getopt()找不到符合的参数则会印出错信息，并将全域变量optopt设为“?”字符，如果不希望getopt()印出错信息，则只要将全域变量opterr设为0即可。
*/
#include<stdio.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    int ch;
    opterr = 0;
    
    while((ch = getopt(argc,argv,"a:bcdex"))!= -1) {
        switch(ch){
            case 'a':
                printf("[ag] option a:'%s' \n", optarg);
                break;
            case 'b':
                printf("[ag] option b. \n");
                break;
            case 'c':
                printf("[ag] option c. \n");
                break;
            default:
                printf("[ag] other option :%c \n",ch);
        }
    }

    printf("[ag] optopt: %c \n",optopt);
    printf("[ag] opterr: %d \n", opterr);
}
