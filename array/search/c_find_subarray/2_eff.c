#include <stdio.h>

int subArraySum(int *arr, int size, int sum)
{
    int curr_sum = arr[0], start = 0, i, k;

    for(i = 1; i <= size; i++)
    {
        while(curr_sum > sum && start < i - 1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        if(curr_sum == sum)
        {
            printf("%d is sum of subarray: {", sum);
            for(k = start; k < i; k++)
                printf("%d, ", arr[k]);
            printf("\b\b}\r\n");
            //printf("sum found between indexes %d and %d", start, i - 1);

            return 1;
        }
        if(i < size)
            curr_sum += arr[i];
    }

    printf("No subarray found\r\n");
    return 0;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;

    subArraySum(arr, size, sum);

    return 0;
}