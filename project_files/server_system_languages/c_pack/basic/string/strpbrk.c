#include<string.h>

main()
{
	char *s = "12345 filename = \"abc\"";
	char *p;

	p = strpbrk(s, "filename = """);
	printf("%s\n",p);
	p = strpbrk(s, "4398");
	printf("%s\n",p);
}
