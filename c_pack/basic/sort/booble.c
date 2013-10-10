#include<stdio.h>

main() 
{ 
    int i,j,temp; 
    int a[10]; 
    for(i=0;i<10;i++) 
    scanf ("%d,",&a[i]); 

    for(j=0;j<=9;j++) 
    { 
        for (i=0;i<10-j;i++) 
        {
            if (a[i]>a[i+1]) 
            { 
                temp=a[i]; 
                a[i]=a[i+1]; 
                a[i+1]=temp;
            }
        }
    } 
    
    for(i=1;i<11;i++) 
    printf("%5d,",a[i] ); 
    printf("\n"); 
}
