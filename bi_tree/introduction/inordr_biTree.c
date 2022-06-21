#include <stdio.h>
#include <stdlib.h>

struct tree{
	int ele;
	struct tree *left, *right;
};

struct tree *create()
{
	int tEle;
	struct tree *tTree;

	tTree = (struct tree *)malloc(sizeof(struct tree));
	if(NULL == tTree)
	{
		printf("Failed to create a binary tree.\r\n");
		return NULL;
	}

	printf("Enter data to be inserted, -1 to quit: ");
	scanf("%d", &tEle);
	if(-1 == tEle)
		return 0;
	
	tTree->ele = tEle;
	
	printf("Enter left child of %d:\r\n", tEle);
	tTree->left = create();

	printf("Enter right child of %d:\r\n", tEle);
	tTree->right = create();

	return tTree;
}

void inorder(struct tree *root)
{
	if(NULL == root)
		return ;

	inorder(root->left);
	printf("%d ", root->ele);
	inorder(root->right);
}

int main()
{
	struct tree *root;
	
	root = create();

	inorder(root);

	printf("\r\n");
	return 0;
}
