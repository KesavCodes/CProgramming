#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        printf("%d", n);
    }
}

int main(int argc, char const *argv[])
{
    int x = 3;
    func(x);
    return 0;
}
