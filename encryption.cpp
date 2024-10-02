#include "encryption.h"
using namespace std;

bool encryptFile(const string& filename, bool encrypt)
{
    ifstream inFile(filename);
    
    if (!inFile) {
        return false;
    }

    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    int choice = 0;
    cout << "Enter Your choice (1: Vigenere, 2: Base64, 3: Caesar, 4: Rot13, 5: Hybrid): ";
    cin >> choice;

    switch (choice)
    {
        case 1: {
            VigenereCipher vigenereCipher("YOUR_KEY_HERE");
            if (encrypt) {
                if (!vigenereCipher.encrypt(content, filename)) {
                    return false;
                }
            } else {
                if (!vigenereCipher.decrypt(content, filename)) {
                    return false;
                }
            }
            break;
        }

        case 2: {
            Rot13 rot13;
            if (encrypt) {
                if (!rot13.encrypt(content, filename)) {
                    return false;
                }
            } else {
                if (!rot13.decrypt(content, filename)) {
                    return false;
                }
            }
            break;
        }

       case 3: {
            CaesarCipher caesarCipher(2);  //Enter shift key
            if (!caesarCipher.performCaesarCipher(content, encrypt, filename)) {  
                return false;
            }
            break;  
        }

        case 4: {
            Base64 base64;
            if (encrypt) {
                if (!base64.encrypt(content, filename)) {
                    return false;
                }
            } else {
                if (!base64.decrypt(content, filename)) {
                    return false;
                }
            }
            break;
        }

        case 5: {
             
            //Hybrid Algorithm
        }

        default:
            cout << "Invalid choice." << endl;
            return false;
    }

    return true;
}
