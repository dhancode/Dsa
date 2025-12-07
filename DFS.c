#include<stdio.h>
#include<stdlib.h>
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
int DFS(int i)
{
    
    printf("%d",i);
    int j;
    visted[i]=1;
    for(j=0; j<7 ;j++)
    {
        if(a[i][j]==1 && !visted[j])
        {
            DFS(j);
        }
    }
}
int main()
{
    printf("DFS\n");
    DFS(0);
}
