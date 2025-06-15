#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *sp,char val)
{
    if(isFull(sp))
    {
        printf("Stack overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=val;
    }
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack underflow\n");
    }
    else
    {
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesis(char *exp)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=10;
    sp->arr=(char*)malloc(sizeof(char)*sp->size);

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(sp,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp))
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
    char *exp="(1+2)+(2+3)";
    if(parenthesis(exp))
    {
        printf("It is balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }
}