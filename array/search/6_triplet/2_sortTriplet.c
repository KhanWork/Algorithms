#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
//qsort(array, len, sizeof(int), cmp);
bool find_3_num(int *arr, int size, int sum)
{
	int left, right;
	int i;

	qsort(arr, size, sizeof(int), cmp);
	for(i = 0; i < size -2; i++)
	{
		left = i + 1;
		right = size - 1;		
		while(left < right)
		{
			if(arr[i] + arr[left] + arr[right] == sum)
			{
				printf("Triplet is: %d, %d, %d\r\n", arr[i], arr[left], arr[right]);
				return true;
			}
			else if(arr[i] + arr[left] + arr[right] < sum)
				left++;
			else
				right--;
		}
	}

	return false;
}

int main()
{
	int arr[] = {1, 4, 45, 6, 10, 8};
	int sum = 22;
	int size = sizeof(arr)/sizeof(arr[0]);

	find_3_num(arr, size, sum);
	return 0;
}
