#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void show_handler(struct sigaction * act)
{
    switch (act->sa_flags) {
        case SIG_DFL:printf("Default action\n");break;
        case SIG_IGN:printf("Ignore the signal\n");break;
        default: printf("0x%x\n",act->sa_handler);
    }
}

main()
{
    int i;
    struct sigaction act , oldact;
    act.sa_handler = show_handler;
    act.sa_flags = SA_ONESHOT|SA_NOMASK;
    sigaction(SIGUSR1 , &act , &oldact);
    for(i=5;i<15;i++) {
        printf("sa_handler of signal %2d =",i);
        sigaction(i,NULL,&oldact);
    }
}

