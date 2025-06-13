#include<stdio.h>
#include<stdlib.h>
struct DEqueue
{
    int f;
    int r;
    int *arr;
    int size;
};
int isFull(struct DEqueue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}
void enqueuef(struct DEqueue *q,int val)
{
    if (isFull(q))
    {
        printf("queue overflow\n");
    }
    else if(q->f==-1)
    {
        printf("the element cannot be entered\n");
    }
    else
    {
        q->arr[q->f]==val;
        q->f--;
        printf("the value entered is %d\n",val);
    }
}
void enqueuer(struct DEqueue *q,int val)
{
    if(isFull(q))
    {
        printf("queue overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("the value entered is %d\n",val);
    }
}
int isEmpty(struct DEqueue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}
int dequeuef(struct DEqueue *q)
{
    int val=-1;
    if(isEmpty(q))
    {
        printf("queue underflow\n");
    }
    else
    {
        q->f++;
        val=q->arr[q->f];
    }
    return val;
}
int dequeuer(struct DEqueue *q)
{
    int val=-1;
    if(isEmpty(q))
    {
        printf("queue is in underflow");
    }
    else
    {
        val=q->arr[q->r];
        q->r--;
    }
    return val;
}
int main()
{
    struct DEqueue q;
    q.f=-1;
    q.r=-1;
    q.size=4;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueuer(&q,15);
    enqueuer(&q,14);
    enqueuer(&q,13);
    enqueuer(&q,46);
    enqueuer(&q,46);

    printf("the dequed element through front is %d\n",dequeuef(&q));
    printf("the dequed element through rear is %d\n",dequeuer(&q));


}