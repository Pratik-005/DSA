#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};


int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr)
{   
    return ptr->arr[ptr->top];
}


int main()
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 5;
    stk->top = -1;
    stk->arr = (int *)malloc(stk->size * sizeof(int));

    push(stk, 5);
    push(stk, 5);
    push(stk, 5);
    push(stk, 5);
    push(stk, 5);
    printf("%d", peek(stk));

    return 0;
}


