#include <stdio.h>

int sum(int n)
{
    if (n > 0)
    {
        return n + sum(n - 1);
    }
    return n;
}

int main()
{
    int res = sum(10);
    printf("The sum of first 10 natural number is %d", res);
}