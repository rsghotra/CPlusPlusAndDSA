/*
Topic: Static cast in C++
Static casting means - casting will happen at compile time and not at runtime.
NOTES:
 - 1. We need static cast to make sure C-style implicit conversion does not ruin the code.
 - 2. Use static_cast when conversion between types is provided through conversion operator 
        or conversion constructor. See prog2
.  3  Static cast is more restrictive than C-Style
        EXAMPLE: char* to int* is allowed in C-Style but not with static_cast. see prog3
   4. Static cast avoid cast from dervived to prvate base pointer. see prog 4.
   5. Use for all upcasts, BUT never used for confused downcast
   6. Static_cast should be prefered when converting to void* OR from void*
*/

#include <iostream>
using namespace std;

//Program 1
// int main() {
//     float f = 3.5;
//     int a;

//     a = f;
//     a = static_cast<int>(f);
//     return 0;
// }

class Int {
    int x;
    public:
        Int(int x=0):x{x}{
            cout << "conversion constructor" << endl;
        };
        operator string() {
            cout << "conversion operator" << endl;
            return to_string(x);
        }
};

// int main() {
//     Int obj(3);

//     string str1 = static_cast<string>(obj);
//     obj = static_cast<Int>(30);
//     string str2 = static_cast<string>(obj);
//     obj = static_cast<Int>(30);
// }

//Program3
// int main() {
//     char c; //1-byte data
//     //this is C-style casting.
//     int* p = (int*) &c; //4-byte data
//     *p = 5; //PASS at compile time but will fail at run time.(that's why it is not allowed).
//     //corrupt memory, segmentation fault what not.
//     //this is C++ casting.C++ casting saves alot of dangerous trouble.
//     //int* ip = static_cast<int*>(&c); //FAIL at COMPILE TIME
//     return 0;
// }

//Program 4

class Base {};
class Derived1: public Base {};
class Derived2: public Base {};


// int main() {
//     Derived d1;
//     Base *bp1 = (Base*)&d1; //C-Style casting //Allowed at Compile time
//     Base *bp2 = static_cast<Base*>(&d1); //Not allowed at Run-Time
// }

//program 5
// int main() {
//     Derived1 d1;
//     Derived2 d2;

//     Base* bp1 = static_cast<Base*>(&d1);
//     Base* bp2 = static_cast<Base*>(&d1);

//     Derived1* d1p = static_cast<Derived1*>(bp2);
//     Derived2* d2p = static_cast<Derived2*>(bp1);
// }

//program 6
//static_cast should be used when converting to void* OR from void*.

int main() {
    int i = 10;
    void* v = static_cast<void*>(&i);
    int *ip = static_cast<int*>(v);
    return 0;
}

