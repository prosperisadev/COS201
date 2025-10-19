#include <iostream>
//Write a C++ program that swaps the value of 2 integers using a temporary variable

int main() {
    int a, b, temp;

    // Read two integers from the user
    std::cout << "Enter first integer (a): ";
    std::cin >> a;
    std::cout << "Enter second integer (b): ";
    std::cin >> b;

    // Display values before swapping
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    // Swap the values using a temporary variable
    temp = a;
    a = b;
    b = temp;

    // Display values after swapping
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}