#include "encryption.h"
 
 
bool encryptFile(const string& filename, bool encrypt) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return false;
    }

    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    int choice = 0;
    while (true) {  
        Sleep(2000);
        cout<<"\n\n\n";
        cout << R"(
    Enter Your Choice of Encryption/Decryption Algorithm:
    
    0: Help Manual 
    1: Vigenere Cipher
    2: ROT-13 Encryption
    3: Caesar Cipher
    4: Base-64 Encryption
    5: Hybrid Encryption
    6: Key Strength Checker
    7: Exit
    )";

        cout << "\n\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 0: {
                info();   
                break;  
            }
            case 1: {
                string key;
                cout << "Enter the KEY: ";
                cin >> key;
                VigenereCipher vigenereCipher(key);

                if (encrypt) {
                    if (!vigenereCipher.encrypt(content, filename)) {
                        return false;
                    }
                } else {
                    if (!vigenereCipher.decrypt(content, filename)) {
                        return false;
                    }
                }
                return true;
                break;
            }
            case 2: {
                Rot13 rot13;
                if (encrypt) {
                    if (!rot13.encrypt(content, filename)) return false;
                } else {
                    if (!rot13.decrypt(content, filename)) return false;
                }
                return true;
                break;
            }
            case 3: {
                int shift;
                cout << "Enter the Shifting Value: ";
                cin >> shift;
                CaesarCipher caesarCipher(shift);

                if (!caesarCipher.performCaesarCipher(content, encrypt, filename)) {
                    return false;
                }
                return true;
                break;
            }
            case 4: {
                Base64 base64;
                if (encrypt) {
                    if (!base64.encrypt(content, filename)) return false;
                } else {
                    if (!base64.decrypt(content, filename)) return false;
                }
                return true;
                break;
            }
            case 5: {
                string key;
                cout << "Enter the KEY: ";
                cin >> key;
                HybridAlgo hybridAlgo(key);
                int shiftValue = 0;

                if (encrypt) {
                    if (!hybridAlgo.encrypt(content, filename, shiftValue)) return false;
                } else {
                    cout << "Enter the shift value used during encryption: ";
                    cin >> shiftValue;
                    if (!hybridAlgo.decrypt(content, filename, shiftValue)) return false;
                }
                return true;
                break;
            }
            case 6: {
                evaluateKeyStrength();   
                return true;
                break;
            }
            case 7: {
                cout << "Exiting program. Goodbye!" << endl;
                return true;   
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return true;
}

