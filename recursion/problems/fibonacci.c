#include <stdio.h>

int arr[10];

int fib(int n)
{
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int optimizedFib(int n)
{
    if (n < 2)
    {
        arr[n] = n;
        return n;
    }
    arr[n] = (arr[n - 1] == -1 ? optimizedFib(n - 1) : arr[n - 1]) + (arr[n - 2] == -1 ? optimizedFib(n - 2) : arr[n - 2]);
    return arr[n];
}

int IterFib(int n)
{
    if (n < 2)
        return n;
    int t1 = 0;
    int t2 = 1;
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum = t1 + t2;
        t1 = t2;
        t2 = sum;
    }
    printf("The iterative fib: %d\n", sum);
}

int main()
{
    int res = fib(9);
    IterFib(9);
    for (int i = 0; i <= 9; i++)
        arr[i] = -1;
    printf("%d \n", res);
    int optRes = optimizedFib(9);
    printf("%d ", optRes);
}