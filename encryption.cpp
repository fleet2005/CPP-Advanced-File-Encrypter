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
    cout << "Enter Your choice (1: Vigenere, 2: ROT-13, 3: Caesar, 4: Base-64, 5: Hybrid): ";
    cin >> choice;

    switch (choice)
    {
        case 1: {
            VigenereCipher vigenereCipher("CBA");
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
             
            HybridAlgo hybridAlgo("KEY"); 

            if (encrypt) {
                if (!hybridAlgo.encrypt(content, filename)) {
                    return false;
                }
            } else {
                if (!hybridAlgo.decrypt(content, filename)) {
                    return false;
                }
            }
            break;
        }

        default:
            cout << "Invalid choice." << endl;
            return false;
    }

    return true;
}
