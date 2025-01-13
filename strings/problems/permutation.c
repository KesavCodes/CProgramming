#include <stdio.h>

void permutation(char *str, int *processed, char *res, int k)
{
    if (str[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
        return;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (processed[i] == 0)
        {
            processed[i] = 1;
            res[k] = str[i];
            permutation(str, processed, res, k + 1);
            res[k] = '\0';
            processed[i] = 0;
        }
    }
}

int main()
{
    char str[] = "abc", res[4];
    int processed[3] = {0};
    int k = 0;
    permutation(str, processed, res, k);
    return 0;
}