#include <stdio.h>

int main()
{
    char A[20] = "Hello world";
    int i = 0;
    while(A[i]!='\0')i++;
    printf("The length of the array is %d", i);
    return 0;
}