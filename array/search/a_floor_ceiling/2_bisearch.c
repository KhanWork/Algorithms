#include <stdio.h>

int ceil_search(int *arr, int low, int high, int x)
{
	int mid;

	if(x <= arr[low])
		return low;

	if(x > arr[high])
		return -1;

	mid = (low + high)/2;
	if(arr[mid] == x)
		return mid;
	else if(arr[mid] < x)
	{
		if(mid + 1 < high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceil_search(arr, mid + 1, high, x);
	}
	else
	{
		if(mid - 1 >= low && x > arr[mid - 1])
			return mid;
		else
			return ceil_search(arr, low, mid - 1, x);
	}
}

int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 11;
	int index = ceil_search(arr, 0, size - 1, x);

	if(index == -1)
		printf("Ceiling of %d doesn't exist in array\r\n", x);
	else
		printf("Ceiling of %d is %d\r\n", x, arr[index]);

	return 0;
}
