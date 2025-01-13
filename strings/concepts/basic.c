#include <stdio.h>

int main()
{
    // char array declaration and initialization
    char A[5];
    char B[5] = {'a', 'b', 'c', 'd', 'e'};
    char C[] = {'a', 'b', 'c', 'd', 'e'};
    char D[5] = {'a', 'b'}; // will have 0 for the index 2,3 and 4

    // string is a char array with null charater to denote the end of the string
    // \0 is a null char which is used to identify end of the string 
    char name1[10] = {'J', 'o', 'h', 'n', '\0'}; // The size of the arr is 5
    char name2[] = "John"; // When using double quotes, null char is not needed to be added at the end

    //printing and reading a string;
    scanf("%s", A);
    printf("%s", A);

    return 0;
}