/*  Computes averages of three numbers */

int average(int a, int b)
{
    return (a + b) / 2;
}

int main(void)
{
    int num1, num2, num3;
    
    printf("Enter three numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("Average of %d and %d: %d\n", num1, num2, average(num1, num2));
    printf("Average of %d and %d: %d\n", num2, num3, average(num2, num3));
    printf("Average of %d and %d: %d\n", num1, num3, average(num1, num3));

    return 0;
}


