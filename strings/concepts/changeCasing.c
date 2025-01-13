#include <stdio.h>

int main()
{
    char A[50] = "HELLO WorlD Is A fiZZ";
    int i = 0;
    printf("Original string : %s\n", A);
    while (A[i] != '\0')
    {
        if (A[i] >= 65 && A[i] <= 90)
        {
            A[i] += 32; // ASCII code for A-65 and a-97 -> To change to lower case just add 32
        }
        i++;
    };
    printf("Lowercase string : %s\n", A);
    i = 0;
    while (A[i] != '\0')
    {
        if (A[i] >= 97 && A[i] <= 122)
        {
            A[i] -= 32; // ASCII code for A-65 and a-97 -> To change to upper case just subtract 32
        }
        i++;
    };
    printf("Uppercase string : %s\n", A);
    return 0;
}