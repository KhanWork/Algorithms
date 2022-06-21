#include <stdio.h>

#define MAX 100000
/*  */
void print_pairs(int arr[], int size, int target)
{
	int i, temp;
	int s[MAX] = {0};

	for(i = 0; i < size; i++)
	{
		temp = target - arr[i];
		if(s[temp] == 1)
			printf("Pair with given sum %d is (%d, %d)\r\n", target, arr[i], temp);

		s[arr[i]] = 1;
	}
}

int main()
{
	int arr[] = {1, 4, 45, 6, 10, 8};
	int target = 16;
	int size = sizeof(arr)/sizeof(arr[0]);

	print_pairs(arr, size, target);

	return 0;
}
