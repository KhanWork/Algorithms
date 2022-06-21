#include <stdio.h>

int find_element(int *array, int len, int key)
{
	int i;
	for(i = 0; i < len; i++)
		if(array[i] == key)
			return i;

	return -1;
}

int del_element(int *array, int len, int key)
{
	int pos = find_element(array, len, key);
	if(-1 == pos)
	{
		printf("Element not found\r\n");
		return len;
	}

	int i;
	for(i = pos; i < len-1; i++)
		array[i] = array[i + 1];

	return len - 1;
}

int main()
{
	int i;
	int array[] = {10, 50, 30, 40, 20};

	int len = sizeof(array)/sizeof(array[0]);
	int key = 30;
	
	printf("Array before deletion:\r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);
	
	len = del_element(array, len, key);

	printf("\r\nArray after deletion\r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);
	
	printf("\r\n");

	return 0;
}
