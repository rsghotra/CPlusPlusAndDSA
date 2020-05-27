/*
C++ Interview Questions
*/
#include <iostream>
//Que1: Difference between void and void*
//https://www.youtube.com/watch?v=t9s6280XQ5Q&list=PLk6CEY9XxSIDxoAaWfdNSX-QckVXMWMMZ

using namespace std;

void fun( void ) {
    cout << "CPP" << endl;
}

int main() {
    int* i = new int(10);
    //always use static cast.
    void* v = static_cast<void*>(i);
    //void is a generic type. That is why dereference the void pointer.
    cout << *(static_cast<int*>(v)) << endl;
    fun();

    //USAGE
    int *y = static_cast<int*>(malloc(sizeof(int)));
    char* c = static_cast<char*>(malloc(sizeof(char)));

}

/*
BOTTOM LINE:
- void means nothing and void* means pointer to anything(except function pointer, const or volatile)
USE CASES:
// Malloc and calloc returns void* or void pointers.
//In c++, void* to any other pointer conversion is always explicit like in line 23.
//
*/