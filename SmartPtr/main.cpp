#include<iostream>
using namespace std;

/*
It is basically a wrapper which wraps raw pointer and handles the life time of the object for you, 
means if there is no reference to the pointer it will delete it otherwise it will hold. 
There are basically three types of smart pointers. 
TYPES:
1. unique_ptr
2. shared_ptr
3. weak_ptr
And the basic job of smart pointer is, it actually makes sure that we don't have memory leaks. 

*/
class MyInt {
    public:
        explicit MyInt(int *p=nullptr) {
            data=p;
        }
        ~MyInt() { delete data;}

        int& operator *() {return *data;}
    private:
        int *data;
};

int main() {
    int *p = new int(10);
    //making it a smart ptr;
    //note that there is no NEW keyword used
    //intentionally so that variable is allocated in Call Stack
    //when scope is finished myInt object's desctructor is called.
    //Hence pointer p is removed automatically from the memory.
    MyInt myInt = MyInt(p);
    cout << *myInt << endl;
    return 0;
}