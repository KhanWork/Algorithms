#include <stdio.h>

int find_element(int *array, int len, int key)
{
	int pos;
	for(pos = 0; pos < len; pos++)
		if(array[pos] == key)
			return pos;

	return -1;
}
int main()
{
	int array[] = {12, 34, 10, 6, 40};
	int len = sizeof(array)/sizeof(array[0]);

	int key = 40;
	int pos = find_element(array, len, key);

	if(-1 == pos)
		printf("element not found\r\n");
	else
		printf("element found at position: %d\r\n", pos + 1);

	return 0;
}
