#include <stdio.h>

int equilibrium(int *arr, int size)
{
	if(size == 1)
		return 0;

	int forward[size];
	int reverse[size];

	int i;
	for(i = 0; i < size; i++)
	{
		if(i)
			forward[i] = forward[i-1] + arr[i];
		else
			forward[i] = arr[i];
	}
	for(i = size-1; i > 0; i--)
	{
		if(i <= size - 2)
			reverse[i] = reverse[i + 1] + arr[i];
		else
			reverse[i] = arr[i];
	}

	for(int i = 0; i < size; i++)
		if(forward[i] == reverse[i])
			return i;

	return -1;
}

int main()
{
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("First index of equilibrium is: %d\r\n", equilibrium(arr, size));

	return 0;
}


