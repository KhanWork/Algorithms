#include <stdio.h>

int bi_search(int *array, int low, int high, int key)
{
	if(high < low)
		return -1;
	int mid = (low + high)/2;
	
	if(key == array[mid])
		return mid;
	if(key > array[mid])
		return bi_search(array, (mid + 1), high, key);

	return bi_search(array, low, (mid - 1), key);
}

int main()
{
	int array[] = {5, 6, 7, 8, 9, 10};
	int len, key;
	len = sizeof(array)/sizeof(array[0]);
	key = 10;

	printf("Index: %d\r\n", bi_search(array, 0, len - 1, key));

	return 0;
}
