#include <iostream>
using namespace std;

/*
Conditions: It is a Set so no duplicate entries.

*/

int binarySearch(int a[], int low, int high, int key) {
    while(low <= high) {
        int mid = (low + high)/2;
        if(a[mid] == key) return mid;
        if(a[mid] > key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 10;
    int x, leftValue, elem, foundIndex;
    int array[SIZE] = {12,7,5,11,4,3,9,15,9,1};
    cout << "Please enter the value of x: ";
    cin >> x;
    for(int i = 0; i < SIZE; i++) {
        leftValue = array[i];
        elem = x - leftValue;
        if(elem > 0) {
            //go fo binary search in the array
            foundIndex = binarySearch(array, i+1, SIZE - 1, elem);
            if (foundIndex != -1) {
                cout << "\nFound correspnding element in the array at " << foundIndex << " index" << endl;
                cout << "LHS = " << leftValue << "\tRHS =  " << array[foundIndex]<< endl;
                break;
            }
        }
    }
    if(foundIndex == -1) cout << "\nElement not found!" << endl;
}
