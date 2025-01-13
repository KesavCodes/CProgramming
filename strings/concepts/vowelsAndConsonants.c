#include <stdio.h>

int main()
{
    char A[] = "This is a string example";
    char vowels[] = "AEIOUaeiou";
    int i = 0, vCount = 0, cCount = 0;
    while (A[i] != '\0')
    {
        int j = 0;
        int isVowel = 0;
        while (vowels[j] != '\0' && isVowel == 0)
        {
            if (A[i] == vowels[j])
            {
                vCount += 1;
                isVowel = 1;
            }
            j++;
        }
        if (isVowel == 0 && ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122)))
            cCount += 1; 
        i++;
    }

    printf("Total number of vowels : %d\n", vCount);
    printf("Total number of consonants : %d", cCount);
    return 0;
}