#include <iostream>
#include "Utils.h"

int main() {
  int number;
  getValue(&number);
  doubleValue(&number);
  std::cout << "Number is: " << number;
  return 0;
}