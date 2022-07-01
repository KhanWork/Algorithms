#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int ele;
    struct node *prev;
    struct node *next;
};

struct node *createList(int val)
{
    struct node *tNode;
    tNode = (struct node *)malloc(sizeof(struct node));
    if(NULL == tNode)
    {
        printf("Failed to allocate space\r\n");
        return NULL;
    }

    tNode->ele = val;
    tNode->next = tNode;
    tNode->prev = tNode;

    return tNode;
}

bool isEmpty(struct node *funNode)
{
    return (funNode == NULL)? true : false;
}

struct node *findPosition(struct node*funNode, int val)
{
    struct node *orzNode;

    orzNode = funNode;
    do{
        if(funNode->ele == val)
            return funNode;
        funNode = funNode->next;
    }while(orzNode != funNode);

    return NULL;
}

void deleteNode(struct node **funNode, int val)
{
    struct node *preNode;
    struct node *curNode;

    curNode = findPosition(*funNode, val);
    preNode = curNode->prev;

    if(curNode && (preNode != curNode))
    {
        preNode->next = curNode->next;
        curNode->next->prev = preNode;
        *funNode = preNode;
        free(curNode);
        return ;
    }
    else if(curNode)
    {
        *funNode = NULL;
        free(curNode);

        return ;
    }
    else
        return ;
}

void insertNode(struct node *funNode, int orz, int val)
{
    struct node *curNode;
    
    curNode = findPosition(funNode, orz);
    if(curNode == NULL)
    {
        return ;
    }
    else
    {
        struct node *inNode;
        inNode = (struct node *)malloc(sizeof(struct node));
        inNode->ele = val;
        curNode->prev->next = inNode;
        inNode->next = curNode;
        inNode->prev = curNode->prev;
        curNode->prev = inNode;
    }

    return ;
}

void *deleteList(struct node **funNode)
{
    struct node *curNode;
    curNode = *funNode;
    while(*funNode)
    {
        curNode = (*funNode)->next;
        deleteNode(funNode, (*funNode)->ele);
        if(*funNode != NULL)
            *funNode = curNode;
        else
            return NULL;
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
    //deleteNode(&list, 10);
    //printList(list);
    //deleteNode(&list, 35);
    //printList(list);
    //deleteNode(&list, 20);
    //printList(list);
    printf("delete Node complete\r\n");

    list = (struct node *)deleteList(&list);
    printf("deleteList complete\r\n");
    if(isEmpty(list))
        printf("list is empty\r\n");
    else
        printf("list is not empty\r\n");

    
    if(!isEmpty(list))
       printList(list);

    return 0;
}