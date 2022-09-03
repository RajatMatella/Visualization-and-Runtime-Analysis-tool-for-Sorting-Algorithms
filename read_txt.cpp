#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    ifstream fp("Random_Numb_Data.txt");
    int arr[10];
    int i=0;
    int x;
    while (fp >> x){
        arr[i] = x;
        i++;
    }

    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
   
    return 0;
}