#include <stdio.h>

void find(int *arr, int size)
{
	int mid = size/2;
	int leftsum = 0, rightsum = 0;

	int i;
	for(i = 0; i < mid; i++)
		leftsum += arr[i];

	for(i = size - 1; i > mid; i--)
		rightsum += arr[i];

	if(rightsum > leftsum)
	{
		while(rightsum > leftsum && mid < size - 1)
		{
			rightsum -= arr[mid + 1];
			leftsum += arr[mid];
			mid++;
		}
	}
	else
	{
		while(leftsum > rightsum && mid > 0)
		{
			rightsum += arr[mid];
			leftsum -= arr[mid - 1];
			mid--;
		}
	}

	if(rightsum == leftsum)
	{
		printf("First index of equilibrium is: %d\r\n", mid);
		return ;
	}
}

int main()
{
	int arr[] = {1, 1, 1, -1, 1, 1, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	find(arr, size);
}


