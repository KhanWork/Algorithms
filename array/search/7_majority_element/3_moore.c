#include <stdio.h>
#include <stdbool.h>

bool is_maj(int *arr, int size, int cand)
{
	int i, count = 0;
	for(i = 0; i < size; i++)
		if(arr[i] == cand)
			count++;
	if(count > (size/2))
		return true;
	else
		return false;
}

int find_candidate(int *arr, int size)
{
	int majIndex = 0, count = 1;
	int i;
	for(i = 1; i < size; i++)
	{
		if(arr[majIndex] == arr[i])
			count++;
		else
			count--;
		if(count == 0)
		{
			majIndex = i;
			count = 1;
		}
	}

	return arr[majIndex];
}

void print_maj(int *arr, int size)
{
	int cand = find_candidate(arr, size);

	if(is_maj(arr, size, cand))
		printf(" %d ", cand);
	else
		printf("No majority element");

	printf("\r\n");
}

int main()
{
	int arr[] = {1, 3, 3, 3, 2};
	int size = sizeof(arr)/sizeof(arr[0]);

	print_maj(arr, size);

	return 0;
}
