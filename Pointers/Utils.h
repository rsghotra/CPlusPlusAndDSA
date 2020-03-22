#ifndef UTILS_H
#define UTILS_H

void displayVariableInfo(int val) {
  std::cout << "The address of variable is " << &val << std::endl;
  std::cout << "The size of valriable is " << sizeof(val) << " bytes\n";
  std::cout << "The value of variable is " << val << std::endl;
  return;
}

//setReference variable value
void setValue(int &val) {
  std::cout << "what value you would like to set? " << std::endl;
  std::cin >> val;
  return;
}
#endif