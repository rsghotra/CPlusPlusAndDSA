/*
Data hiding in C++

1/ Data hiding is about data members in classes, we keep data members as private(generally) and this is considerd
as data hiding.
>>It is not about hacking or something., it is about correctness of the data and preventing accidental manipulation.
*/

#include<iostream>
using namespace std;

class AbcPlayer {
private:
    int volume;
public:
AbcPlayer():volume{0}{}
    void setVolume(int x) {
        //you can put data validation
        if(x>=0 && x<=100) {
            volume = x;
            cout << "Set" << endl;
        } else {
            cout << "Can't set" << endl;
        }
    }
};

int main() {
    AbcPlayer abc;
    abc.setVolume(50);
    abc.setVolume(-30);
    return 0;
}