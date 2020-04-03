#include<iostream>
using namespace std;

/*
NOTES:
0. unique_ptr is a class template.
1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
   when unique_ptr object goes out of scope.
3. similar to actual pointers we can use arrow and * on the object of unique_ptr,  because it is overloaded in unique_ptr class.
4. When exception comes then also it will de-allocate the memory hence no memory leak.
5. Not only object we can create array of objects of unique_ptr.
*/

int main() {
    
    return 0;
}