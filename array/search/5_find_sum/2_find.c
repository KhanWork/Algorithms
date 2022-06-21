#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

bool has_candidates(int arr[], int size, int sum)
{
	int left, right;

	qsort(arr, size, sizeof(int), cmp);
	
	left = 0;
	right = size - 1;

	while(left < right)
	{
		if(arr[left] + arr[right] == sum)
			return true;
		else if(arr[left] + arr[right] < sum)
			left++;
		else
			right--;
	}
	return 0;
}

int main()
{
	int arr[] = {1, 4, 45, 6, 10, -8};
	int sum = 16;
	int size = 6;

	if(has_candidates(arr, size, sum))
		printf("Array has two elements with given sum\r\n");
	else
		printf("Array doesn't have two elements with given sum\r\n");

	return 0;
}
