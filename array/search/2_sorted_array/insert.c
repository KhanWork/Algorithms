#include <stdio.h>

int in_sorted(int *array, int len, int key, int capacity)
{
	if(len >= capacity)
		return len;

	int i;
	for(i = len - 1; (i >= 0 && array[i] > key); i--)
		array[i + 1] = array[i];
	array[i + 1] = key;

	return (len + 1);
}

int main()
{
	int array[20] = {12, 16, 20, 40, 50, 70};
	int capacity = sizeof(array)/sizeof(array[0]);
	int len = 6;
	int i, key = 26;
	printf("Before insertion: \r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);

	len = in_sorted(array, len, key, capacity);
	printf("\r\nAfter insertion: \r\n");
	for(i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\r\n");

	return 0;
}
