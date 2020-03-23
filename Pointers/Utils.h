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

void display_first_array_emenent() {
  int numbers[] = {1, 3, 4, 5, 6};
  std::cout << "The first element of the array is: ";
  std::cout << *numbers <<  std::endl;
}

void print_array_using_pointer() {
  const int SIZE = 5;
  int numbers[SIZE];
  int count;

  std::cout << "Please enter " << SIZE << " numbers: ";
  for(count=0;count<SIZE;count++) {
    std::cin >> *(numbers + count);
  }

  //display the array using pointer notation
  std::cout << "Here are the numbers you had entered.\n";
  for(count=0;count<SIZE;count++) {
    std::cout << *(numbers + count) << " ";
  }
  std::cout << "\nThe array is finished.\n";
  return;
}

void print_array_using_pointer_subscript() {
  const int NUM_COINS = 5;
  double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
  double *doublePtr = coins;
  int count;
  std::cout << "Pointer using array subscript notation to access the elements.\n";
  for(count=0;count<NUM_COINS;count++) {
    std::cout << doublePtr[count] << " ";
  }

  std::cout << "\nArray using pointer arithmetic.\n";
  for(count=0;count<NUM_COINS;count++) {
    std::cout << *(coins + count) << " ";
  }
}

void print_array_using_address_of_elements() {
  const int NUM_COINS = 5;
  double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
  double *doublePtr;
  int count;
  std::cout << "\nDisplaying Array using address& operator on each element of array.\n";
  for(count=0;count<NUM_COINS;count++) {
    doublePtr = &coins[count];
    std::cout << *doublePtr << " ";
  }
  std::cout << std::endl;
}

void print_reverse_array_using_pointer() {
  const int NUM_COINS = 5;
  double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
  double *doublePtr = coins;
  int count;
  std::cout << "\nDisplaying Array in reverse order.\n";
  for(count=0;count<NUM_COINS;count++) {
    doublePtr++;
  }
  for(count=0;count<NUM_COINS;count++) {
    doublePtr--;
    std::cout << *doublePtr << " "; 
  }
  std::cout << std::endl;
}

//this function displays the array in reverse order by comparing pointer address.
void print_array_in_reverse_using_ptr_comparison() {
  int set[8] = {52, 47,56, 3, 4, 2, 1, 5};
  int *nums = set;
  //display the array.
  std::cout << "The numbers in the array are: " << std::endl;
  std::cout << *nums << " ";

  while(nums < &set[7]) {
    nums++;
    std::cout << *nums << " ";
  }

  std::cout << "\nDisplaying the number in backward order: " << std::endl;
  std::cout << *nums << " ";
  while(nums > set) {
    nums--;
    std::cout << *nums << " ";
  }
  return;
}

void doubleValue(int *val) {
  *val *= 2;
}

void getValue(int *input) {
  std::cout << "Enter your number: ";
  std::cin >> *input;
}

#endif