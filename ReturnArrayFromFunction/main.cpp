/*
Q: How to return Array from a function in C++
Ans:
1. By using static keyword.
2. Create array dynamically.
Note: Returning pointer to local or reference to local is not a good idea.
*/

#include<iostream>
using namespace std;

int* function() {

    //you need to  use static keyword here
    //method1-class variable
    static int arr[3] = {1,2,3};
    //method2-heap memory
    int* arr2 = new int[3];
    arr2[0] = 22;
    arr2[1] = 23;
    arr2[2] = 24;
    return arr2;
}


int main() {
    int* arr = function();
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    delete [] arr;
    return 0;
}