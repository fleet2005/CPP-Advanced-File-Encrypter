#include "Rot13.h"

bool Rot13::encrypt(const string& text, const string& filename) {
    string result = text;
    for (char& c : result) {
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + 13) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + 13) % 26) + 'a';
        }
    }
    ofstream outFile("encrypted_" + filename);
    if (!outFile) {
        return false;
    }

    outFile << result;
    outFile.close();
    
    return true;
}

bool Rot13::decrypt(const string& text, const string& filename) {
    // In ROT13, encryption and decryption are the same
    return encrypt(text, filename);
}
