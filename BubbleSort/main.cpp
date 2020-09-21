#include <iostream>

using namespace std;

/*
- Bubble Sort - O(n^2) complexity
- Sorting in increasing order.
*/


int main() {
    const int SIZE = 8;
    int arrayy[SIZE] = {8, 5, 2, 2, 5, 7, 3, 8};
    int temp;
    for(int i = 0; i < SIZE - 2; i++) {
        for(int j = i+1; j < SIZE; j++) {
            if(arrayy[i] > arrayy[j]) {
                temp = arrayy[i];
                arrayy[i] = arrayy[j];
                arrayy[j] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arrayy[i] << endl;
    }
    return 0;
}