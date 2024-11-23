#include <stdio.h>

void toh(int disc, int src, int des, int help){
    if(disc==0) return;
    toh(disc-1, src, help, des);
    printf("Move disc %d from %d to %d using %d\n", disc, src, des, help);
     toh(disc-1, help, des, src);
}

int main(){
    toh(1, 1, 3, 2);
}