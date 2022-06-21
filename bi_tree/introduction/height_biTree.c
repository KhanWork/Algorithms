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

int height(struct tree *root)
{
    int x, y;

    if(NULL != root)
    {
        x = height(root->left);
        y = height(root->right);

        if(x > y)
            return x + 1;
        else
            return y + 1;
    }

    return 0;
}

int main()
{
	struct tree *root;
	root = create();

    printf("Height of tree is: %d\r\n", height(root));

	return 0;
}
