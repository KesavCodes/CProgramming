#include <stdio.h>

void startingFromOne(){
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12};
    int n = arr[10];
    int sumOfNaturalNumbers = (n * (n + 1)) / 2;
    int sumOfElementsInArr = 0;
    for (int i = 0; i < 11; i++)
        sumOfElementsInArr += arr[i];
    int missingElement = sumOfNaturalNumbers - sumOfElementsInArr;
    printf("The missing element is %d\n", missingElement);
}

void startingFromX_v1(){
    int arr[11] = {6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17};
    int diff = arr[0], missingElement;
    for (int i = 0; i < 11; i++){
        if(arr[i]-i!=diff){
            missingElement = i + diff;
            break;
        }
    }
    printf("The missing element is %d\n", missingElement);
}

void startingFromX_v2(){
    int arr[11] = {6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17};
    int n = arr[10];
    int x = arr[0];
    int sumOfXNaturalNumbers = (x * (x - 1)) / 2;
    int sumOfNNaturalNumbers = (n * (n + 1)) / 2;
    int sumOfElementsInArr = 0;
    for (int i = 0; i < 11; i++)
        sumOfElementsInArr += arr[i];
    int missingElement = sumOfNNaturalNumbers - sumOfXNaturalNumbers - sumOfElementsInArr;
    printf("The missing element is %d\n", missingElement);
}

int main()
{
    startingFromOne();
    startingFromX_v1();
    startingFromX_v2();
}