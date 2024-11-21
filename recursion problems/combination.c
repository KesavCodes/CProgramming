#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int rCombination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return rCombination(n - 1, r - 1) + rCombination(n - 1, r);
}

int iCombination(int n, int r)
{
    int num = fact(n);
    int den = fact(r) * fact(n - r);
    return num / den;
}

int main()
{
    int res1 = rCombination(4, 2);
    int res2 = iCombination(4, 2);
    printf("%d ", res1);
    printf("%d ", res2);
}