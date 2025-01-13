#include <stdio.h>

int isValidString(char *name)
{
    int i = 0;
    while (name[i] != '\0')
    {
        if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || (name[i] >= 48 && name[i] <= 57)))
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char name1[] = "batsy1234";
    char name2[] = "supes!777!";
    char name3[] = "wondERwoMaN";

    printf("%d\n", isValidString(name1));
    printf("%d\n", isValidString(name2));
    printf("%d\n", isValidString(name3));
    return 0;
}