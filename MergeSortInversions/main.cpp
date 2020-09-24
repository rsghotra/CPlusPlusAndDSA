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
    k = low;
    //Now the Merge;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            a1[k] = left[i];
            i++;
        } else {
            a1[k] = right[j];
            j++;
            inversions += mid - i;
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
        inversions++;
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
    int array[] = { 1, 20, 6, 4, 5};
    
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

// C++ program to Count 
// Inversions in an array 
// using Merge Sort 

// int _mergeSort(int arr[], int temp[], int left, int right); 
// int merge(int arr[], int temp[], int left, int mid, int right); 

// /* This function sorts the input array and returns the 
// number of inversions in the array */
// int mergeSort(int arr[], int array_size) 
// { 
// 	int temp[array_size]; 
// 	return _mergeSort(arr, temp, 0, array_size - 1); 
// } 

// /* An auxiliary recursive function that sorts the input array and 
// returns the number of inversions in the array. */
// int _mergeSort(int arr[], int temp[], int left, int right) 
// { 
// 	int mid, inv_count = 0; 
// 	if (right > left) { 
// 		/* Divide the array into two parts and 
// 		call _mergeSortAndCountInv() 
// 		for each of the parts */
// 		mid = (right + left) / 2; 

// 		/* Inversion count will be sum of 
// 		inversions in left-part, right-part 
// 		and number of inversions in merging */
// 		inv_count += _mergeSort(arr, temp, left, mid); 
// 		inv_count += _mergeSort(arr, temp, mid + 1, right); 

// 		/*Merge the two parts*/
// 		inv_count += merge(arr, temp, left, mid + 1, right); 
// 	} 
// 	return inv_count; 
// } 

// /* This funt merges two sorted arrays 
// and returns inversion count in the arrays.*/
// int merge(int arr[], int temp[], int left, 
// 		int mid, int right) 
// { 
// 	int i, j, k; 
// 	int inv_count = 0; 

// 	i = left; /* i is index for left subarray*/
// 	j = mid; /* j is index for right subarray*/
// 	k = left; /* k is index for resultant merged subarray*/
// 	while ((i <= mid - 1) && (j <= right)) { 
// 		if (arr[i] <= arr[j]) { 
// 			temp[k++] = arr[i++]; 
// 		} 
// 		else { 
// 			temp[k++] = arr[j++]; 

// 			/* this is tricky -- see above 
// 			explanation/diagram for merge()*/
// 			inv_count = inv_count + (mid - i); 
// 		} 
// 	} 

// 	/* Copy the remaining elements of left subarray 
// (if there are any) to temp*/
// 	while (i <= mid - 1) 
// 		temp[k++] = arr[i++]; 

// 	/* Copy the remaining elements of right subarray 
// (if there are any) to temp*/
// 	while (j <= right) 
// 		temp[k++] = arr[j++]; 

// 	/*Copy back the merged elements to original array*/
// 	for (i = left; i <= right; i++) 
// 		arr[i] = temp[i]; 

// 	return inv_count; 
// } 

// // Driver code 
// int main() 
// { 
// 	int arr[] = { 1,2,3,4,5,6 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	int ans = mergeSort(arr, n); 
// 	cout << " Number of inversions are " << ans; 
// 	return 0; 
// } 

// // This is code is contributed by rathbhupendra 
