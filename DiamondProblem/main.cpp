#include <iostream>

//this program illustrated the classic diamond problem which arises in C++.
// when multiple inhertince is being used.
/*
Solutions:
    1. To remove ambiguity in the child Class D. It's better to override
        foo function in child class D. So that Ambiguity could be removed. In order to do that
        you need to make function in base class virtual.

*/
// class A {
//     public:
//     virtual int foo() {
//         return 1;
//     }
// };

// class B: public A {

// };

// class C: public A {

// };

// class D: public B, public C {
//     public:
//         int foo() override{
//             return 100;
//         }
// };

/*2. Use Virtual inhertince which tells makes the compiler aware to always use
        base class method.
*/
class A {
    public:
    int foo() {
        return 1;
    }
};

class B: virtual public A {

};

class C: virtual public A {

};

class D: public B, public C {
    public:
};

int main() {
    D d;
    std::cout << d.foo() << std::endl;
    return 0;
}