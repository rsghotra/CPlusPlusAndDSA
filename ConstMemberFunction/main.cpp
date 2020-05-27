/*
Constant member function: https://www.youtube.com/watch?v=MR37gqFEmFA&list=PLk6CEY9XxSIDxoAaWfdNSX-QckVXMWMMZ&index=3&frags=wn

Notes:
This is a used to restrict modification of data members inside function.
BUT there is still a way to do modifications.
 -- 
*/
#include <iostream>
using namespace std;

class Base {
    mutable int x;
    //make x mutable and then you can modify it with in const function.
public:
    Base() {}
    Base(int a):x{a} {}
    void setX(int a) {x = a;}
    int getX() const { x = 20; return x;}
};

int main() {
    Base b;
    b.setX(10);
    cout << b.getX() << endl;
    return 0;
}

