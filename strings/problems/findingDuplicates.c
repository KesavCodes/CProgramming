#include <stdio.h>
#include <stdlib.h>

// this fn will only work for lower case alphabets. For all cases, we can increase the hash size.
int findDuplicateUsingHash(char *name)
{
    char hashSet[26];
    for (int i = 0; i < 26; i++)
        hashSet[i] = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hashSet[name[i] - 97]++;
    for (int i = 0; i < 26; i++)
        if (hashSet[i] > 1)
            printf("The char %c repeated %d times in string %s\n", i + 97, hashSet[i], name);
}

int findingDuplicateUsingBitWiseOperators(char *name)
{
    int bitSet = 0, x = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        x = 1;
        x = x << name[i] - 97;
        if ((bitSet & x) > 0) // Bit Masking
            printf("The char %c is duplicated.\n", name[i]);
        else
            bitSet = bitSet | x; // Bit Merging
    }
}

int main()
{
    char name1[] = "batman";
    char name2[] = "superman";
    char name3[] = "wonderwoman";

    findDuplicateUsingHash(name1);
    findDuplicateUsingHash(name2);
    findDuplicateUsingHash(name3);
    findingDuplicateUsingBitWiseOperators(name1);
    findingDuplicateUsingBitWiseOperators(name2);
    findingDuplicateUsingBitWiseOperators(name3);

    return 0;
}