#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int isOperator(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/')
    {
        return 1;
    }
    return 0;
}
int precendence(char a)
{
    if(a=='*'||a=='/')
    {
        return 3;
    }
    else if(a=='+'||a=='-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
void push(struct stack *sp,char val)
{
    if(isFull(sp))
    {
        printf("stack is oveflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=val;
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack undeflow\n");
    }
    else
    {
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
char * inToPo(char * Infix)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=10;
    s->arr=(char*)malloc(s->size*sizeof(char));
    char * Postfix=(char *)malloc((strlen(Infix)+1) * sizeof(char));
    int i=0;
    int j=0;
    while(Infix[i]!='\0')
    {
        if(!isOperator(Infix[i]))
        {
            Postfix[j]=Infix[i];
            i++;
            j++;
        }
        else
        {
            if(precendence(Infix[i])>precendence(stackTop(s)))
            {
                push(s,Infix[i]);
                i++;
            }
            else
            {
                Postfix[j]=pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s))
    {
        Postfix[j]=pop(s);
        j++;
    }
    Postfix[j]='\0';
    return Postfix;
}
int main()
{
    char * infix="x-y/z-k*d";
    printf("the postfix expression is %s",inToPo(infix));
    return 0;
}