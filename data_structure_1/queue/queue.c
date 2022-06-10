#include <stdio.h>

#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
	dequeue();

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	enqueue(6);
	
	display();

	dequeue();
	
	display();

	return 0;

}

void enqueue(int val)
{
	if(rear == (SIZE - 1))
		printf("queue is full!\r\n");
	else
	{
		if(front == -1)
			front = 0;
		rear++;
		queue[rear] = val;
		printf("inserted %d", val);
	}
}

void dequeue()
{
	if(front == -1)
		printf("queue is empty!\r\n");
	else
	{
		printf("dequeue: %d", queue[front]);
		front++;
		if(front > rear)
			front = rear = -1;
	}
}

void display()
{
	if(rear == -1)
		printf("queue is empty!");
	else
	{
		int i;
		printf("queue elements are:\r\n");
		for(i = front; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	printf("\r\n");
}
