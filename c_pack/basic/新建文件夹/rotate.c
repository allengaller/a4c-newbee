
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * invert (char * str_start, char * str_end)
{
    char *ptmp = str_start;
    char ctmp;

    if (str_start == NULL || str_end == NULL) {
        return NULL;
    }

    while (str_start < str_end) {
        ctmp = *str_start;
        *str_start = *str_end;
        *str_end = ctmp;
        str_start++;
        str_end--;
    }

    return ptmp;
}

char * rotate (char * str, int num)
{
    char *ptmp = str;

    if (str == NULL) {
        return NULL;
    }

    int last_index = strlen(str) - 1;
    num = num % (last_index + 1);
    invert (ptmp, ptmp + num -1);
    invert (ptmp + num, ptmp + last_index);
    invert (ptmp, ptmp + last_index);

    return ptmp;
}

int main ()
{ 
    char str[] = "abcdefg";
    char str_tmp[17];
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        strcpy (str_tmp, str);
        char *tmp = rotate (str_tmp, i);
        printf ("i: %d; value: %s\n", i, tmp);
    }

    return 0;
}

