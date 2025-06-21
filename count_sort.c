#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int maximum(int A[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    return max;

}
void countSort(int A[],int n)
{
    int max=maximum(A,n);
    printf("the size of count array \%d\n",max+1);
    int i,j;
    int *count=(int *)malloc(sizeof(int) * max+1);

    //intializing the count array to all zeros
    for(i=0;i<max+1;i++)
    {
        count[i]=0;
    }
    //incrementing the elements values in count array using orginal array
    for(i=0;i<n;i++)
    {
        count[A[i]]=count[A[i]]+1;
    }

    i=0;//to traverse the count array
    j=0;//to traverse the orginal array
    while(i<=max)
    {
        if(count[i]>0)
        {   
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
        {
            i++;
        }
    }


}
int main()
{
    int A[]={7,11,2,9,17,4};
    int n=(sizeof(A)) / sizeof(A[0]);
    printArray(A,n);//arr before sorting
    countSort(A,n);
    printArray(A,n);//arr after sorting
}