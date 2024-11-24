#include <stdio.h>
#include <stdlib.h>
int main()
{
    // static array with fixed type - Both size and type know before the compile time
    int A[5];
    // dynamic array - Both size and type will be know only during the runtime
    int *p, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));

    A[0] = 10;
    p[0] = 20;
    p[1] = 40;
    p[2] = 60;

    printf("%d\t", *A);
    printf("%d", *p);
    return 0;
}