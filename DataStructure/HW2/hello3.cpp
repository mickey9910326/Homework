#include "hello3.h"
#include<iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for ( int i = 0; i < size; i++ ) {
        cout << arr[i] << ' ';
    }
}
void hello3(){
    int i,tmp;
    cout << "Hello world from header." << endl;
    int target[5] = {2,5,8,1,3};
    cout << "init array = ";
    printArray(target, 5);

    cout << endl << "sorted array = ";
    sort(target, target + 5);
    printArray(target, 5);
}
