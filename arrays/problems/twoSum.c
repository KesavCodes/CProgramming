#include <stdio.h>
#include <stdlib.h>

void twoSum()
{
    int key = 10;
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int maxElement = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    int *hashSet = (int *)malloc(maxElement * sizeof(int));
    for (int i = 0; i <= maxElement; i++)
        hashSet[i] = 0;
    for (int i = 0; i < 10; i++)
    {
        int requiredNum = key - arr[i];
        if (hashSet[requiredNum] != 0 && requiredNum >= 0)
        {
            printf("%d + %d = %d\n", arr[i], requiredNum, key);
        }
        hashSet[arr[i]]++;
    }
}

void twoSumSorted()
{
    int key = 10;
    int arr[11] = {0, 1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int i = 0, j = 10;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum > key)
        {
            j--;
        }
        else if (sum < key)
        {
            i++;
        }
        else
        {
            printf("%d + %d = %d\n", arr[i], arr[j], key);
            j--;
            i++;
        }
    }
}

int main()
{
    twoSum();
    twoSumSorted();
}
