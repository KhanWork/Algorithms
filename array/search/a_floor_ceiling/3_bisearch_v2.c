#include <stdio.h>

int ceil_search(int *arr, int low, int high, int x)
{
	if(x == 0)
		return -1;
	
	int mid;

	while(low <= high)
	{
		mid = low + (high - low) / 2;
		if(arr[mid] == x)
			return mid;
		else if(x < arr[mid])
			high = mid -1;
		else
			low = mid + 1;
	}

	return low;
}

int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 8;
	int index = ceil_search(arr, 0, size - 1, x);

	if(index == -1)
		printf("Ceiling of %d doesn't exsist\r\n", x);
	else
		printf("Ceiling of %d is %d\r\n", x, arr[index]);

	return 0;
}
