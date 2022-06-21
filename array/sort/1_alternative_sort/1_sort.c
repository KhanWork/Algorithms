#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void alternateSort(int *arr, int size)
{
    qsort(arr, size, sizeof(int), cmp);
    
    int i = 0, j = size -1;
    while(i < j)
    {
        printf("%d ", arr[j--]);
        printf("%d ", arr[i++]);
    }

    if(size % 2 != 0)
        printf("%d ", arr[i]);
    
    printf("\r\n");
}

int main()
{
    int arr[] = {1, 12, 4, 6, 7, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    alternateSort(arr, size);

    return 0;
}