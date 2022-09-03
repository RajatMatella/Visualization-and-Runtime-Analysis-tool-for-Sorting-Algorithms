#include<iostream>
#include<limits>
#include<time.h>
#include<string.h>
#include<chrono>
#include<fstream>


#include "numbGen.cpp"
using namespace std;

using namespace chrono;


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

void inplaceHeapSort_runtime(int* input, int n)
{
    for(int i=1; i<n; i++)
    {
       int childIndex=i;
       int parentIndex=(childIndex-1)/2;

       while(childIndex>0)
       {
           if(input[childIndex]>input[parentIndex])
           {
               int temp=input[parentIndex];
               input[parentIndex]=input[childIndex];
               input[childIndex]=temp;

           }
           else
           {
               break;
           }

           childIndex=parentIndex;
           parentIndex=(childIndex-1)/2;
       }
    }

    for(int heapLast=n-1; heapLast>=0 ; heapLast--)
    {
        int temp=input[0];
        input[0]=input[heapLast];
        input[heapLast]=temp;

        int parentIndex=0;
        int leftChildIndex=2*parentIndex + 1;
        int rightChildIndex=2*parentIndex + 2;

        while(leftChildIndex<heapLast)
        {
            int maxIndex=parentIndex;

            if(input[leftChildIndex]>input[maxIndex])
            {
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<heapLast && input[rightChildIndex]>input[maxIndex])
            {
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex)
            {
                break;
            }

            int temp=input[parentIndex];
            input[parentIndex]=input[maxIndex];
            input[maxIndex]=temp;

            parentIndex=maxIndex;
            leftChildIndex=2*parentIndex + 1;
            rightChildIndex=2*parentIndex + 2;
        }
    }
}

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


void user_controls(){
    cout <<"\n\nAvailable User Controls :-\n"
         <<"    Use 1 to start Selection Sort Algorithm.\n"
         <<"    Use 2 to start Insertion Sort Algorithm.\n"
         <<"    Use 3 to start Bubble Sort Algorithm.\n"
         <<"    Use 4 to start Merge Sort Algorithm.\n"
         <<"    Use 5 to start Quick Sort Algorithm.\n"
         <<"    Use 6 to start Heap Sort Algorithm.\n";
}

int main_runtime()
{
    int size;
    cout<<"\nEnter size of the array: "<<endl;
    cin>>size;
    int arr[size];
    


    //creating a txt file containing numbers = size within a user defined range
    main_numbGen(size);


    //Reading input data for our array from "Random_Numb_Data.txt" file
    ifstream fp("Random_Numb_Data.txt");
    int i=0;
    int read;
    while (fp >> read) {
        arr[i] = read;
        i++;
    }


    auto started = high_resolution_clock::now(); //start time measure
    int choice;
    int x=1;
    while(x){
        user_controls();
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                {
                    selectionSort(size,arr);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n^2)"<<endl;
                    cout<< "Space Complexity : O(1)"<<endl;
                    x=0;
                    break;
                }

            case 2:
                {
                    insertionSort(size,arr);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n^2)"<<endl;
                    cout<< "Space Complexity : O(1)"<<endl;
                    x=0;
                    break;
                }

            case 3:
                {
                    bubbleSort(size,arr);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n^2)"<<endl;
                    cout<< "Space Complexity : O(1)"<<endl;
                    x=0;
                    break;
                }

            case 4:
                {
                    mergeSort_runtime(arr,0,size-1);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n*log(n))"<<endl;
                    cout<< "Space Complexity : O(n)"<<endl;
                    x=0;
                    break;
                }

            case 5:
                {
                    quickSort_runtime(arr,0,size-1);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n^2)"<<endl;
                    cout<< "Space Complexity : O(log(n))"<<endl;
                    x=0;
                    break;
                }

            case 6:
                {
                    inplaceHeapSort_runtime(arr,size);
                    auto done = high_resolution_clock::now();	//end time measure
                    cout<< "\n\nRunning time: " << duration_cast<milliseconds>(done - started).count() << " ms\n" << endl;
                    cout<< "Time Complexity : O(n*log(n))"<<endl;
                    cout<< "Space Complexity : O(1)"<<endl;
                    x=0;
                    break;
                }

        }

    }

    cout<<"\n\nSorted array :-"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n\n\n--------------EXITING PROGRAM--------------\n\n\n";

    return 0;

}

