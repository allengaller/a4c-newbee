#include "stdio.h"
#define MaxSize 10

/*向顺序表中插入元素*/
/*参数Sqlist:表首地址*/
/*参数*len: 表的长度*/
/*参数pos: 插入元素的位置*/
/*参数val:待插入的元素值*/
void insertElem(int Sqlist[], int *len, int pos, int val) {
    int t;
    if (*len==MaxSize || pos<1 || pos>*len+1) {
        printf("This insert is illegal!\n");
        return;
    }

    for(t=*len-1; t>=pos-1; t--)
        Sqlist[t+1] = Sqlist[t];

    Sqlist[pos-1]=val;

    *len = *len + 1;
}

void printSqlist(int Sqlist[], int len) {
    int i=0;
    for(i=0; i<len; i++) {
        printf(" %d ", Sqlist[i]);
    }
}

int main()
{
    printf("This is sequence list demo!\n");

    int Sqlist[MaxSize];
    int len = 0;
    int pos = 0;

    //get amount of num for demo
    printf("Input how many num for demo: ");
    scanf("%d", &len);
    printf("OK, %d nums for this demo.\n", len);

    //get nums
    printf("Input the nums: ");
    for(pos=0; pos<len; pos++)
        scanf("%d", &Sqlist[pos]);
    printf("Your input is:");
    for(pos=0; pos<len; pos++)
        printf(" %d ", Sqlist[pos]);

    //spare length
    printf("\n The spare length is %d!\n", MaxSize-len);

    //insert elements
    int insertPos = 0;
    int val = 0;
    printf("INSERT\n");
    printf("Input the insert position:");
    scanf("%d", &insertPos);

    printf("Input the num you want to insert:");
    scanf("%d", &val);
    insertElem(Sqlist, &len, insertPos, val);
    printf("INSERT done!\n");

    printSqlist(Sqlist, len);
    return 0;
}
