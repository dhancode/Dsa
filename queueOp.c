#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int f;
    int r;
    int *arr;
    int size;
};

int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    return 0;
} 
void enqueue(struct queue *q,int val)
{
    if(isFull(q))
    {
        printf("queue overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("the value enqueued value is %d\n",val);
    }
}
int isEmpty(struct queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    return 0;
}
int dequeue(struct queue *q)
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
int main()
{
    struct queue q;
    q.f=-1;
    q.r=-1;
    q.size=4;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,13);
    enqueue(&q,11);
    enqueue(&q,12);    
    enqueue(&q,10);    
    enqueue(&q,12);

    printf("the dequed element is %d\n",dequeue(&q));
    printf("the dequed element is %d\n",dequeue(&q));
    printf("the dequed element is %d\n",dequeue(&q));
    printf("the dequed element is %d\n",dequeue(&q));
    printf("the dequed element is %d\n",dequeue(&q));
}