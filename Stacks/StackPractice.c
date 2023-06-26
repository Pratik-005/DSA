// // stack implementation using arrays

// #include <stdio.h>
// #include <stdlib.h>

// struct stack
// {
//     int top;
//     int size;
//     int *arr;
// };

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int peek(struct stack *ptr)
// {
//     if (ptr->top != -1)
//     {
//         return ptr->arr[ptr->top];
//     }
//     else
//     {
//         return -1;
//     }
// }

// void push(struct stack *ptr, int val)
// {
//     if (isFull(ptr))
//     {
//         printf("stack overflow");
//     }
//     else
//     {
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }

// int pop(struct stack *ptr)
// {
//     if (isEmpty(ptr))
//     {
//         printf("stack underflow");
//         return -1;
//     }
//     else
//     {
//         int val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }

// int main()
// {
//     struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
//     stk->top = -1;
//     stk->size = 5;
//     stk->arr = (int *)malloc(stk->size * sizeof(int));

//     pop(stk);
//     printf("%d", peek(stk));

//     return 0;
// }

// linked list imoplementation of stacks

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

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

void push(struct stack **top,int val){
    if(isFull()){
        printf("stack overflow");
    }else{
        struct stack* ptr = (struct stack*)malloc(sizeof(struct stack));
        ptr->data = val ;
        ptr->next = *top;
        *top = ptr ;
    }
}

int pop(struct stack **top){
    if(isEmpty(*top)){
        printf("stack underflow");
        return -1 ;
    }else{
        int val = (*top)->data ;
        struct stack* ptr = *top;
        *top = (*top)->next;
        free(ptr);
        return val ;
    }
}

int peek(struct stack *top)
{
    if(top!=NULL){
        return top->data;
    }else{
        return -1 ;
    }
}

void traversal(struct stack* ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
}


int main()
{
    struct stack *top = NULL;
    traversal(top);

    return 0;
}