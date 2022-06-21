#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortInWave(int *arr, int size)
{
    qsort(arr, size, sizeof(int), cmp);

    int i = 0;

    for(i = 0; i < size - 1; i += 2)
        swap(&arr[i], &arr[i + 1]);
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    sortInWave(arr, size);
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\r\n");

    return 0;
}
