#include <stdio.h>

int insert_unsorted(int *array, int pos, int key, int capacity)
{
	if(pos >= capacity)
		return pos;

	array[pos] = key;

	return (pos + 1);
}

int main()
{
	int array[20] = {12, 16, 20, 40, 50, 70};
	int capacity = sizeof(array)/sizeof(array[0]);
	int pos = 6;
	int i;
	int key = 26;

	printf("Before insertion:\r\n");
	for(i = 0; i < pos; i++)
		printf("%d ", array[i]);

	pos = insert_unsorted(array, pos, key, capacity);
	printf("\r\nAfter insertion:\r\n");
	for(i = 0; i < pos; i++)
		printf("%d ", array[i]);
	printf("\r\n");
}
