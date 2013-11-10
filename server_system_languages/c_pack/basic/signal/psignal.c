#include <signal.h>

main()
{
	int sig;
	char s[40];

	for(sig = 1; sig < 10; sig++) {
		sprintf(s, "signal %d", sig);
		psignal(sig, s);
	        //printf("%s\n", s);
	}
}
