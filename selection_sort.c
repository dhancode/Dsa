#include<stdio.h>
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[minIndex])
            {
                minIndex=j;
            }
        }
        int temp=A[i];
        A[i]=A[minIndex];
        A[minIndex]=temp;
    }
}
int main()
{
    int A[]={8,0,7,1,3};
    int n=(sizeof(A))/(sizeof(A[0]));
    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
}
