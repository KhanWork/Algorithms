#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int single_element(int *array, int n)
{
	int low = 0, high = n - 2;
	int mid;

	while(low <= high)
	{
		mid = (low + high)/2;
		if(array[mid] == array[mid ^1])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return array[low];
}
int main()
{
	int len;
	int array[] = {2, 3, 5, 4, 5, 3, 4};

	len = sizeof(array)/sizeof(array[0]);
	qsort(array, len, sizeof(int), cmp);

	printf("Single number: %d\r\n", single_element(array, len));

	return 0;
}
