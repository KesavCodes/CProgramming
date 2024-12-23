#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *A;
    int size;
    int length;
} Array;

// Prints all the elements of an given array. Time complexity: O(n)
void Display(Array arr)
{
    printf("Printing all elements of an array: \n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

// Add element at the last of the array. Time complexity: O(1)
void Append(Array *arr, int x)
{
    if (arr->size == arr->length)
    {
        printf("The array is full, can't add element %d\n", x);
        return;
    }
    arr->A[arr->length] = x;
    arr->length++;
    printf("The element %d is added to the array.\n", x);
}

// Insert element at a given index. Time complexity: O(n)
void Insert(Array *arr, int index, int x)
{
    if (index < 0 || index > arr->length)
    {
        printf("Can't insert element at index %d, the last index of the element is %d (index range can be between 0 and %d)\n", index, arr->length - 1, arr->length);
        return;
    }
    if (arr->size == arr->length)
    {
        printf("The array is full, can't add element %d\n", x);
        return;
    }
    arr->A[arr->length] = x;
    int i = arr->length;
    while (i > index)
    {
        arr->A[i] = arr->A[i - 1];
        i--;
    }
    arr->A[i] = x;
    arr->length++;
    printf("The element %d is added to the array at index %d.\n", x, index);
}

// Delete an element of the given index from the array. Time complexity: O(n)
int Delete(Array *arr, int index)
{
    if (index < 0 || index > arr->length - 1)
    {
        printf("Can't delete element at index %d, the last index of the element is %d (index range can be between 0 and %d)\n", index, arr->length - 1, arr->length - 1);
        return 0;
    }
    int i = index;
    int x = arr->A[i];
    while (i < arr->length - 1)
    {
        arr->A[i] = arr->A[i + 1];
        i++;
    }
    arr->length--;
    printf("The element %d is deleted from the array at index %d.\n", x, index);
    return x;
}

// Search an array for an given an given key and return an index if the key present in the array or else returns -1
int LinearSearch(Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
            return i;
    }
    return -1;
}

// This method will move the searched element one index to the front so that next time if the same key is called it has to perform n-1 checks.
int OptimizedLinerSearchTransposition(Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            if (i != 0)
            {
                int temp = arr->A[i];
                arr->A[i] = arr->A[i - 1];
                arr->A[i - 1] = temp;
            }
            return i;
        }
    }
    return -1;
}

// This method will swap the searched element with the head of array. so the very next time (subsequential request) if the same key is called it will got the result in O(1).

int OptimizedLinerSearchMoveToFront(Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[0];
            arr->A[0] = temp;
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array arr, int key)
{
    int mid, l = 0, h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return RBinarySearch(a, l, mid - 1, key);
        else
            return RBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int GetValue(Array arr, int index)
{
    if (index < 0 || index > arr.length - 1)
    {

        printf("Can't get value of element at index %d, the last index of the element is %d (index range can be between 0 and %d)\n", index, arr.length - 1, arr.length);
        return -1;
    }
    return arr.A[index];
}

void SetValue(Array *arr, int index, int x)
{
    if (index < 0 || index > arr->length)
    {
        printf("Can't insert element at index %d, the last index of the element is %d (index range can be between 0 and %d)\n", index, arr->length - 1, arr->length);
        return;
    }
    arr->A[index] = x;
}

int MaxValue(Array arr)
{
    if (arr.length == 0)
        return -1;
    int maxValue = arr.A[0];
    int i = 1;
    while (i < arr.length)
    {
        if (arr.A[i] > maxValue)
            maxValue = arr.A[i];
        i++;
    }
    return maxValue;
}

int MinValue(Array arr)
{
    if (arr.length == 0)
        return -1;
    int minValue = arr.A[0];
    int i = 1;
    while (i < arr.length)
    {
        if (arr.A[i] < minValue)
            minValue = arr.A[i];
        i++;
    }
    return minValue;
}
int SumOfArr(Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return sum;
}
float AvgOfArr(Array arr)
{
    return (float)SumOfArr(arr) / arr.length;
}

void Reverse(Array *arr)
{
    int l = 0, r = arr->length - 1;
    while (l < r)
    {
        int temp = arr->A[l];
        arr->A[l] = arr->A[r];
        arr->A[r] = temp;
        l++;
        r--;
    }
}

void InsertInSortedArray(Array *arr, int x)
{
    if (arr->size == arr->length)
    {
        printf("The array is full, can't add element %d\n", x);
        return;
    }
    int i = arr->length;
    arr->A[i] = x;
    while (arr->A[i] < arr->A[i - 1] && i > 0)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[i - 1];
        arr->A[i - 1] = temp;
        i--;
    }
    arr->length += 1;
    printf("The element %d is added to the array at index %d.\n", x, i);
}

bool IsSorted(Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }
    return true;
}

void MoveNegativeToLeftSide(Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

Array Merge(Array arr1, Array arr2)
{
    Array newArr;
    newArr.size = arr1.size + arr2.size;
    newArr.length = arr1.length + arr2.length;
    int i = 0, j = 0, k = 0;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            newArr.A[k++] = arr1.A[i++];
        else
            newArr.A[k++] = arr2.A[j++];
    }
    while (i < arr1.length)
        newArr.A[k++] = arr1.A[i++];
    while (j < arr2.length)
        newArr.A[k++] = arr2.A[j++];
    return newArr;
}

Array Union(Array *arr1, Array *arr2)
{
    Array newArr;
    newArr.size = arr1->size + arr2->size;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    int i, j, k;
    for (i = 0; i < arr1->length; i++)
        newArr.A[i] = arr1->A[i];
    for (j = 0; j < arr2->length; j++)
    {
        int isNew = true;
        for (k = 0; k < arr1->length; k++)
        {
            if (arr2->A[j] == arr1->A[k])
            {
                isNew = false;
                break;
            }
        }
        if (isNew)
            newArr.A[i++] = arr2->A[j];
    }
    newArr.length = i;
    return newArr;
}

Array UnionForSortedArray(Array *arr1, Array *arr2)
{
    Array newArr;
    newArr.size = arr1->size + arr2->size;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] == arr2->A[j])
        {
            newArr.A[k++] = arr1->A[i];
            i++;
            j++;
        }
        else if (arr1->A[i] < arr2->A[j])
        {
            newArr.A[k++] = arr1->A[i++];
        }
        else
        {
            newArr.A[k++] = arr2->A[j++];
        }
    }
    while (i < arr1->length)
        newArr.A[k++] = arr1->A[i++];
    while (j < arr2->length)
        newArr.A[k++] = arr2->A[j++];
    newArr.length = k;
    return newArr;
}

Array Intersection(Array *arr1, Array *arr2)
{
    Array newArr;
    newArr.size = arr1->length > arr2->length ? arr2->length : arr1->length;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    int i = 0, k = 0;
    for (; i < arr1->length; i++)
    {
        bool isIntersect = false;
        bool isUnique = true;
        for (int j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
            {
                isIntersect = true;
                break;
            }
        }
        if (!isIntersect)
            continue;
        for (int l = 0; l < k; l++)
        {
            if (arr1->A[i] == newArr.A[l])
            {
                isUnique = false;
                break;
            }
        }
        if (!isUnique)
            continue;
        newArr.A[k++] = arr1->A[i];
    }
    newArr.length = k;
    return newArr;
}

Array IntersectionForSortedArray(Array *arr1, Array *arr2)
{
    Array newArr;
    newArr.size = arr1->length > arr2->length ? arr2->length : arr1->length;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] == arr2->A[j])
        {
            newArr.A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
        else if (arr1->A[i] < arr2->A[j])
            i++;
        else
            j++;
    }
    newArr.length = k;
    return newArr;
}

Array Difference(Array *arr1, Array *arr2)
{
    Array newArr;
    newArr.size = arr1->size;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    int k = 0;
    for (int i = 0; i < arr1->length; i++)
    {
        bool isPresentInArr2 = false;
        for (int j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
            {
                isPresentInArr2 = true;
                break;
            }
        }
        if (!isPresentInArr2)
            newArr.A[k++] = arr1->A[i];
    }
    newArr.length = k;
    return newArr;
}

int main()
{
    Array arr;
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the numbers of elements to be added: ");
    scanf("%d", &n);
    printf("Enter all elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    Display(arr);
    Array arr1 = {(int[]){1, 10, 18, 18, 30, 44}, 10, 5};
    Array arr2 = {(int[]){8, 18, 30, 38}, 10, 4};
    Array resArr = Intersection(&arr1, &arr2);
    // Reverse(&arr);
    // printf("%s\n", IsSorted(arr) ? "true" : "false");
    // InsertInSortedArray(&arr, 25);
    Display(resArr);
    printf("Length of the newArray: %d\n", resArr.length);
    MoveNegativeToLeftSide(&arr);
    // Append(&arr, 50);
    // Insert(&arr, 8, 100);
    // Insert(&arr, 1, 100);
    Display(arr);
    // printf("%s\n", IsSorted(arr) ? "true" : "false");
    // Delete(&arr, 0);
    // Insert(&arr, 6, 100);
    // Display(arr);

    // printf("Linear search: %d\n", LinearSearch(arr, 30));
    // printf("Binary search: %d\n", BinarySearch(arr, 30));
    // printf("Recursive Binary search: %d\n", RBinarySearch(arr.A, 0, arr.length - 1, 30));

    // printf("Linear search: %d\n", LinearSearch(arr, 55));
    // printf("Binary search: %d\n", BinarySearch(arr, 55));
    // printf("Recursive Binary search: %d\n", RBinarySearch(arr.A, 0, arr.length, 55));

    return 0;
}