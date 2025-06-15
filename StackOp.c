#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("the pushed element is %d\n",val);
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
int pop(struct stack *ptr)
{   
    if(isEmpty(ptr))
    {
        printf("stack underflow\n");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}
int main()
{
    struct stack *s;
    s->top=-1;
    s->size=100;
    s->arr=(int *)malloc(s->size*sizeof(int));
    push(s,12);
    push(s,13);
    push(s,10);
    printf("the popped element is %d\n",pop(s));
    printf("the popped element is %d\n",pop(s));
    printf("the popped element is %d\n",pop(s));
    printf("the popped element is %d\n",pop(s));
    
}