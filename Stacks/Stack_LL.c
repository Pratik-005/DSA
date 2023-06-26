#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

int isFull()
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traversal(struct stack *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct stack *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack **top, int val)
{
    if (isFull())
    {
        printf("stack overflow");
    }
    else
    {
        struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
        ptr->data = val;
        ptr->next = (*top);
        *top = ptr;
    }
}

int pop(struct stack **top)
{
    if (isEmpty(*top))
    {
        printf("stack underflow");
    }
    else
    {
        int val = (*top)->data;
        struct stack *ptr = *top;
        *top = (*top)->next;
        free(ptr);
        return val;
    }
}

int peek(struct stack *top)
{
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int main()
{

    struct stack *top = NULL;
    push(&top, 5);

    printf("%d", peek(top));

    return 0;
}
