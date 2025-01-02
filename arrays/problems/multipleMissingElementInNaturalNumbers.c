#include <stdio.h>

void startingFromX()
{
    int arr[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int res[11], k = 0;
    int diff = arr[0];
    for (int i = 0; i < 11; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                res[k++] = i + diff;
                diff++;
            }
        }
    }
    printf("The missing element are: ");
    for(int i=0;i<k;i++) printf("%d ", res[i]);
}

int main()
{
    startingFromX();
}
