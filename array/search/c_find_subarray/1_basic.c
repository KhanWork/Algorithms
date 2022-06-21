#include <stdio.h>

int subArraySum(int *arr, int size, int sum)
{
    int curr_sum, i, j, k;

    for(i = 0; i < size; i++)
    {
        curr_sum = arr[i];

        for(j = i + 1; j <= size; j++)
        {
            if(curr_sum == sum)
            {
                printf("%d is sum of subarray: {", sum);
                for(k = i; k < j; k++)
                    printf("%d, ", arr[k]);
                printf("\b\b}\r\n");
                //printf("Sum found between indexes %d and %d\r\n", i, j - 1);
                return 1;
            }
            if(curr_sum > sum || j == size)
                break;
            curr_sum += arr[j];
        }
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