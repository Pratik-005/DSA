#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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


int isOperator(char a){
    if(a=='*' || a=='/' || a=='+' || a=='-'){
        return 1;
    }else{
        return 0;
    }
}

int precedence(char a){
    if(a=='/' || a =='*'){
        return 3 ;
    }else if(a=='+' || a =='-'){
        return 2;
        }else{
    return 1 ;
        }

    
}

char* infixToPostfix(char* infix){
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 10;
    stk->top = -1;
    stk->arr = (char *)malloc((stk->size) * sizeof(char));

    char* postfix = (char *)malloc(strlen(infix+1) * sizeof(char));

    int i=0 ;
    int j= 0;

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
           postfix[j] = infix[i];
           i++;
           j++;
        }else{
            if(precedence(infix[i]) > precedence(stk->arr[stk->top])){
                push(stk,infix[i]);
                i++;
            }else{
                postfix[j] = pop(stk);
                j++;
            }
           
        }
    }

    while(!isEmpty(stk)){
        postfix[j]=pop(stk);
        j++;
    }

    postfix[j]='\0';
    return postfix ;
}


int main()
{
    char *ptr = "a+c";
    printf(infixToPostfix(ptr));
    return 0;
},

