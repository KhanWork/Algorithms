#include <stdio.h>

int check_pair(int *arr, int size, int x)
{
	int i;
	int j;
	for(i = 0; i < (size -1); i++)
		for(j = (i+1); j < size; j++)
		{
			if(arr[i] + arr[j] == x)
			{
				printf("Pair with a given sum %d is (%d %d)\r\n", x, arr[i], arr[j]);
				return 0;
			}
		}

	return -1;
}

int main()
{
	int arr[] = {0, -1, 2, -3, 1};
	int x = -2;
	int size = sizeof(arr)/sizeof(arr[0]);

	if(check_pair(arr, size, x))
		printf("No valid pair exists for %d\r\n", x);
	
	return 0;
}
