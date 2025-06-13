#include<stdio.h>
#include<stdlib.h>
struct circularQueue
{
    int f;
    int r;
    int size;
    int *arr;
};
int isFull(struct circularQueue *q)
{
    if((q->r+1)%(q->size)==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct circularQueue *q,int val)
{
    if(isFull(q))
    {
        printf("queue overflow\n");
    }
    else
    {
        q->r=(q->r+1)%(q->size);
        q->arr[q->r]=val;
        printf("the enqueued element is %d\n",val);
    }
}

int isEmpty(struct circularQueue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}
int dequeue(struct circularQueue *q)
{
    int val=-1;
    if(isEmpty(q))
    {
        printf("the queue is in underflow\n");
    }
    else
    {
        q->f=(q->f+1)%(q->size);
        val=q->arr[q->f];
    }
    return val;
}
int main()
{
    struct circularQueue q;
    q.f=0;
    q.r=0;
    q.size=4;
    q.arr=(int *)malloc(q.size*sizeof(int *));

    enqueue(&q,14);
    enqueue(&q,7);
    enqueue(&q,11);
    enqueue(&q,12);

    printf("the element dequed is %d\n",dequeue(&q));
    printf("the element dequed is %d\n",dequeue(&q));
    printf("the element dequed is %d\n",dequeue(&q));
    printf("the element dequed is %d\n",dequeue(&q));

    enqueue(&q,12);
}