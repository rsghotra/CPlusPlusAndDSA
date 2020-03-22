#include <iostream>
#include "Utils.h"

int main() {
  int x = 25;
  displayVariableInfo(x);
  int val;
  setValue(val);
  std::cout << "Value is set to " << val << std::endl;
  return 0;
}
