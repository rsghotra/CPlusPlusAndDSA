/* pwgen_fn.cpp */

#include "pwgen_fn.h"



string PasswordGenerator::Generate(int passwordLength) {
	int randomNumber;
	string password;
	srand(time(0));

	for(int i = 0; i < passwordLength; i++) {
		randomNumber = rand() % 94 + 33;
		password += (char) randomNumber;
	}
	return password;
}