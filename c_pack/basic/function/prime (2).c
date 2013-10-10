/* Tests whether a number is prime */

#include<stdbool.h>
#include<stdio.h>

bool is_prime(int n)
{
    int divisor;
    
    if(n <= 1)
        return false;
    for(divisor = 2; divisor * divisor <= n; divisor++)
        if(n % divisor == 0)
            return false;
    return true;
}

int main(void)
{
    int quit;

    do
    {
        int n;
        
        printf("Enter a number: ");
        scanf("%d", &n);
        if(is_prime(n))
            printf("Prime\n");
        else
            printf("Not Prime\n");
        
        printf("Press 1 to quit.\nPress 0 to continue.\n");
                
        scanf("%d", &quit);
        if(quit == 1)
        {
            printf("Quit.\n");            
        } else if (quit = 0) {
            printf("Again.\n");
        }
    }while(quit == 0);
    
    return 0; 
}

