#include <stdio.h>

void findingMinAndMax()
{
    int arr[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int min = arr[0], max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]<min){
            min = arr[i];
            continue; // Prevent unnecessary max condition check
        }
        if(arr[i]>max) max = arr[i];
    }
    printf("The Min element is : %d\n", min);
    printf("The Max element is : %d\n", max);
}


int main()
{
    findingMinAndMax();
}
