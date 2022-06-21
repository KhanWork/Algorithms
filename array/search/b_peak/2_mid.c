#include <stdio.h>

int findPeakUtil(int *arr, int low, int high, int size)
{
    int mid = low + ((high - low) / 2);
    
    if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size -1 || arr[mid + 1] <= arr[mid]))
        return mid;
    
    else if(mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1), size);
    
    else
        return findPeakUtil(arr, (mid + 1), high, size);
}

int findPeak(int *arr, int size)
{
    return findPeakUtil(arr, 0, size - 1, size);
}

int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Peak is: %d\r\n", arr[findPeak(arr, size)]);

    return 0;
}