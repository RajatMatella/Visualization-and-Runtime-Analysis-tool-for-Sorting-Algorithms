#include<iostream>

using namespace std;

void insertionSort(int arrSize,int arr[])
{
    for(int i=1; i<arrSize; i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
    }
}

int main_insertion(int size,int arr[]){
    insertionSort(size,arr);
    return 0;
}
