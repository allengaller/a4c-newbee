#include<stdlib.h>

void my_exit(void)
{
    printf("before exit() \n");
}

main()
{
    atexit(my_exit);
    exit(0);
}
