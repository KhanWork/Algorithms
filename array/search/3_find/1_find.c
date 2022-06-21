#include <stdio.h>

int find_single(int *array, int size)
{
	int res = array[0];
	int i;
	for(i = 1; i < size; i++)
		res = res ^ array[i];

	return res;
}

int main()
{
	int array[] = {2, 3, 5, 4, 5, 3, 4};
	int n = sizeof(array)/sizeof(array[0]);

	printf("Element occurring once is: %d\r\n", find_single(array, n));

	return 0;
}
