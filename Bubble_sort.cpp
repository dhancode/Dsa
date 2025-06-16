#include<stdio.h>
void printArr(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubbleSort(int A[],int n)
{
    int temp;
    for(int i=0;i<n-1 ;i++)
    {
        printf("The number of passes is %d\n",i+1);
        for(int j=0;j,j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }

    }
}

void adaptiveBubbleSort(int A[],int n)
{
    int temp;
    int isSorted=0;
    for(int i=0;i<n-i;i++)//no of passes
    {
        isSorted=1;
        printf("The number of passes is %d\n",i+1);
        for(int j=0;j,j<n-i-1;j++)//no of comparsions
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted)
        {
            return;
        }

    }
}
int main()
{
    int A[]={12,3,4,5,6};
    int n=(sizeof(A))/(sizeof(A[0]));
    printArr(A,n);//before sorting
    //bubbleSort(A,n);
    adaptiveBubbleSort(A,n);
    printArr(A,n);//after sorting
}