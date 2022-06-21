#include <stdio.h>
#include <stdbool.h>

bool find_3_num(int *arr, int size, int sum)
{
	int left, right;
	int i, j, k;

	for(i = 0; i < size - 2; i++)
		for(j = i + 1; j < size - 1; j++)
			for(k = j + 1; k < size; k++)
			{
				if(arr[i] + arr[j] + arr[k] == sum)
				{
					printf("Triplet is: %d, %d, %d\r\n", arr[i], arr[j], arr[k]);
					return true;
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
