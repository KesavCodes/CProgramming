#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *reverse(char *name, int length)
{

    for (int j = 0; j < length / 2; j++)
    {
        char temp = name[j];
        name[j] = name[length - 1 - j];
        name[length - 1 - j] = temp;
    }
    return name;
}

// method 1: reverse a string, compare each index of original and reversed string
bool isPalindrome(char *name)
{
    int length = 0;
    while (name[length] != '\0')
        length++;
    char *reversedString = (char *)malloc(length * sizeof(char));
    for (int i = 0; i <= length; i++)
        reversedString[i] = name[i];
    reversedString = reverse(reversedString, length);
    for (int i = 0; i < length; i++)
        if (name[i] != reversedString[i])
            return false;
    return true;
}

// method 2: Checking in place using 2 pointers.
bool isPalindromeInPlace(char *name)
{
    int length = 0;
    while (name[length] != '\0')
        length++;
    for (int i = 0, j = length-1; i < j; i++, j--)
    {
        if(name[i]!=name[j]) return false;
    }
    return true;
}

int main()
{
    char name1[] = "batsy1234";
    char name2[] = "!767!";
    char name3[] = "tenet";

    printf("%s\n", isPalindromeInPlace(name1) ? "True" : "False");
    printf("%s\n", isPalindromeInPlace(name2) ? "True" : "False");
    printf("%s\n", isPalindromeInPlace(name3) ? "True" : "False");

    printf("%s\n", isPalindrome(name1) ? "True" : "False");
    printf("%s\n", isPalindrome(name2) ? "True" : "False");
    printf("%s\n", isPalindrome(name3) ? "True" : "False");
    return 0;
}