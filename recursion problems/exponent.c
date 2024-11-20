#include <stdio.h>

int exponent(int x, int y){
    if(y>0){
        return x*exponent(x, y-1); 
    }
    return 1;
}

int optimizedExponent(int x, int y){
    if(y>0){
        if(y%2==0){
            return optimizedExponent(x*x, y/2);
        }else {
            return x * optimizedExponent(x*x, y/2);
        }
    }
    return 1;
}

int main(){
    int res1 = exponent(3,4);
    int res2 = optimizedExponent(3,4);
    printf("%d ", res1);
    printf("%d ", res2);
}