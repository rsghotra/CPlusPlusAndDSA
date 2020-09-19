#include <iostream>

using namespace std;

/*
Insertion Sort: A decent agorith which gives linear search time on small input therefore much better choice than Bubble, Selction and sometimes better than Mergesort as well.
Runnint Times:
Best Case Running Time: O(n)
    -When the list is sorted then the algorithm will give O(n) time
Worst Case Running Time: O(n^2)
    - When the list is not in sorted order at all.
Interesting Points:
    - Sorting almost always contains search step.
    - In Insertion Sort - search step is linear i,e: O(n)
    - In-Place Algorithm
    - Insertion sort could be viewed just as a bad Divide and Conquer algorithm
        - Why becasue at each iteration we are dividing the problem inefficiently.
        - Also, in recursive insertion sort - we do not merge the problems altogether but one by one - for imagination perspective.
    - T(n) = {O(1) when n=1; 2T(n-1) + 3C when n>1}
*/


void insertionSortIterative(int a[], const int size) {
    int i, j, key;
    for(j = 1; j < size; j++) {
        cout << "Hello" << endl;
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key) {
            a[i+1] = a[i]; //copying the element forward.
            i--; //interesting
        }
        a[i+1] = key;
    }
}


int main() {
    const int SIZE = 8;
    int array[] = {3, 41, 52, 26, 38, 57, 9, 49};
    insertionSortIterative(array, SIZE);
    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << "   ";
    }
    cout << endl;
    return 0;
}