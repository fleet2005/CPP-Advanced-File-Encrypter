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
    cout << R"(
    Enter Your choice of Encryption/Decryption Algorithm :
    0: Help Manual 
    1: Vigenere Cipher
    2: ROT-13 Encryption
    3: Caesar Cipher
    4: Base-64 Encryption
    5: Hybrid Encryption
    6: Key Strength Checker
     )";

    cin >> choice;

    switch (choice)
    {
        case 0: {
            info();
            break;
        }
        
        case 1: {
            string temp;
            cout<<"\nPlease Enter the KEY\n"<<endl;
            cin>>temp;
            VigenereCipher vigenereCipher(temp);
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
            int temp1;
            cout<<"\nPlease Enter the Shifting Value\n"<<endl;
            cin>>temp1;
            CaesarCipher caesarCipher(temp1);  
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
             
            string temp3;
            cout<<"\nPlease Enter the KEY\n"<<endl;
            cin>>temp3;

            HybridAlgo hybridAlgo(temp3); 
            int val = 0;

            if (encrypt) {
                int shiftValue = 0;
                if (!hybridAlgo.encrypt(content, filename, shiftValue)) {
                    return false;
                }
            } else { 
                int shiftValue;  
                cout << "\nEnter the shift value used during encryption: "<<endl;
                cin >> shiftValue;
                if (!hybridAlgo.decrypt(content, filename, shiftValue)) {
                    return false;
                }
            }
            break;
        }

       case 6: {
            evaluatePasswordStrength();
            break;  
        }

        default:
            cout << "Invalid choice." << endl;
            return false;

    }

    return true;
}
