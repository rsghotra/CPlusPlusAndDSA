#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cctype>
#include <iomanip>

bool test_name(char *name, const int size) {
    for(int count=0;count<3;count++) {
        if(!isalpha(*(name + count))) return false;
    }
    for(int count=3;count<size-1;count++) {
        if(!isdigit(*(name + count))) return false;
    }
    return true;
}
//this function tests the customername in correct format or not
void validate_customer_name() {
    const int SIZE = 8; //null terminated string
    char customer[SIZE];
    std::cout << "Enter a customer name in the form: LLLNNNN\n";
    std::cout << "(LLL means letters and NNN means numbers.\n";
    std::cin.getline(customer, SIZE);
    if(test_name(customer, SIZE)) {
        std::cout << "That's a valid customer name.\n";
    }
    else {
        std::cout << "Bad name format.\n";
        std::cout << "Here is the example: ABC1234\n";
    }
    return;
}

void calculate_area_of_circle() {
    const double PI = 3.14;
    double radius;
    char goAgain;

    std::cout << "This program calculates the area of the circle.\n";
    std::cout << std::fixed << std::setprecision(2);

    //get the radius and display the area
    do
    {
        std::cout << "Enter the radius: ";
        std::cin >> radius;
        std::cout << "The area of the circle is: " << (PI * radius * radius) << std::endl;
        std::cout << "Do you want to continue: ";
        std::cin >> goAgain;
    }while(toupper(goAgain) == 'Y');
    return;
}

#endif