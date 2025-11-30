#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string admissioncheck(int jamb_score, double waec_average, int age, bool first_choice, bool disciplinary){
    string admission_status;
    if (((jamb_score >= 220 && waec_average >= 60) || (jamb_score >= 200 && waec_average >= 70)) && first_choice == true){
        admission_status = "Admitted";
        if (age < 15 || disciplinary == true){
            admission_status = "Rejected";
        }
    }
    else {
        admission_status = "Pending";
    }
    return admission_status;
}

int scholarship(int jamb_score, int waec_average, bool first_choice, string admission_status){
    int scholarship_percentage = 0;
    if (admission_status != "Admitted") {
        return scholarship_percentage; 
    }
    if (jamb_score >= 320) {
        scholarship_percentage = 30;
        if (waec_average >= 80 && first_choice == true) {
           scholarship_percentage = 35;
        }
    }
    else if (jamb_score >= 280) {
        scholarship_percentage = 20;
        if (waec_average >= 80 && first_choice == true) {
           scholarship_percentage = 25;
        }
    }
    else if (jamb_score >= 240) {
        scholarship_percentage = 10;
        if (waec_average >= 80 && first_choice == true) {
           scholarship_percentage = 15;
        }
    }
    else {
        scholarship_percentage = 0;
    }
    return scholarship_percentage;
}

int hostel(bool disciplinary, int hostel_choice , string admission_status){
    int hostel_fee = 0;
    if (admission_status == "Admitted" && disciplinary == false){
        switch (hostel_choice) {
            case 1:
                hostel_fee = 180000;
                break;
            case 2:
                hostel_fee = 120000;
                break;
            case 3:
                hostel_fee = 0;
                break;
            default:
                hostel_fee = 0;
        }
    }
    return hostel_fee;

}

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int randmeritgrant(string admission_status, int &lucky_number) {
    int grant_amount = 0;
    lucky_number = (rand() % 100) + 1; // generates a number between 1 and 100
    if (admission_status == "Admitted" && lucky_number <= 97 && isPrime(lucky_number)) {
        grant_amount = 50000;
    }
    return grant_amount;
}


int main() {
    srand(time(0));
    string name;
    cout << "Welcome to the PAU Tuition & Scholarship Platform \n";
    cout << "Please enter your full name: \n";
    getline(cin, name);
    int jamb_score;
    cout << "Please enter your JAMB Score | From 0-400\n";
    cin >> jamb_score;
    double waec_average;
    cout << "Please enter your WAEC Average | From 0-100\n";
    cin >> waec_average;
    int age;
    cout << "How old are you | Input number only\n";
    cin >> age;
    bool first_choice;
    cout << "Is PAU your first choice | true or false\n";
    cin >> boolalpha >> first_choice;
    bool disciplinary;
    cout << "Do you have any disciplinary records | true or false \n";
    cin >> boolalpha >> disciplinary;
    int hostel_choice;
    cout << "What's your hostel preference \n1. Main Hostel (N180,000), \n2. Annex Hostel (N120,000)\n3. Day Student (Nil)\n";
    cin >> hostel_choice;

    int random_number = 0;
    string admission_status1 = admissioncheck(jamb_score, waec_average, age, first_choice, disciplinary);
    int scholarship_status1 = scholarship(jamb_score, waec_average, first_choice, admission_status1);
    int hostel_fee1 = hostel(disciplinary, hostel_choice, admission_status1);
    int merit_grant1 = randmeritgrant(admission_status1, random_number);

    cout << "Full Name: " << name << "\n";
    cout << "Admission Status: " << admission_status1 << "\n";
    cout << "Scholarship Percentage: " << scholarship_status1 << "%\n";
    cout << "Hostel Fee: ₦" << hostel_fee1 << "\n";\
    cout << "Merit Grant: ₦" << merit_grant1 << "\n";
    cout << "Random Merit Number Grant Check: " << random_number << "\n";
 
    int final_payable = 1500000 - (scholarship_status1 * 1500000 / 100) - merit_grant1 + hostel_fee1;
    cout << "Your Tuition Fee is ₦" << final_payable << "\n";
    cout << "Thank you for using the PAU Tuition & Scholarship Platform";
    cout << "Goodbye " << name;

}
