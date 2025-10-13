#include <iostream>
//practicing pre or post increment/decrement
using namespace std;
int main() {
    int a = 5;
    cout << "Initial value of a: " << a << endl;

    // Post-increment
    cout << "Post-increment a++: " << a++ << endl; // Outputs 5, then a becomes 6
    cout << "Value of a after post-increment: " << a << endl; // Outputs 6

    // Pre-increment
    cout << "Pre-increment ++a: " << ++a << endl; // a becomes 7, then outputs 7
    cout << "Value of a after pre-increment: " << a << endl; // Outputs 7

    // Post-decrement
    cout << "Post-decrement a--: " << a-- << endl; // Outputs 7, then a becomes 6
    cout << "Value of a after post-decrement: " << a << endl; // Outputs 6

    // Pre-decrement
    cout << "Pre-decrement --a: " << --a << endl; // a becomes 5, then outputs 5
    cout << "Value of a after pre-decrement: " << a << endl; // Outputs 5

    return 0;
}