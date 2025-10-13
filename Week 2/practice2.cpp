#include <iostream>
using namespace std;

// Print star into a pattern of alphabet A
#include <iostream>
using namespace std;

int main() {
    int n = 7;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            // Conditions for 'A'
            if (
                j == 0 && i != 0 ||                // left diagonal
                j == n && i != 0 ||                // right diagonal
                i == 0 && j != 0 && j != n ||      // top horizontal bar
                i == n / 2                         // middle horizontal bar
            )
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

