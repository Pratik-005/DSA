#include <stdio.h>
#include <stdlib.h>

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

int isMatched(char a ,char b){
    if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']') return 1;
    return 0;
}

int isValidParenthesis(char *infix)
{
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
    stk->size = 100;
    stk->top = -1;
    stk->arr = (char *)malloc((stk->size) * sizeof(char));

    char popped_char;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            push(stk, infix[i]);
        }
        else
        {
            if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
            {
                if (isEmpty(stk))
                {
                    return 0;
                }

                popped_char = pop(stk);

                if (!isMatched(popped_char,infix[i])){
                    return 0 ;
                }

            }
        }
    }

    if (isEmpty(stk))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *ptr = "[[{{{(({{{[[]]}}}))}}}]]";
    if (isValidParenthesis(ptr))
    {
        printf("Valid Expression");
    }
    else
    {
        printf("invalid expression");
    }
    return 0;
}
