#include<stdio.h>
void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partion(int *A,int low,int high)
{
    int pivot=A[low];
    int i=low+1; //used to find the largest element from the array;
    int j=high; //used to find the samllest element from  the array;
    do{
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);

    int temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void quickSort(int *A,int low,int high)
{
    if(low<high)
    {
        int partionIndex=partion(A,low,high);
        quickSort(A,low,partionIndex-1);
        quickSort(A,partionIndex+1,high);
    }
}
int main()
{
    int A[ ]={7,11,2,9,17,4};
    int n=(sizeof(A))/(sizeof(A[0]));
    printArray(A,n);//Array before sorting
    quickSort(A,0,n-1);
    printArray(A,n);//Array after sorting
}