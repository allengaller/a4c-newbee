#include <stdio.h>
#include <stdlib.h>



int count_one(unsigned int n)
{
    int x = n;
    x = (x & 0x55555555ul) + ((x >> 1) & 0x55555555ul);
    x = (x & 0x33333333ul) + ((x >> 2) & 0x33333333ul);
    x = (x & 0x0f0f0f0ful) + ((x >> 4) & 0x0f0f0f0ful);
    x = (x & 0x00ff00fful) + ((x >> 8) & 0x00ff00fful);
    x = (x & 0x0000fffful) + ((x >> 16) & 0x0000fffful);
    
    return x;
}

int main()
{
    unsigned int itest = 0xabcdefab;
    scanf ("%d", &itest);
    printf("num is : 0x%x; the num has %d one\n", itest, count_one(itest));
    return 0;
}

