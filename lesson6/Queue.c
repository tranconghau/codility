#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE,
	TRUE
}bool;

typedef struct Queue
{
	int top;
	int tail;
	unsigned capacity;
	unsigned size;
	int* data;
}Queue;


Queue* init(unsigned cap)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));

	q->top = -1;
	q->tail = -1;
	q->capacity = cap;
	q->size = 0;
	q->data = (int*)malloc(sizeof(int));
	return q;
}

bool isEmpty(Queue *q)
{
	return q->size == 0;
}

//need to rotate the queue
int isFull(Queue *q)
{
	return q->size == q->capacity;
}

void push(Queue* q, int val)
{
	if (!isFull(q))
	{
		if (isEmpty(q))
			q->top = 0;

		q->data[++q->tail % q->capacity] = val;
		q->size++;
	}
}

int top(Queue* q)
{
	if (!isEmpty(q))
		return q->data[q->top];
}

void pop(Queue* q)
{
	if (!isEmpty(q))
	{
		if (q->size == 1)
		{
			q->top = -1;
			q->tail = -1;
		}
		else
			q->top = ++q->top % q->capacity;
		
		q->size--;
	}
}

int main(int argc, char const *argv[])
{
	Queue *q = init(10);

	push(q,5);
	push(q,10);
	push(q,5);
	push(q,10);
	push(q,5);
	push(q,10);
	push(q,5);
	push(q,10);
	push(q,5);
	push(q,10);

	pop(q);

	push(q,1000);
	pop(q);pop(q);pop(q);pop(q);pop(q);pop(q);pop(q);pop(q);pop(q);

	printf("%d\n", top(q));

	return 0;
}