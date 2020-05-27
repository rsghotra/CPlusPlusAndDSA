/*
Const Cast: The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointes or references.
Where T must be a pointer, reference or pointer-to-member type.

BOTTOM LINE:

1. Never use unless you have to use it.
2. Use to remove constentness of the ptr
3. Use only when dealing with 3rd party library and some API want data in non-const form but we have it in const form.
*/


#include <iostream>
using namespace std;

//1. When the actual referred object/variable is not const.

int main() {
    const int a1 = 10;
    const int *b1 = &a1;
    int *d1 = const_cast<int*>(b1);
    *d1 = 15; //Invalid and undefined behavior. NO COMPILE OR RUNTIME ERROR
    cout << a1 << endl;
    cout << *d1 << endl;
    int a2 = 20;
    const int *b2 = &a2;
    int *d2 = const_cast<int*>(b2);
    *d2 = 30;
}