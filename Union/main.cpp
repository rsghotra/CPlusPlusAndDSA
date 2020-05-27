/*
Unions in C++
NOTES:

1. Just like structures and classes a union is a user defined data type.
2. Key point: In union, all members share the biggest same memory location.
3. This is used to achieve polymorphism in C.

Possible Usage?
1. When we need only one value out of many that time we will use Union.(Example: Square class)
2. Get the actual data in parts.(Example: int value. char bytes[4]): When memory is critical we use Union alot
Union gives us byte by byte access of memory and also we can declare multiple data types
Very popular in embedded programming
*/

#include <iostream>
using namespace std;

//Example1
//used to achieve polymorphism in C.
union Square {
    int width;
    int height;
};

int getArea(int width, int height) {
    return width * height;
}

// int main() {
//     Square sqr;
//     sqr.width  = 5;
//     cout << getArea(sqr.width, sqr.height) << endl;
// }

//Example 2: When you need to access data byte by byte.
//very interesting example
union myUnion {
    char bytes[4];
    unsigned int value;
};

int main() {
    myUnion un;
    un.value = 0;
    un.value = 257;

    cout << static_cast<int>(un.bytes[0]) << endl;
    cout << static_cast<int>(un.bytes[1]) << endl;
    cout << static_cast<int>(un.bytes[2]) << endl;
    cout << static_cast<int>(un.bytes[3]) << endl;

    return 0;
}
