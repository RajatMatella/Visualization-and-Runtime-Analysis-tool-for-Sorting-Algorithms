#include<iostream>

using namespace std;

void merge2SortedArrays_runtime(int a[], int si, int ei)
{
    int size_output=(ei-si)+1;
    int* output=new int[size_output];

    int mid=(si+ei)/2;
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei)
    {
        if(a[i]<=a[j])
        {
            output[k]=a[i];
            i++;
            k++;
        }
        else
        {
            output[k]=a[j];
            j++;
            k++;
        }

    }
    while(i<=mid)
    {
        output[k]=a[i];
        i++;
        k++;
    }
    while(j<=ei)
    {
        output[k]=a[j];
        j++;
        k++;
    }
    int x=0;
    for(int l=si; l<=ei; l++)
    {
        a[l]=output[x];
        x++;
    }
    delete []output;
}

void mergeSort_runtime(int a[], int si, int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;

    mergeSort_runtime(a, si, mid);
    mergeSort_runtime(a, mid+1, ei);

    merge2SortedArrays_runtime(a, si, ei);
}

int main_merge(int size,int arr[]){
    mergeSort_runtime(arr,0,size-1);
    return 0;
}
