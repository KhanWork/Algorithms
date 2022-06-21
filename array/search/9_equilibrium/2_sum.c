#include <stdio.h>

int equilibrium(int *arr, int size)
{
	int sum = 0;
	int leftsum = 0;

	for(int i = 0; i < size; i++)
		sum += arr[i];

	for(int i = 0; i < size; i++)
	{
		sum -= arr[i];

		if(leftsum == sum)
			return i;

		leftsum += arr[i];
	}

	return -1;
}

int main()
{
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("First equilibrium index is: %d\r\n", equilibrium(arr, size));

	return 0;
}
