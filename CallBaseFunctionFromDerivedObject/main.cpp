/*
Please note that this is NOT ABOUT VIRTUAL KEYWORD AND RUN TIME POLYMORPHISM.

IN RUN-TIME-POLYMORPHISM: WE CALL:
    - DERIVED CLASS function from BASE POINTER
IN THIS WE CALL:
    - BASE CLASS FUNCTION FROM DERIVED OBJECT
        1. One very famous way is to use scope resolution operator.
        2. static cast derived object to base class and then call the function: CAUSE DATA LOSS
        3. NEED TO USE POINTERS.

*/

#include <iostream>
using namespace std;

class Base {
    public:
        void fun() {
            cout << "Base" << endl;
        }
};

class Derived:public Base {
    public:
    void fun() {
        cout << "Derived" << endl;
    }
};

int main() {
    Derived d;
    d.fun();
    //IMPORTANT LINE: 1;
    //THIS IS STATIC BINDING
    d.Base::fun();
    //This is Second way; Note it will do SLICING and we will loose the data when converting from D -> B
    Base* b = static_cast<Base*>(&d);
    b->fun();
    //Now we can safely go back to Derived class.

    //Other solution is to use pointers. If we use pointers then no data will be lost. Hence

    return 0;

}
