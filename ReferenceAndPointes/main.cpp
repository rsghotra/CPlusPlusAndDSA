/*
Q: What is the difference between Reference and Pointer in C++?
Reference operator: is jsut an alias, does not have its own memory address

NOTES:
1. Memory Address
2. REASSIGNMENT Is not possible with reference as it a tight bound
3. NULL value: You can not initilize reference variable with NULL value
4. Arithmetic Operations: Arithmetic operations are NOT available
5. Indirection: Only 1 level of indirection for reference variable but n-level of indirection with pointer variable.
*/

#include <iostream>
using namespace std;

int main() {
    int i=10;
    int &r = i; // refrence here //re-assignment is not possible
    int *p = &i; //pointer
    //p has its own memory address
    cout << &r << '\t' << &p << '\t' << &i<< endl;
    cout << i << endl;

    //only 1 level of indirection
    int &r1 = r;

    cout << r << '\t' << r1 << endl;
    return 0;
}