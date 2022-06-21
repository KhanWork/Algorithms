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

int deepest(struct tree *root)
{
    if(NULL == root)
        return 0;

    struct queue *treeQueue;
    treeQueue = createQueue(nodeNum);

    enQueue(treeQueue, root);
    while(!isQueueEmpty(treeQueue))
    {
        root = front(treeQueue);
        deQueue(treeQueue);

        if(root->left)
            enQueue(treeQueue, root->left);
        if(root->right)
            enQueue(treeQueue, root->right);
    }

    return (root->ele);
}

int main()
{
	struct tree *root;
    int searchEle;
	root = createTree();

    printf("Deepest node of tree is: %d\r\n", deepest(root));

	return 0;
}
