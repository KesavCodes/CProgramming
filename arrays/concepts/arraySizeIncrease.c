#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++)
        q[i] = p[i];
    q[5] = 11;
    q[6] = 13;
    q[7] = 15;

    free(p);

    p = q;

    q = NULL;

    for(int i=0;i<10;i++) printf("%d \n", p[i]);
    return 0;
}