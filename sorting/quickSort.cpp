#include<iostream>

using namespace std;

int partition_array_runtime(int a[], int si, int ei)
{
    int count_small=0;

    for(int i=(si+1);i<=ei;i++)
    {
        if(a[i]<=a[si])
        {
            count_small++;
        }
    }
    int c=si+count_small;
    int temp=a[c];
    a[c]=a[si];
    a[si]=temp;

    int i=si, j=ei;

    while(i<c && j>c)
    {
        if(a[i]<= a[c])
        {
            i++;
        }
        else if(a[j]>a[c])
        {
            j--;
        }
        else
        {
            int temp_1=a[j];
            a[j]=a[i];
            a[i]=temp_1;

            i++;
            j--;
        }
    }
    return c;
}

void quickSort_runtime(int a[], int si, int ei)
{
    if(si>=ei)
    {
        return;
    }

    int c=partition_array_runtime(a, si, ei);
    quickSort_runtime(a, si, c-1);
    quickSort_runtime(a, c+1, ei);

}

int main_quick(int size,int arr[]){
    quickSort_runtime(arr,0,size-1);
    return 0;
}