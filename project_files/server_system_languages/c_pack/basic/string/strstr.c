#include<string.h>

main()
{
	char *s = "Content Disposition: form data; name=\"filename\"; filename=\"abc\"";
	char *p;
	p = strstr(s, "filename");
	printf("%s\n",p);
}
