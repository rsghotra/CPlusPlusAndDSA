#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <chrono>

auto get_time_now() {
    return std::chrono::high_resolution_clock::now();
}

auto calculate_run_time(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point stop) {
    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

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
    //various manipulations and test
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

//this program displays string strored as C-String

void display_c_string() {
    const int SIZE = 10;
    char line[SIZE];
    std::cout << "Enter a sentence of size " << (SIZE - 1) << " characters.\n";
    std::cin.getline(line, SIZE);
    //cctype and cstring library functions
    std::cout << "The length of the string entered is: " << strlen(line) << std::endl;
    std::cout << "The string you entered is: " << line << std::endl;
    //concatenation
    const int SIZE2 = 5;
    char line2[SIZE2];
    std::cout << "Enter a sentence of size " << (SIZE2 - 1) << " characters.\n";
    std::cin.getline(line2, SIZE2);
    int maxChars = sizeof(line) - (strlen(line) + 1);
    strncpy(line, line2, maxChars);
    int count = 0;
    while(line[count] != '\0') {
        std::cout << line[count];
        count++;
    }
    return;
}

bool is_prime(int x) {
    int i;
    int prime = 1;
    for(int i = 2; i < x; i++) {
        if((x%i) == 0) {
            prime = 0;
        }
    }
    return prime;
}

void is_prime() {
    int count = 0;
    int number = 2;
    auto start = get_time_now();
    while(count < 10000) {
        if(is_prime(number)) {
            std::cout << number << std::endl;
            count++;
        }
        number++;
    }
    auto stop = get_time_now();
    auto duration = calculate_run_time(start, stop);
    std::cout << "Runtime: " << duration.count() << std::endl;
    return;
}

#endif