#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct tree{
	int ele;
	struct tree *left, *right;
};

struct stack{
	int top;
	unsigned int capacity;
	struct tree **array;
};

static unsigned int nodeNum = 0;

struct stack *createStack(unsigned int capacity)
{
	struct stack *tStack;
	tStack = (struct stack *)malloc(sizeof(struct stack));
	tStack->capacity = capacity;
	tStack->top = -1;
	tStack->array = (struct tree **)malloc(tStack->capacity * sizeof(struct tree));

	return tStack;
}

int isStackFull(struct stack *tStack)
{
	return ((tStack->capacity - 1) == tStack->top);
}

int isStackEmpty(struct stack * tStack)
{
	return (-1 == tStack->top);
}

void push(struct stack *tStack, struct tree *tTree)
{
	if(isStackFull(tStack))
		return ;
	tStack->array[++tStack->top] = tTree;
}

struct tree* pop(struct stack *tStack)
{
	if(isStackEmpty(tStack))
		return NULL;
	return tStack->array[tStack->top--];
}

struct tree *createTree()
{
	int tEle;
	struct tree *tTree;

	tTree = (struct tree *)malloc(sizeof(struct tree));

	if(NULL == tTree)
	{
		printf("Failed to allocate space for tree.\r\n");
		return 0;
	}
	printf("Enter data to be inserted, -1 for nothing: ");
	scanf("%d", &tEle);

	if(-1 == tEle)
		return 0;

	tTree->ele = tEle;

	printf("Enter left child of %d: \r\n", tEle);
	tTree->left = createTree();

	printf("Enter right child of %d: \r\n", tEle);
	tTree->right = createTree();

	nodeNum++;

	return tTree;
}

void preorder(struct tree *root)
{
	if(NULL == root)
		return ;

	struct stack *treeStack;
	
	treeStack = createStack(nodeNum);

	while((NULL != root) || (!isStackEmpty(treeStack)))
	{
		if(NULL != root)
		{
			printf("%d ", root->ele);
			push(treeStack, root);
			root = root->left;
		}
		else
		{
			root = pop(treeStack);
			root = root->right;
		}
	}
	printf("\r\n");
}

int main()
{
	struct tree *root;
	root = createTree();

	preorder(root);

	return 0;
}
