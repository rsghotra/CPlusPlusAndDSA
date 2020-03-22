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

//display array

void showArrayValues(int values[], int size) {
  for (int count = 0; count < size; count++) {
    std::cout << values[count] << std::endl;
  }
  return;
}

//basic pointer declaration
void display_ptr() {
  int value;
  std::cout << "Please enter an int value :" << std::endl;
  std::cin >> value;
  int *ptr;
  ptr = &value;
  std::cout << "The value of val is " << value << std::endl;
  std::cout << "The address of val is " << ptr << std::endl;
  return;
}

//this program demonstrates the use of indirection operator.
void indirection_operator() {
  int x = 25;
  int *ptr;
  ptr = &x;

  std::cout << "Here is value of x printed twice:\n";
  std::cout << x << std::endl;
  std::cout << *ptr << std::endl;

  //assign a new value to x;
  *ptr = 100;
  std::cout << "Here is value of x printed twice:\n";
  std::cout << x << std::endl;
  std::cout << *ptr << std::endl;

  int y = 35;
  int z = 45;

  ptr = &y;
  *ptr += 100;
  ptr = &z;
  *ptr +=100;
  std::cout << "The value of x is " << x << " the value of y is " << y << " the value of z is " << z << std::endl;
  return;
}

#endif