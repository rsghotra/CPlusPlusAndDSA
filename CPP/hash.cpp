/* hash.cpp */

#include <iostream>
#include <functional>
#include <string>
using namespace std;


int main(void) {
	string plainText = "";
	cout << "Input string and hit Enter if ready: ";
	cin >> plainText;

	hash<string> hashFunc;

	size_t hashText = hashFunc(plainText);
	cout << "Hashing: " << hashText << "\n";
	return 0;
}