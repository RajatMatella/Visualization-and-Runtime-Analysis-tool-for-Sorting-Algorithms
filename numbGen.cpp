#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

void main_numbGen(int amount) {
    srand(time(NULL));
    ofstream file ("Random_Numb_Data.txt");
    int i, rnum, first, last;
    cout<<"\n\nEnter the Interval: ";
    cin>>first>>last;
    cout<<"\nList of "<<amount<<" Random Numbers Between "<<first<<" and "<<last<<" : \n"<<endl;
    for(i=0; i<amount; i++)
    {
        rnum = rand()%(last+1-first)+first;
        cout<< rnum <<" ";
        file << rnum <<" ";
    }
    cout<<endl;
    
    file.close();
    
}


