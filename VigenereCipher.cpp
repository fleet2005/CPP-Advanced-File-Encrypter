#include "VigenereCipher.h"
#include <fstream>
#include <cctype> //isalpha, toupper

using namespace std;

VigenereCipher::VigenereCipher(const string& key) {
    for (char c : key) {
        if (isalpha(c)) {
            this->key += toupper(c);  
        }
    }
}

bool VigenereCipher::encrypt(const string& text, const string& filename) {
    string result;
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = toupper(c);
            int shift = key[keyIndex % keyLength] - 'A';
            result += shiftChar(c, shift);  
            keyIndex++;
            if (!isUpper) result.back() = tolower(result.back());  
        } else {
            result += c;  
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

bool VigenereCipher::decrypt(const string& text, const string& filename) {
    string result;
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = toupper(c);
            int shift = key[keyIndex % keyLength] - 'A';
            result += shiftChar(c, -shift);  
            keyIndex++;
            if (!isUpper) result.back() = tolower(result.back());  
        } else {
            result += c;  
        }
    }

    ofstream outFile("decrypted_" + filename);
    if (!outFile) {
        return false;  
    }

    outFile << result;
    outFile.close();

    return true;
}

char VigenereCipher::shiftChar(char c, int shift) {
     
    char shifted = (c - 'A' + shift + 26) % 26 + 'A';
    return shifted;
}
