/*
Reintrepret Cast:
IT can perform dangerous conversions because it can typecast any pointer to any other pointer.
NOTES:
1. Reinrepret cast should be avoided because it is dangerous
2. Reintreprt Cast IS VERY USEFUL WHEN WORKING WITH BITS


BOTTOM LINE
1. if you reintrepret_cast - you make your prject not portable to each CPU architecture
2. reintrepret_cast accessess the hardware directly that is bit - by - bit
*/

#include <iostream>
using namespace std;

class Mango {
    public:
        void eatMango() {cout << "Eating Mango";}
};

class Banana {
    public:
        void eatBanana(int a, int b) {cout << "Eating Banana";}
};

// int main() {
//     Banana* b = new Banana();
//     Mango* m = new Mango();
//     Banana* newBanana = reinterpret_cast<Banana*>(&m);
//     //compiler will change the following line to this
//     newBanana->eatBanana(1, 2);
//     return 0;
// }

struct myStruct {
    int x;
    int y;
    char c;
    bool b;
};

int main() {
    myStruct s;
    s.x = 5; s.y=10;s.c='a';s.b=true;

    int* p = reinterpret_cast<int*>(&s);
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    //now it is point to char datatype hence reintrpret case
    char *c = reinterpret_cast<char*>(p);
    cout << *c << endl;
    c++;
    bool* b = reinterpret_cast<bool*>(c);
    cout << *b << endl;
    return 0;
}