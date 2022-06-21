#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
//qsort(array, len, sizeof(int), cmp);
bool maj_element(int *arr, int size)
{
	if(size == 1) return arr[0];
	int cnt = 1;
	int i;
	qsort(arr, size, sizeof(int), cmp);

	for(i = 1; i < size; i++)
	{
		if(arr[i - 1] == arr[i])
			cnt++;
		else
		{
			if(cnt > (size/2))
				return arr[i - 1];
			cnt = 1;
		}
	}

	return false;
}

int main()
{
	int arr[] = {1, 1, 2, 1, 3, 5, 1};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("Majority element: %d\r\n", maj_element(arr, size));

	return 0;
}
