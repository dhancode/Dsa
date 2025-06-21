#include<stdio.h>
void printArray(int A[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void merge(int A[],int low,int high,int mid)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int B[100];
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            k++;
            i++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(j<=high)
    {
        B[k]=A[j];
        j++;
        k++;
    }
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    
    for(int i=low;i<high+1;i++)
    {
        A[i]=B[i];
    }
}
void mergeSort(int A[] , int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,high,mid);
    }
}
int main()
{
    int A[]={7,8,9,1,2,3};
    int n=sizeof(A) / sizeof(A[0]);
    printArray(A,n);
    mergeSort(A,0,n-1);
    printArray(A,n);
}