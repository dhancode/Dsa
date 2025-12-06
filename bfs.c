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
    q.size=7;
    q.arr=(int *)malloc(q.size*sizeof(int));

    //bfs implementation
    int node;
    int i=0;
    int visted[7]={0,0,0,0,0,0,0};
    int a[7][7]=
        {
            {0,1,1,1,0,0,0},
            {1,0,1,0,0,0,0},
            {1,1,0,1,1,0,0},
            {1,0,1,0,1,0,0},
            {0,0,1,1,0,1,1},
            {0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0}
        };
    printf("%d",i);
    visted[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
        int node=dequeue(&q);
        for(int j=0; j < 7; j++)
        {
            if(a[node][j]==1 && visted[j]==0)
            {
                printf("%d",j);
                visted[j]=1;
                enqueue(&q,j);
            }
        }
    }
}