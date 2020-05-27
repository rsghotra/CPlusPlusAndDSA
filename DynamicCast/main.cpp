/*
Dynamic Cast in C++: https://www.youtube.com/watch?v=wE4beL95pIo&list=PLk6CEY9XxSIDxoAaWfdNSX-QckVXMWMMZ&index=8
1. dynamic_cast ==> downcast
2. static_cast ==> upcast
3. dynamic_Cast is used at runtime to find out correct down-cast.
4. dynamic_casti is run-time checking
NOTES:
0. Need at least one virtual function in base class.
1. it is concept of virtual functions
2. if the cast is successful, dynamic_cast returns a value of type new_type.
3. if the cast fails and new_type is a pointer type, it returns a null pointer of that type.
4. if the cast fails and new_type is a refrence type, it thrwos an exception that matches a handler of type std::bad_cast

BOTTOM LINE:
1. dynamic_Cast checks at RUN-TIME therefore it has run-time overhead.becuse compilers checks for RunTimeTypeInformation(RTTI) of object Not good for HFT
2. work only on polymorphic base class(at least one virtual function in base class) because it uses this information to decide wrong downcast.
3. it is used for up-case(D->B) and down-cast(B->D), but it is mainly used for correct downcast.
*/

#include <iostream>
using namespace std;

class Base {
    virtual void print() {
        cout << "Base" << endl; 
    }
};

class Derived1: public Base {
    void print() {
        cout << "Derived1" << endl;
    }
};

class Derived2: public Base {
    void print() {
        cout << "Derived2" << endl;
    }
};

int main() {
    Derived1 d1;
    Base* bp = dynamic_cast<Base*>(&d1);
    // following casting will fail and dymaic_cast will detect is.
    Derived2 *dp2 = dynamic_cast<Derived2*>(bp);
    //correct dymaic upcasting
    Derived1 *dp3 = dynamic_cast<Derived1*>(bp);
    if(dp3 == nullptr) {
        cout << "NULL " << endl;
    } else {
        cout << "NOT NULL"  << endl;
    }
    return 0;
}