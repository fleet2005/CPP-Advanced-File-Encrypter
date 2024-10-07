#include "Strength.h"
#include <iostream>

using namespace std;

void evaluateKeyStrength() {
    string key;
    cout << "Enter your encryption key: ";
    cin >> key;

    int lowerCount = 0, upperCount = 0, specialCount = 0;

    
    for (char c : key) {
        if (islower(c)) {
            lowerCount++;
        } else if (isupper(c)) {
            upperCount++;
        } else if (!isalnum(c)) {
            specialCount++;
        }
    }

   
    cout << "\nPassword Strength Evaluation: \n" << endl;
    if (lowerCount > 0) {
        cout << "- Contains lowercase characters\n\n" << endl;
    }
    if (upperCount > 0) {
        cout << "- Contains uppercase characters\n\n" << endl;
    }
    if (specialCount > 0) {
        cout << "- Contains special characters\n\n" << endl;
    }

    int strength = 0;
    if (lowerCount > 0) strength++;
    if (upperCount > 0) strength++;
    if (specialCount > 0) strength++;

    cout<<"Your password strength is : ";

    switch (strength) {
        case 1:
            cout<<"Weak\n\n"<<endl;
            break;
        case 2:
            cout<<"Moderate\n\n"<<endl;
            break;
        case 3:
            cout<<"Strong\n\n"<<endl;
            break;

        default:
            cout<<"Very Weak\n\n"<<endl;
            break;
    }

}
