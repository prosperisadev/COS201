#include <iostream>
#include <cstdlib>
using namespace std;

bool verifyPin(int correctPin) {
    int enteredPin;
    int attempts = 0; 
    while (attempts < 3) {
        cout << "Please input your pin: ";
        cin >> enteredPin;
        if (enteredPin == correctPin) {
            return true; 
        }
        attempts++;
        if (attempts < 3) {
            cout << "Incorrect pin, please try again.\n";
        }
    }
    return false; 
}

void displayMenu() {
    cout << "\n=== ATM Main Menu ===\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Cash\n";
    cout << "3. Withdraw Cash\n";
    cout << "4. Reset Pin\n";
    cout << "5. Exit\n";
}

double depositMoney (double balance) {
    double deposit_amount;
    cout << "Enter amount to deposit: ₦";
    cin >> deposit_amount;
    if (deposit_amount > 0) {
        balance += deposit_amount;
        cout << "You have successfully deposited ₦" << deposit_amount << "\n";
    } else {
        cout << "Invalid deposit amount.\n";
    }
    return balance;
}

double viewBalance (double balance) {
    cout << "Your current balance is: ₦" << balance << "\n";
    return balance;
}

double withdrawMoney (double balance, double daily_limit) {
    double withdraw_amount;
    cout << "Enter amount to withdraw: ₦";
    cin >> withdraw_amount;
    if (withdraw_amount > 0 && withdraw_amount <= daily_limit && withdraw_amount <= balance) {
        balance -= withdraw_amount;
        cout << "You have successfully withdrawn ₦" << withdraw_amount << "\n";
    } else if (withdraw_amount > daily_limit) {
        cout << "Withdrawal amount exceeds daily limit of ₦" << daily_limit << "\n";
    } else if (withdraw_amount > balance) {
        cout << "Insufficient balance.\n";
    } else {
        cout << "Invalid withdrawal amount.\n";
    }
    return balance;
}

int resetPin (int currentPin){
    int old_pin;
    int new_pin;

    cout << "Enter your old PIN to confirm: ";
    cin >> old_pin;

    if (old_pin == currentPin) {
        cout << "Input your new pin: ";
        cin >> new_pin;
        cout << "Your pin has been successfully changed.\n";
        return new_pin; // Return the new PIN to update main()
    } else {
        cout << "Incorrect old PIN. Reset failed.\n";
        return currentPin; // Return the old PIN unchanged
    }
}



int main(){

    int pin = 4321;
    double account = 50000;
    double daily_limit = 20000;

    if (!verifyPin(pin)) {
        cout << "Account Locked. Please contact your bank.\n";
        return 0; // Stop the program if PIN fails
    }

    int choice;
    do {
        displayMenu();
        cout << "Select an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewBalance(account);
                break;
            case 2:
                account = depositMoney(account);
                break;
            case 3:
                account = withdrawMoney(account, daily_limit);
                break;
            case 4:
                resetPin(pin);
                break;
            case 5:
                cout << "Thank you for using the ATM. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

}