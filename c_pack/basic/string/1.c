#include<string.h>
#include<stdio.h>

int main()
{
	//字符串内存函数
	char s1[20];//定义数组， 可视为连续内存块
	const char *s2 = "Linux rock!";//定义数组， 可视为连续内存块
	memcpy(s1, s2, 13);//将s2指向的内存块前13个字符复制到s1
	puts(s1);//打印s1
	memmove(s1, s1 + 6, 7);//将s1指向的内存块从第6个字符开始的7个字符复制给自己
	puts(s1);//打印s1
	printf("比较的结果是： %d\n", memcmp(s1, s2 + 6, 7));//比较s1和s2第6个字符开始的7个字节
	puts(memchr(s2, 'o', 13));//在s2指向内存块的前13个字符中查找字符r的位置
	puts(memset(s1, 'B', 6));//在s1所指向的内存块前6个字符设置为B	
	return 0;

	//字符串查找函数
	const char *s11 = "Happy New Year! ";
	const char *s22 = "Year";
	const char *s33 = "pye HwNa";
	char *p;
	p = strchr(s1, 'a');
	printf("在字符串s1中首次出现字母‘a’的位置是：");
	p != NULL ? puts(p) : puts("无");
	p = strrchr(s11, 'a');
	printf("在字符串s1中最后一次出现字母‘a‘的位置是：");
	p != NULL ? puts(p) : puts("无");
	printf("字符串s1从首字符开始不包括字符串s2所含字符的分段长度是： %d\n", strcspn(s11, s22));
	printf("字符串s1从首字符开始只包括字符串s3所含字符的分段长度是： ％d\n", strspn(s11,s33));
	p = strpbrk(s11, s22);
	printf("字符串s2中任意字符出现在s1中的位置是：");
	p != NULL ? puts(p) : puts("无");
	p = strstr(s11, s22);
	printf("字符串s2出现在字符串s1中的位置是： ");
	p != NULL ? puts(p) : puts("无");
}
