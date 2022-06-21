#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct tree{
	int ele;
	struct tree *left, *right;
};

struct queue{
	int front, rear, size;
	unsigned int capacity;
	struct tree **array;
};

static unsigned int nodeNum = 0;

struct stack{
	int top;
	unsigned int capacity;
	int *array;
};

struct stack *createStack(unsigned int capacity)
{
	struct stack *tStack;
	tStack = (struct stack *)malloc(sizeof(struct stack));
	tStack->capacity = capacity;
	tStack->top = -1;
	tStack->array = (int *)malloc(tStack->capacity * sizeof(int));

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

void push(struct stack *tStack, int tData)
{
	if(isStackFull(tStack))
		return ;
	tStack->array[++tStack->top] = tData;
}

int pop(struct stack *tStack)
{
	if(isStackEmpty(tStack))
		return 0;
	return tStack->array[tStack->top--];
}

int top(struct stack *tStack)
{
	if(isStackEmpty(tStack))
		return 0;
	return tStack->array[tStack->top];
}

struct queue *createQueue(unsigned int capacity)
{
	struct queue *tQueue;
	tQueue = (struct queue *)malloc(sizeof(struct queue));

	tQueue->capacity = capacity;
	tQueue->front = tQueue->size = 0;
	tQueue->rear = capacity - 1;
	tQueue->array = (struct tree **)malloc(tQueue->capacity * sizeof(struct tree));

	return tQueue;
}

int isQueueFull(struct queue *tQueue)
{
	return (tQueue->size == tQueue->capacity);
}

int isQueueEmpty(struct queue *tQueue)
{
	return (tQueue->size == 0);
}

void enQueue(struct queue *tQueue, struct tree *tTree)
{
	if(isQueueFull(tQueue))
		return;

	tQueue->rear = (tQueue->rear + 1) % tQueue->capacity;
	tQueue->array[tQueue->rear] = tTree;
	tQueue->size = tQueue->size + 1;
}

struct tree *deQueue(struct queue *tQueue)
{
	if(isQueueEmpty(tQueue))
		return NULL;
	struct tree *tTree;
	tTree = tQueue->array[tQueue->front];
	tQueue->front = (tQueue->front + 1) % tQueue->capacity;
	tQueue->size = tQueue->size - 1;

	return tTree;
}

struct tree *front(struct queue *tQueue)
{
	if(isQueueEmpty(tQueue))
		return NULL;

	return tQueue->array[tQueue->front];
}

struct tree *rear(struct queue *tQueue)
{
	if(isQueueEmpty(tQueue))
		return NULL;
	
	return tQueue->array[tQueue->rear];
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

void reverseTree(struct tree *root)
{
	if(NULL == root)
		return;

	struct queue *treeQueue;
	struct stack *treeStack;
	treeQueue = createQueue(nodeNum);
	treeStack = createStack(nodeNum);
	struct tree *tTree;
	enQueue(treeQueue,root);

	while(!(isQueueEmpty(treeQueue)))
	{
		tTree = front(treeQueue);
		deQueue(treeQueue);

		push(treeStack, tTree->ele);
		if(tTree->left)
			enQueue(treeQueue, tTree->left);
		if(tTree->right)
			enQueue(treeQueue, tTree->right);
	}

	while(!isStackEmpty(treeStack))
	{
		printf("%d ", top(treeStack));
		pop(treeStack);
	}

	printf("\r\n");
}

int main()
{
	struct tree *root;
    int searchEle;
	root = createTree();

	printf("Reversed tree is: \r\n");

	reverseTree(root);

	return 0;
}
