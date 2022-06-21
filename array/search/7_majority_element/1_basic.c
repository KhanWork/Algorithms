#include <stdio.h>

void find_maj(int *arr, int size)
{
	int maxCount = 0;
	int index = -1;

	for(int i = 0; i < size; i++)
	{
		int count = 0;
		for(int j = 0; j < size; j++)
		{
			if(arr[i] == arr[j])
				count ++;
		}
		if(count > maxCount)
		{
			maxCount = count;
			index = i;
		}
	}

	if(maxCount > size/2)
		printf("Majority element: %d\r\n", arr[index]);
	else
		printf("No majority element.\r\n");
}

int main()
{
	int arr[] = {1, 1, 2, 1, 3, 5, 1};
	int size = sizeof(arr)/sizeof(arr[0]);

	find_maj(arr, size);

	return 0;
}
