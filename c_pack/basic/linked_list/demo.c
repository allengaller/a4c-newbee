#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
}*start;

main()
{
    int choice, n, m, po, i;
    start = NULL;
    while(1)
    {
        printf("1.Create List\n");
        printf("2.Add at begining\n");
        printf("3.Add after\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Count\n");
        printf("7.Reverse\n");
        printf("8.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("How many nodes you want:");
                scanf("%d", &choice)
        }
    }
}
