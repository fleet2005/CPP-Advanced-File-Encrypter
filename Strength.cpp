#include "Strength.h"
#include <iostream>

using namespace std;

void evaluateKeyStrength() {
    string key;
    cout<<"\n\n\n\n\n"<<endl;
    cout << "Enter your encryption key: ";
    cin >> key;

    int lowerCount = 0, upperCount = 0, specialCount = 0;
    int length =0;

    Sleep(2000);
    
    //  key evaluation
    for (char c : key) {
        length++;
        if (islower(c)) {
            lowerCount++;
        } else if (isupper(c)) {
            upperCount++;
        } else if (!isalnum(c)) {
            specialCount++;
        }
    }

    // Strength Evaluation
    cout << "\nPassword Strength Evaluation: \n" << endl;
    if (lowerCount > 0) {
        cout << "- Contains lowercase characters\n" << endl;
    }
    if (upperCount > 0) {
        cout << "- Contains uppercase characters\n" << endl;
    }
    if (specialCount > 0) {
        cout << "- Contains special characters\n" << endl;
    }

    // Password Strength Calculation
    int strength = 0;
    if (lowerCount > 0) strength++;
    if (upperCount > 0) strength++;
    if (specialCount > 0) strength++;
    if (length>=12) strength++;

    cout << "Your password strength is: ";

    // Strength Bar

    switch (strength) {
        case 1:
            cout << "Weak\n" << endl;
            break;
        case 2:
            cout << "Moderate\n" << endl;
            break;
        case 3:
            cout << "Strong\n" << endl;
            break;
        case 4:
            cout<< "Very Strong\n" << endl;
            break;
        default:
            cout << "Very Weak\n" << endl;
            break;
    }

     
    cout << "Strength Bar: [";
    for (int i = 0; i < strength; i++) {
        cout << "#";  // Filled part
    }
    for (int i = strength; i < 4; i++) {
        cout << "-";  // Empty part
    }
    cout << "]\n\n";

    //  tips  
    if (strength < 3) {
        cout << "Tips to improve your password strength:\n\n";
        if (lowerCount == 0) {
            cout << "- Add some lowercase letters.\n";
        }
        if (upperCount == 0) {
            cout << "- Add some uppercase letters.\n";
        }
        if (specialCount == 0) {
            cout << "- Include special characters like @, #, $, etc.\n";
        }
        cout << "- Increase the length of your password to at least 8 characters.\n\n";
    }
}
