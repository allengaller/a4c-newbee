//Display menu until press 0 by using child process
/*A small program that display menu until press 0*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
   int choice;
   do {
      printf("\n---------------=====00=====---------------\n");
      printf("Main Menu\n");
      printf("Please select an option that you need:\n");
      printf("	1. Executer ls command\n");
      printf("	2. Execute ps command\n");
      printf("	3. Execute who command\n");
      printf("	0. exit\n");
      printf("Your choice:\n");
      scanf("%d", &choice);
  
      switch (choice){
          case 1:
               if (fork())
                  wait(0);
                else
                  execlp("ls", "ls", (char *)NULL);
                  break;
          case 2:
               if (fork())
                  wait(0);
               else
                  execlp("ps", "ps", (char *)NULL);
                  break;
          case 3:
               if (fork())
                  wait(0);
               else
                  execlp("who", "who", (char *)NULL);
                  break;
          case 0:
               break;
          default:
               printf("Please enter only 0-3");
       }
   }
   while (choice != 0);
}

