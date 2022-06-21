#include <stdio.h>

int findPeak(int *arr, int size)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right)
    {
        mid = (left + right) >> 1;

        if((0 == mid || arr[mid - 1] <= arr[mid]) && (size - 1 == mid || arr[mid + 1] <= arr[mid]))
            break;
        
        if(mid > 0 && arr[mid - 1] > arr[mid])
            right = mid - 1;

        else
            left = mid + 1;
    }

    return mid;
}

int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Peak is: %d\r\n", arr[findPeak(arr, size)]);

    return 0;
}