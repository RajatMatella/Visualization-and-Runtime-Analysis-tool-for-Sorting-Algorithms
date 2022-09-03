#include<iostream>
#include<time.h>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arrSize,int arr[])
{
    for(int i=0; i<arrSize-1; i++)
    {
        for(int j=0; j<arrSize-1-i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main_bubble(int size,int arr[]){
    auto start = high_resolution_clock::now();
    bubbleSort(size,arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<"Runtime : "<<duration.count()<<" ms"<<endl;
    
    return 0;
}
