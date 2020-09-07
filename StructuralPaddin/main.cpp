/*
Sturctural Padding & Packing in C++
1. It is a way to speed up Speed optimization
2. Padding : Adding extra bit
3. Packing: Not adding extra bit
4. If data is stored at Hard Disk = PAGES
5. If data is stored at Memory = Called SEGMENTS
6. Paging HELPS Mapping: PAGES==>SEGMENTS.
7. How data gets memory slots?

1 Byte ==> can be stored at multiple of 1 memory slot
2 Byte ==> can be stored at multiple of 2 memory slot
4 Byte ==> can be stored at multiple of 4 memory slot
*/
#include <iostream>
using namespace std;

//#pragma pack(1)
//1 word is 4 byte in 32 bit processor
//1 word is 8 byte in 64 bit processor
// |a|b|c|-|i|i|i|i|
struct Base {
    char a;
    char b;
    char c;
    int i;
};

// |a|-|b|b|
struct Base2 {
    char a;
    short b;
};

int main() {
    cout << sizeof(Base) << endl;
    return 0;
}