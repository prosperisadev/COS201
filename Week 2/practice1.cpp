#include <iostream>
using namespace std;
const double pi = 3.142;

int main() {
    double r;
    cout << "Hello user, enter the radius of the circle: ";
    cin >> r;
    double area = pi * r * r;
    cout << "The area of the circle is: " << area << endl;
    return 0;
}