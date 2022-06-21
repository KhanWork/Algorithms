#include <stdio.h>

int find_peak(int *arr, int n)
{
	if(1 == n)
		return 0;
	if(arr[0] >= arr[1])
		return 0;
	if(arr[n - 1] >= arr[n - 2])
		return n -1;

	int i;
	for(i = 1; i < n - 1; i++)
	{
		if(arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
			return i;
	}
}

int main()
{
	int arr[] = {1, 3, 20, 4, 1, 0};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("peak is: %d\r\n", arr[find_peak(arr, size)]);

	return 0;
}
