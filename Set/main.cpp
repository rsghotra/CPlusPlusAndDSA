#include <iostream>
#include <set>
#include <functional>

using namespace std;
//usage of set.
/*
1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
2. It is usually implemented using Red-Black Tree.
3. Insertion, Removal, Search have logarithmic complexity.
4. If we want to store user defined data type in set then we will have to provide 
   compare function so that set can store them in sorted order.
5. We can pass the order of sorting while constructing set object.

BOTTOM LINE:
It store unique elements and they are stored in sorted order (A/D)
*/
//point 4: User defined data type and set.
class Person {
    public:
        float age;
        string name;
    //providing comparator
    bool operator < (const Person& rhs) const {
        return age< rhs.age;
    }
    bool operator > (const Person& rhs) const {
        return age> rhs.age;
    }
};

int main() {
    //set<int> Set = {1,2,3,2,1,1,4,5,3,5,7,2};
    set<Person, std::greater<>> p = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "John"}};
    for(const auto& e: p) {
        cout << e.age << " " << (e.name) << endl;
    }
    return 0;
}

