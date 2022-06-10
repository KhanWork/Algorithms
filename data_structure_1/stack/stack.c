#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int count = 0;

struct stack{
	char items[MAX];
	int top;
};

typedef struct stack st;

void create_empty_stack(st *s)
{
	s->top = -1;
}

int isfull(st *s)
{
	return (s->top == MAX-1) ? 1 : 0;
}

int isempty(st *s)
{
	return (s->top == -1) ? 1 : 0;
}

void push(st *s, char newitem)
{
	if(isfull(s))
		printf("stack full\r\n");
	else
	{
		s->top++;
		s->items[s->top] = newitem;
	}
	
	count++;
}

void pop(st *s)
{
	if(isempty(s))
		printf("stack empty\r\n");
	else
	{
		printf("%c", s->items[s->top]);
		s->top--;
	}
}

void print_stack(st *s)
{
	int i;
	printf("Stack: ");
	for(i = 0; i < count; i++)
		printf("%c", s->items[i]);
	printf("\r\n");
}

int main()
{
	char ch;
	int i;

	st *s = (st *)malloc(sizeof(st));
	
	create_empty_stack(s);

	while((ch = getchar()) != '\n')
	{
		push(s, ch);
	}

	for(i = 0; i < count; i++)
	{
		pop(s);
	}

	printf("\r\n");
}
