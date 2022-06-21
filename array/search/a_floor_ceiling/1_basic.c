#include <stdio.h>

int ceil_search(int *arr, int low, int high, int x)
{
	int i;
	
	if(x <= arr[low])
		return low;

	for(i = low; i < high; i++)
	{
		if(arr[i] == x)
			return i;

		if(arr[i] < x && arr[i + 1] >= x)
			return i + 1;
	}

	return -1;
}

int main()
{
	int arr[] = {1, 2, 8, 10, 10, 12, 19};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 3;

	int index = ceil_search(arr, 0, size - 1, x);

	if(index == -1)
		printf("Ceiling of %d doesn't exist in array\r\n", x);
	else
		printf("Ceiling of %d is %d\r\n", x, arr[index]);

	return 0;
}
