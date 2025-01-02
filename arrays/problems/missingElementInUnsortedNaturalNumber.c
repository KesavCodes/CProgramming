#include <stdio.h>
#include <stdlib.h>

void missingElementsInUnsortedNaturalNumber()
{
    int arr[11] = {3, 7, 4, 9, 12, 6, 1, 2, 10};
    int maxElement = arr[0];
    for (int i = 0; i < 11; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    int *hashTable = (int*)malloc(maxElement * sizeof(int));
    for (int i = 0; i <= maxElement; i++) hashTable[i]=0;
    for (int i = 0; i < 11; i++) hashTable[arr[i]]+=1;
    printf("The missing elements are : ");
    for (int i = 1; i <= maxElement; i++) if(hashTable[i]==0) printf("%d ", i);
}

int main()
{
    missingElementsInUnsortedNaturalNumber();
}
