/*
How to return two dimensional array from function in C++?
Ans1: Using Dynamic Array
Ans2: Using static keyword
Ans3: Using struct technique == when array gets bigger it gets problematic.
*/

#include <iostream>
using namespace std;

//Ans1: Dynamic Array
int** getArray() {
    int** arr = new int*[3];
    for(int i=0;i<3;i++) {
        arr[i] = new int[3];
        for(int j=0;j<3;j++) {
            arr[i][j] = i+j;
        }
    }
    return arr;
}

void printArray(int** arr) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << arr[i][j] << endl;
        }
    }
}

// int main() {
//     int **arr;
//     arr = getArray();
//     printArray(arr);
//     return 0;
// }

//Ans2 is weird

//Ans3: Using Struct
//How we do it is we wrap the array around struct
const int N = 3;
struct ArrayStrct {
    int arr[3][3];
};

void printArrayS(ArrayStrct var) {
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            cout << var.arr[i][j] << " ";
        }
    }
    cout << endl;
}

ArrayStrct getArrayS() {
    ArrayStrct var;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            var.arr[i][j] = i+j;
        }
    }
    return var;
}

int main() {
    ArrayStrct arr;
    arr=getArrayS();
    printArrayS(arr);
    return 0;
}

