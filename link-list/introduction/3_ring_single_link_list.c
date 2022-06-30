#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int ele;
    struct node *next;
};

struct node *createList(int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == newNode)
    {
        printf("Create list failed\r\n");
        return NULL;
    }

    newNode->ele = val;
    newNode->next = newNode;

    return newNode;
}

bool isEmpty(struct node *fnode)
{
    if(fnode == NULL)
        return true;
    else
        return false;
}

struct node *findPosition(struct node *fnode, int val)
{
    struct node *tNode;
    tNode = fnode;

    do
    {
        if(tNode->ele == val)
            return tNode;
        tNode = tNode->next;
    }while(tNode != fnode);

    return NULL;
}

struct node *findPrevious(struct node *fnode, int val)
{
    struct node *tNode;
    struct node *pNode;
    tNode = fnode->next;
    pNode = fnode;

    do
    {
        if(tNode->ele == val)
            return pNode;
        tNode = tNode->next;
        pNode = pNode->next;
    }while(pNode != fnode);

    return NULL;
}

void deleteNode(struct node **fnode, int val)
{
    struct node *preNode;
    struct node *curNode;

    preNode = findPrevious(*fnode, val);
    curNode = findPosition(*fnode, val);

    if(preNode && curNode && (preNode != curNode))
    {
        preNode->next = curNode->next;
        free(curNode);
        return ;
    }
    else if(curNode)
    {
        *fnode = curNode->next;
        free(curNode);
        return ;
    }
    else
    {
        printf("No valid node found\r\n");
        return ;
    }
}

void insertNode(struct node *fnode, int orz, int val)
{
    struct node *pNode;

    pNode = findPrevious(fnode, orz);

    if(pNode == NULL)
    {
        printf("Can not find node to be insert\r\n");
        return ;
    }
    else
    {
        struct node *inNode;
        inNode = (struct node *)malloc(sizeof(struct node));
        inNode->ele = val;
        inNode->next = pNode->next;
        pNode->next = inNode;
    }

    return ;
}

void *deleteList(struct node **fnode)
{
    struct node *curNode;
    curNode = *fnode;
    int i = 0;
    while(*fnode)
    {
        curNode = (*fnode)->next;
        deleteNode(fnode, (*fnode)->ele);
        *fnode = curNode;
        if(i)
            return NULL;
        if((*fnode)->next == *fnode && i == 0)
            i++;
    }
    return NULL;
}

void printList(struct node *fnode)
{
    if(isEmpty(fnode))
        return ;
    struct node *tNode;
    tNode = fnode;
    do
    {
        printf("%d ", tNode->ele);
        tNode = tNode->next;
    }while(tNode != fnode);

    printf("\r\n");

    return ;
}

int main()
{
    struct node *list;
    list = createList(10);
    if(isEmpty(list))
        printf("list is empty\r\n");
    else
        printf("list is not empty\r\n");

    insertNode(list, 10, 20);
    insertNode(list, 10, 15);
    insertNode(list, 15, 35);
    insertNode(list, 20, 23);
    insertNode(list, 20, 33);

    printList(list);
    deleteNode(&list, 33);
    printList(list);
    deleteNode(&list, 15);
    printList(list);
    printf("delete Node complete\r\n");

    list = (struct node *)deleteList(&list);
    if(isEmpty(list))
        printf("list is empty\r\n");
    else
        printf("list is not empty\r\n");

    
    if(!isEmpty(list))
       printList(list);

    return 0;
}
