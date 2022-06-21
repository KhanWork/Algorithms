#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortInWave(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i += 2)
    {
        if(i > 0 && arr[i - 1] > arr[i])
            swap(&arr[i], &arr[i - 1]);

        if(i < size - 1 && arr[i] < arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    }
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, size);
    int i;

    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\r\n");
    
    return 0;
}