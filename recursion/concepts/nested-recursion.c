#include <stdio.h>

int fun(int n){
    if(n>100) return n-10;
    return fun(fun(n+11));
}

int main(){
    int res = fun(95);
    printf("Result : %d", res);
}