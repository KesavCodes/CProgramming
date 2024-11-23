#include <stdio.h>

int power(int num, int pow)
{
    if (pow > 0)
    {
        return num * power(num, pow - 1);
    }
    return 1;
}

int fact(int num)
{
    if (num > 0)
    {
        return num * fact(num - 1);
    }
    return 1;
}

double taylorSeries(int x, int n)
{
    if (n > 0)
    {
        return ((double)power(x, n) / fact(n)) + taylorSeries(x, n - 1);
    }
    return 1;
}

double taylorSeriesUsingStaticVar(int x, int n)
{
    static double p = 1, f = 1;
    double res;
    if (n == 0)
        return 1;
    res = taylorSeriesUsingStaticVar(x, n - 1);
    p *= x;
    f *= n;
    return res + (p / f);
}
  
double taylorSeriesUsingHornerRule(int x, int n, int ref){
    if(ref>n) return 1;
    return 1 + ((double)x/ref * taylorSeriesUsingHornerRule(x, n, ref+1));
}

int main()
{
    int x = 2;
    int n = 4;
    double res1 = taylorSeries(x, n);
    double res2 = taylorSeriesUsingStaticVar(x, n); 
    double res3 = taylorSeriesUsingHornerRule(x, n, 1); 
    printf("%.2lf \n", res1);
    printf("%.2lf \n", res2);
    printf("%.2lf ", res3);
}