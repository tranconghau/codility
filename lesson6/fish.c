#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE,
    TRUE
} cBool;

typedef struct cStack
{
    int top;
    unsigned capacity;
    int *data;
} Stack;


Stack *initStack(unsigned int capInByte)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capInByte;
    stack->data = (int *)malloc(sizeof(int)*capInByte);
    return stack;
}

cBool isEmpty(Stack *s)
{
    return (cBool)(s->top == -1);
}


cBool isFull(Stack *s)
{
    return (cBool)(s->top == s->capacity - 1);
}


void push(Stack *s, int val)
{
    if(!isFull(s))
        s->data[++s->top] = val;
}

void pop(Stack *s)
{
    if(!isEmpty(s))
        s->top--;
}

int top(Stack *s)
{
    if(!isEmpty(s))
        return s->data[s->top];
    
    return -1;
}

void clean(Stack *s)
{
    free(s->data);
    s->data = NULL;
    free(s);
    s = NULL;
}

int size(Stack *s)
{
    return (s->top + 1);
}

/*
0 represents a fish flowing upstream,
1 represents a fish flowing downstream.

A[0] = 4    B[0] = 0
A[1] = 3    B[1] = 1
A[2] = 2    B[2] = 0
A[3] = 1    B[3] = 0
A[4] = 5    B[4] = 0
*/
#define UP   0
#define DOWN 1
int solution(int A[], int B[], int N)
{
	Stack *fish = initStack(N);
	int res = 0;
	int i = 0;

	push(fish, 0);
	int direction = B[0];
	int tmp;

	for (i = 1; i < N; ++i)
	{
		if (direction == B[i])
		{
			push(fish, i);
		}
		else
		{
			if (direction == UP)
			{
				push(fish, i);
				//printf("a %d\n", i);
				direction = B[i];
				continue;
			}
			while((tmp = top(fish)) != -1 && direction != B[i] && A[i] > A[tmp])
			{
				pop(fish);
				//printf("pop %d - %d\n", i, size(fish));
				if(size(fish) > 0)
					direction = B[top(fish)];
			}
			if (size(fish) == 0 || direction == B[i])
			{	
				push(fish, i);
				//printf("b %d\n", i);
			}
		}
	}

	res = size(fish);

	clean(fish);
	return res;
}

int main(int argc, char const *argv[])
{
	//int A[] = {4,3,2,1,5,6};
	//int B[] = {0,1,0,0,0,1};


	int A [] = {6,1,2,3,4,5,0,10};
	int B[] = {0,0,0,0,0,0,1,0};


	int res = 0;

	res = solution(A, B, 8);

	printf("%d\n", res);

	return 0;
}