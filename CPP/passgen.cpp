/* passgen.cpp */

#include <iostream>
#include "pwgen_fn.h"

using namespace std;

int main(void) {
	int passLen;
	cout << "Define password length: ";
	cin >> passLen;

	PasswordGenerator pg;

	string password = pg.Generate(passLen);
	cout << "Your password: " << password << "\n";
	return 0;
}