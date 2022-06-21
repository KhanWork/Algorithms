#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a > b)?a:b

struct node{
	int key;
	int c;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node * temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->c = 1;
	temp->left = temp->right = NULL;

	return temp;
}

struct node *insert(struct node *node, int key, int *ma)
{
	if(node == NULL)
	{
		if(*ma == 0)
			*ma = 1;

		return newNode(key);
	}

	if(key < node->key)
		node->left = insert(node->left, key, ma);
	else if(key > node->key)
		node->right = insert(node->right, key, ma);
	else
		node->c++;

	*ma = max(*ma, node->c);

	return node;
}
/* 中序遍历 */
void inorder(struct node *root, int s)
{
	if(root != NULL)
	{
		inorder(root->left, s);

		//if(root->c > (s/2))
			printf("%d \n", root->key);

		inorder(root->right, s);
	}
}

int main()
{
	int arr[] = {1, 3, 3, 3, 2, 3, 5, 3, 8, 10, 3, 3, 3, 7};
	int size = sizeof(arr)/sizeof(arr[0]);

	struct node *root = NULL;
	int ma = 0;
	for(int i = 0; i < size; i++)
	{
		root = insert(root, arr[i], &ma);
	}
	
	if(ma > (size/2))
		inorder(root, size);
	else
		printf("No majority element\r\n");

	return 0;
}
