/*
Friend Function and Friend Class In C++

NOTES
1. Keyword "friend" is used to make some [function OR class] as friend of your class.
2. Friend function or Class can access private/public/protected Data member OR Member functions of another class.
3. Function can not become friend of another function
4. Class can not become friend of a function
5. Friendship is NOT mutual. If class A is friend of B, then B doesn't become friend automatically
6. Friendship is not inherited.
7. It is not standard practice in OOP to have Friend class BUT only in some circumstances:
    a)
*/

#include <iostream>
using namespace std;

class Base {
    int x;
public:
    Base() {}
    Base(int a):x{a} {}
    friend void setF(Base&, int);
    friend int getF(Base&);

    //friend class
    friend class GetSet;
};

//Friend class
class GetSet {
    public:
        void set(Base& obj, int x) {obj.x=x;}
        int get(Base& obj) { return obj.x;}
};

void setF(Base& obj, int x) {
    obj.x = x;
}

int getF(Base& obj) {
    return obj.x;
}

int main() {
    Base obj(10);
    //Friend function call
    cout << getF(obj) << endl;
    setF(obj, 20);
    cout << getF(obj) << endl;
    GetSet gs;
    cout << gs.get(obj) << endl;
    gs.set(obj,40);
    cout << gs.get(obj) << endl;
    return 0;
}