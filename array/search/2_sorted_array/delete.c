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

int del_element(int *array, int len, int key)
{
	int pos = bi_search(array, 0, len - 1, key);
	
	if(-1 == pos)
	{
		printf("Element not found\r\n");
		return len;
	}

	int i;
	for(i = pos; i < len - 1; i++)
		array[i] = array[i + 1];

	return len - 1;
}

int main()
{
	int i;
	int array[] = {10, 20, 30, 40, 50};

	int len = sizeof(array)/sizeof(array[0]);
	int key = 30;
	printf("Array before deletion\r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);

	len = del_element(array, len, key);
	printf("\r\nArray after deletion\r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);

	printf("\r\n");

	return 0;
}
