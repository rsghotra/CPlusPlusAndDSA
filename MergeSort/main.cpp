// Merge Sort Recursive.
#include <iostream>
#include <vector>
using namespace std;

/*
1. Merge Sort is based on Algo Design Pattern - Divide and Conquer.
2. It forms a TREE.
3. The height of the tree will be O(logn)
4. No. of levels in the tree is : logn + 1
5. At each level we MERGE n elements. Therefore, at each level the cost is cn.
6. T(n) = O(n*logn)
7. S(n) = O(n)
8. Yes, it is correct Merge sort has some sort of O(n) space complexity

*/
void merge(int *array, const int p, const int q, const int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int i, j, k;
    //temp arrays.
    vector<int> left(n1);
    vector<int> right(n2);
    //putting left and right sorted array.
    for(int i = 0; i < n1; i++) {
        //PITFALL - 1. Make sure you use 'p' as it will change with every call
        left[i] = array[p + i];
    }
    for(int j = 0; j < n2; j++) {
        // PITFALL - 2 - Must start from mid+1 and onwards.
        right[j] = array[j+q+1];
    }
    i = 0;
    j = 0;
    // PIT FALL - 3
    k = p;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    //When either of left or right array is exhausted but the other array have elements left.
    while(i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }
    while(j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int p, int r) {
    if(p < r) {
        int q = (p+r)/2;
        mergesort(array, p, q);
        mergesort(array, q+1, r);
        merge(array, p, q, r);
    }
}

int main() {
    const int SIZE = 6;
    int array[SIZE] = {100, 5, 3, 1, 99, 2};
    mergesort(array, 0, 5);
    for(int i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}