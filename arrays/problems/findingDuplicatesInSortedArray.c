#include <stdio.h>
#include <stdlib.h>

void findingDuplicatesInSortedArray()
{
    int arr[13] = {3, 6, 8, 8, 8, 10, 10, 12, 15, 15, 15, 20, 20};
    int lastDuplicate;
    printf("The duplicate elements are : ");
    for (int i = 0; i < 12; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
        {
            printf("%d ", arr[i]);
            lastDuplicate = arr[i];
        }
    }
}

void findingDuplicateCountInSortedArray()
{
    int arr[13] = {3, 6, 8, 8, 8, 10, 10, 12, 15, 15, 15, 20, 20};
    int lastDuplicate;
    printf("The duplicate elements are : \n");
    for (int i = 0; i < 12; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            int count = 1;
            while (arr[i] == arr[i + 1])
            {
                count++;
                i++;
            }
            printf("The element %d repeated %d times\n", arr[i], count);
        }
    }
}

void findingDuplicateCountInSortedArrayUsingHashset()
{
    int arr[13] = {3, 6, 8, 8, 8, 10, 10, 12, 15, 15, 15, 20, 20};
    // If the array is unsorted, simply find the max element and create a hashset of size max element.
    int *hashSet = (int *)malloc(arr[12] * sizeof(int));
    printf("The duplicate elements are : \n");
    for (int i = 0; i <= arr[12]; i++)
        hashSet[i] = 0;
    for (int i = 0; i < 13; i++)
        hashSet[arr[i]]++;
    for (int i = 0; i <= arr[12]; i++)
        if(hashSet[i]>1) printf("The element %d is repeated %d times\n", i, hashSet[i]);
}

int main()
{
    findingDuplicatesInSortedArray();
    findingDuplicateCountInSortedArray();
    findingDuplicateCountInSortedArrayUsingHashset();
}
