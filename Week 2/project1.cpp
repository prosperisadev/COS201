#include <iostream>

//Write a C++ code that reads 2 numbers and prints their sum, difference and product.
int main() {
    double num1, num2;

    // Read two numbers from the user
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Calculate sum, difference and product
    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;

    // Print the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}