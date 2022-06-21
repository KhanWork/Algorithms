#include <stdio.h>

void print_pairs(int *arr, int n, int x)
{
	int i;
	int rem[x];

	for(i = 0; i < x; i++)
		rem[i] = 0;

	for(i = 1; i < n; i++)
		if(arr[i] < x)
			rem[arr[i] %x]++;

	for(i = 1; i < x/2; i++)
	{
		if(rem[i] > 0 && rem[x - i] > 0)
		{
			printf("yes\r\n");
			break;
		}
	}

	if(i >= x/2)
	{
		if(x % 2 == 0)
		{
			if(rem[x/2] > 1)
				printf("yes\r\n");
			else
				printf("no\r\n");
		}
		else
		{
			if(rem[x/2] > 0 && rem[x - x/2] > 0)
				printf("yes\r\n");
			else
				printf("no\r\n");
		}
	}
}

int main()
{
	int arr[] = {1, 4, 45, 6, 10, 8};
	int n = 16;
	int size = sizeof(arr)/sizeof(arr[0]);

	print_pairs(arr, size, n);

	return 0;
}
