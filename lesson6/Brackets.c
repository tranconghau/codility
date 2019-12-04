// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>

typedef enum
{
    FALSE,
    TRUE
} cBool;

#define byte char

typedef struct cStack
{
    int top;
    unsigned capacity;
    byte *data;
} Stack;


Stack *initStack(unsigned int capInByte)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capInByte;
    stack->data = (char *)malloc(capInByte);
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


void push(Stack *s, char val)
{
    if(!isFull(s))
        s->data[++s->top] = val;
}

void pop(Stack *s)
{
    if(!isEmpty(s))
        s->top--;
}

char top(Stack *s)
{
    if(!isEmpty(s))
        return s->data[s->top];
    
    return NULL;
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
    return ++s->top;
}

int solution(char *S) {
    //count N
    int i = 0, N = 0, stackSize = 0;
    char c;
    while(S[i] != '\0')
    {
       i++;
    }
    N = i;
    
    if(N == 0)
        return 1;
    else if(N % 2 != 0)
        return 0;
    
    //create stack
    Stack* stack = initStack(N/2);
    
    for(i = 0; i < N; i++)
    {
        if(S[i] == '{' || S[i] == '[' || S[i] == '(')
        {
            push(stack, S[i]);
        }
        else
        {
            c = top(stack);
            pop(stack);
            
            switch(S[i])
            {
                case '}':
                    if('{' != c)
                    {
                        clean(stack);
                        return 0;
                    }
                    break;
                case ']':
                    if('[' != c)
                    {
                        clean(stack);
                        return 0;
                    }
                    break;
                case ')':
                    if('(' != c)
                    {
                        clean(stack);
                        return 0;
                    }
                    break;
                default:
                    break;
            }
            
        }
    }
    
    stackSize = size(stack);
    clean(stack);
    if(i == N && stackSize == 0)
        return 1;
    return 0;
}
