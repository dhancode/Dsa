#include<stdio.h>
#include<stdlib.h>

struct node *f=NULL;
struct node*r=NULL;
struct node 
{
    int data;
    struct node *next;
};
int linkedListTraversal(struct node *ptr)
{
    printf("the elements in the queue are\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("queue is overflow\n");
    }
    else
    {
        n->data=val;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
    }
}
int dequeue()
{
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
    {
        printf("the queue is underflow\n");
    }
    else
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    enqueue(34);
    enqueue(12);
    enqueue(14);
    enqueue(4);
    linkedListTraversal(f);
    printf("the dequeued element is %d\n",dequeue());
    printf("the dequeued element is %d\n",dequeue());
    printf("the dequeued element is %d\n",dequeue());
    printf("the dequeued element is %d\n",dequeue());
    printf("the dequeued element is %d\n",dequeue());

}