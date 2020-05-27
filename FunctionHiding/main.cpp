/*
FUNCTION HIDING IN C++: https://www.youtube.com/watch?v=UURcpaMa0bg&list=PLk6CEY9XxSIDxoAaWfdNSX-QckVXMWMMZ&index=5
Lots of people take function hiding as data hiding or something else 
but this is important concept of c++ inheritance.
- Generally any function with same name (note - not signature is by defualt hidden by the derived class functions)
- Two ways to call base functions:
    1) Using scope resolution: d.Base::fun(1);
    2) using Base::fun scope in Derived class definition
*/

#include <iostream>
using namespace std;

class Base {
    public:
    void fun() {cout << "void" << endl;}
        int fun(int i) {
            cout << "Base" << endl;
            return 0;
        }
};

class Derived: public Base {
    public:
        using Base::fun;
        int fun(char c) {
            cout << "Derived" << endl;
            return 0;
        }
};

int main() {
    Derived d;
    //call to derived class
    d.fun(1);
    //call to derviced class
    d.fun('a');
    // if i want to actually use function of the base class.Then, use scope resolution
    d.Base::fun(1);
    d.fun();
    return 0;
}