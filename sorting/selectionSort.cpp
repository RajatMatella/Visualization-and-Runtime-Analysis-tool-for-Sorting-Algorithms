#include<iostream>

using namespace std;

void selectionSort(int arrSize,int arr[])
{
    int minIndex;
    for(int i=0;i<arrSize-1;i++)
    {
        minIndex=i;
        for(int j=i+1;j<arrSize;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

int main_selection(int size,int arr[]){
    selectionSort(size,arr);
    return 0;
}
