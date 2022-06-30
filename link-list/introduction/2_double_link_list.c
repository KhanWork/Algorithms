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
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(newNode));
    if(NULL == newNode)
    {
        printf("Create link list failed\r\n");
        return NULL;
    }

    newNode->ele = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct node *makeEmpty(struct node *head)
{
    return NULL;
}

bool isEmpty(struct node *head)
{
    return (NULL == head);
}

bool isLast(struct node *tNode)
{
    if(isEmpty(tNode))
    {
        return false;
    }
    return (NULL == tNode->next);
}

struct node *findPosition(struct node *head, int val)
{
    if(isEmpty(head))
    {
        return NULL;
    }

    if(head->ele == val)
        return head;
    
    struct node *temp;
    temp = head;
    while(temp->next)
    {
        if(temp->ele == val)
            return temp;
        temp = temp->next;
    }

    if(temp->ele == val)
        return temp;

    return NULL;
}

void deleteNode(struct node **head, int val)
{
    struct node *preNode;
    struct node *curNode;

    curNode = findPosition(*head, val);
    preNode = curNode->prev;

    if(preNode && curNode)
    {
        preNode->next = curNode->next;
        curNode->next->prev = preNode;
        free(curNode);
        return ;
    }
    else if(curNode)
    {
        *head = curNode->next;
        curNode->next->prev = *head;
        free(curNode);
        return ;
    }
    else
    {
        printf("No valid node found\r\n");
        return ;
    }
}

struct node *insertNode(struct node *head, int val, int pos)
{
    if(isEmpty(head))
        return NULL;

    struct node *cur;
    struct node *pre;
    cur = findPosition(head, pos);
    pre = cur->prev;
    if(pre && cur)
    {
        struct node *insertNode;
        insertNode = (struct node *)malloc(sizeof(struct node));
        insertNode->ele = val;
        pre->next = insertNode;
        insertNode->prev = pre;
        insertNode->next = cur;
        cur->prev = insertNode;
        return head;
    }
    if(!cur)
    {
        printf("Current list do not have this val\r\n");
        return head;
    }

    struct node *insertNode;
    insertNode = (struct node *)malloc(sizeof(struct node));
    insertNode->ele = val;
    insertNode->next = cur;
    cur->prev = insertNode;
    insertNode->prev = NULL;

    return insertNode;
}

void *deleteList(struct node *head)
{
    struct node *tempNode;
    while(head->next)
    {
        tempNode = head;
        head = head->next;
        free(tempNode);
    }
    free(head);

    return NULL;
}

void printList(struct node *head)
{
    while(head->next)
    {
        printf("%d ", head->ele);
        head = head->next;
    }
    printf("%d\r\n", head->ele);

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

    if(!isEmpty(list))
    {
        if(isLast(list))
            printf("This is last node\r\n");
        else
            printf("This is not last node\r\n");
    }
    
    list = insertNode(list, 20, 10);
    list = insertNode(list, 15, 10);
    list = insertNode(list, 35, 15);
    list = insertNode(list, 23, 20);
    list = insertNode(list, 33, 20);

    printList(list);
    deleteNode(&list, 33);
    printList(list);
    deleteNode(&list, 23);
    printList(list);

    list = (struct node *)deleteList(list);
    if(isEmpty(list))
        printf("list is empty\r\n");
    else
        printf("list is not empty\r\n");

    if(!isEmpty(list))
    {
        if(isLast(list))
            printf("This is last node\r\n");
        else
            printf("This is not last node\r\n");
    }

    
    if(!isEmpty(list))
       printList(list);

    return 0;
}