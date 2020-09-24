#include <iostream>
#include <vector>
using namespace std;

// /*
// Inversions with Merge Sort: Is pretty similar to merge sort but with some pit falls.
// PIT-FALLS:
// 1. In merge sort - array is passed and therefore - mergesort recursive function and merge iterative function
//     returns VOID.
// 2. Inversion: if i < j  AND A[I] > A[J] where i and j are index of an array.
// 3. In merge sort: INVERSION will happen when the ELEMENT is coming from the RIGHT ARRAY.
// 4. Because if it is coming out RIGHT ARRAY THEN J > I BUT A[I] > A[J]
// 5. WHICH MEANS RECURSIVE FUNCTION AND ANY HELPER FUNCTION MUST BE RETURNING NO OF INVERSIONS
// 6. Every sub problem must return an int and then add the two inversions
// 7. Ref 1: Coreman 3rd Editin
// 8. Ref 2: https://www.geeksforgeeks.org/counting-inversions/ --> Solution is similar but not exactly same.
// */

int merge(int a1[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int inversions = 0;
    vector<int> left(n1);
    vector<int> right(n2);
    //fill the elements in the left and right array.
    int i, j, k;
    for(i=0; i < n1; i++) {
        left[i] = a1[low+i];
    }
    for(j=0; j < n2; j++) {
        right[j] = a1[j+mid+1];
    }
    i = 0; j = 0;
    //PIT FALL
    k = low;
    //Now the Merge;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            a1[k] = left[i];
            i++;
        } else {
            a1[k] = right[j];
            cout << "=========" << " i= " << i << " j= " << j << " =================" << endl;
            cout << "Left[i]: " << left[i] << endl;
            cout << "Right[i]: " << right[j] << endl;
            j++;
            inversions += mid - i + 1;
        }
        k++;
    }
    //one of the array must be exhausted at this point of time;
    while(i < n1) {
        a1[k] = left[i];
        i++;
        k++;
    }
    while(j < n2) {
        a1[k] = right[j];
        j++;
        k++;
    }
    return inversions;
}

int mergesort(int a1[], int leftIndex, int rightIndex) {
    int number_of_inversions=0;
    if(leftIndex < rightIndex) {
        int mid = (leftIndex + rightIndex)/2;
        number_of_inversions += mergesort(a1, leftIndex, mid);
        number_of_inversions += mergesort(a1, mid+1, rightIndex);
        number_of_inversions +=  merge(a1, leftIndex, mid, rightIndex);
    }
    return number_of_inversions;
}

int main() {
    int SIZE = 5;
    int array[] = { 1, 2, 3, 4, 5 };
    
    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    int inversions = mergesort(array, 0, SIZE - 1);
    cout << "==============" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Number of Inversions: " << inversions << endl;
    return 0;
}
