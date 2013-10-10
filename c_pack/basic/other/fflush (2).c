#include<stdio.h>
#include<unistd.h>
/*
main(){
    int i;
    for(i = 0; i < 10; i++) {
        printf("\n%d\n", i);
        fflush(stdout);
        sleep(1);
    }

}
*/

main()
{
    printf("hello");
    //fflush(stdout);
    fork();
    return 0;
} 
