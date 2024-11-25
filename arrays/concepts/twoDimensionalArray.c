#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declaring and initializing 2D array - Completely in stack
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};

    // declaring row array in stack and col array in heap
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in stack.
    B[1] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in stack.
    B[2] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in stack.

    // declaring both row array and col array in heap and pointing the row array to some pointer variable in stack.
    int **C;
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in heap.
    C[1] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in heap.
    C[2] = (int *)malloc(4 * sizeof(int)); // Col array is created in heap and linked to row array in heap.


    // Accessing 2D arrays
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}