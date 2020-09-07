/*
Function Riding in C++
1. It is a run time binding
2. return type of over-rided functions is taken into account unlike function overloading
3. 
*/

#include <iostream>
using namespace std;

// class Base
// {
//     public:
//         void print() {cout << "Base class" << endl;}
// };

// class Derived: public Base {
//     public:
//         void print() {cout << "Derived class" << endl;}
// };

// int main() {
//     Base b;
//     Derived d;
//     b.print();
//     d.print();
// }

class Person {
public:
    virtual void printName() {
        cout << "Person" << endl;
    }
};

class Man: public Person {
public:
    void printName() override {
        cout << "Man" << endl;
    }
};

class Woman: public Person {
public:
    void printName() override {
        cout << "Woman" << endl;
    }
};

int main() {
    Man m;
    Person* p = &m;
    p->printName();
    return 0;
}



