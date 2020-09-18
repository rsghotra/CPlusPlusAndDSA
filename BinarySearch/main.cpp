#include <iostream>

using namespace std;

/*
Death Traps:
1. mid is always calculated as floor of L+H/2
2. LeftIndex could be atmost equal to High Index
3. We move LeftIndex to mid + 1
4. We move rightIndex to mid-1
5. Algo Analysis:
    - Best Case Run Time: O(1)
    - Worst Case: O(logn)
6. Analysis By Making A Tree of Middle
5. Reference: https://www.youtube.com/watch?v=C2apEw9pgtw&ab_channel=AbdulBari
6. https://www.youtube.com/watch?v=uEUXGcc2VXM&frags=wn&ab_channel=AbdulBari
*/

int binarySearchIter(int a[], const int SIZE, int elem) {
    int foundAt = -1;
    int mid = -1;
    int leftIndex = 0;
    int rightIndex = SIZE - 1;
    int count = 0;
    while(leftIndex <= rightIndex) {
        //ceiling
        mid = (leftIndex + rightIndex)/2;
        cout << "==>LeftIndex=" << leftIndex << endl;
        cout << "==>RightIndex=" << rightIndex << endl;
        cout << "===>Mid=" << mid << endl;
        if(a[mid] == elem) {
            cout << "Element found at index " << mid << endl;
            foundAt = mid;
            break;
        }
        if(elem > a[mid]) {
            leftIndex = mid + 1;
        } else {
            rightIndex = mid - 1;
        }
    }

    return foundAt;
}

void binarySearchRecur(int a[], int first, int last, int elem) {
    //Divide Step
    int mid = (first + last)/2;
    if(first > last ) {
        cout << "Element Not Found." << endl;
        return;
    };
    if(elem == a[mid]) {
        cout << "Element found at: " << mid << endl;
        return;
    }
    if(elem > a[mid]) {
        //reducing the problem size by half.
        binarySearchRecur(a, mid+1, last, elem);
    } else {
        binarySearchRecur(a, first, mid-1, elem);
    }
}

int main() {
    const int SIZE = 5;
    int array[] = {3, 10, 15, 34, 40, 47};
    //cout << binarySearchIter(array, SIZE, 20) << endl;
    binarySearchRecur(array, 0, SIZE-1, 33);
    return 0;
}