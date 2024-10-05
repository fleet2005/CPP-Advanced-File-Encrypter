#include "HybridAlgo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>  

using namespace std;

HybridAlgo::HybridAlgo(const string& key) {
   
    for (char c : key) {
        if (isalpha(c)) {
            this->key += toupper(c);
        }
    }
}

// Encrypt function  Random ASCII Shift, Base64 Encode, and Vigenere Cipher
bool HybridAlgo::encrypt(const string& text, const string& filename) {
    // Random ASCII Shift
    string shiftedText = text;
    for (char& c : shiftedText) {
        c = static_cast<char>((c + rand() % 256) % 256); 
    }

    // Base64 Encoding
    static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string base64EncodedText;
    int val = 0;
    int valb = -6;
    for (unsigned char c : shiftedText) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            base64EncodedText.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) {
        base64EncodedText.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    }
    while (base64EncodedText.size() % 4) {
        base64EncodedText.push_back('=');
    }

    // Vigenere Cipher
    string finalEncryptedText;
    int keyIndex = 0;
    int keyLength = key.length();
    for (char c : base64EncodedText) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = toupper(c);
            int shift = key[keyIndex % keyLength] - 'A';
            char newChar = static_cast<char>((c - 'A' + shift + 26) % 26 + 'A');
            finalEncryptedText += isUpper ? newChar : tolower(newChar);
            keyIndex++;
        } else {
            finalEncryptedText += c; 
        }
    }

    
    ofstream outFile("encrypted_" + filename);
    if (!outFile) {
        return false; 
    }
    outFile << finalEncryptedText;
    outFile.close();
    return true;
}


bool HybridAlgo::decrypt(const string& text, const string& filename) {
    // Reverse Vigenere Cipher
    string base64DecodedText;
    int keyIndex = 0;
    int keyLength = key.length();
    for (char c : text) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            c = toupper(c);
            int shift = key[keyIndex % keyLength] - 'A';
            char newChar = static_cast<char>((c - 'A' - shift + 26) % 26 + 'A');
            base64DecodedText += isUpper ? newChar : tolower(newChar);
            keyIndex++;
        } else {
            base64DecodedText += c; 
        }
    }

    // Base64 Decoding
    static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    vector<int> base64_map(256, -1);
    for (int i = 0; i < 64; i++) base64_map[base64_chars[i]] = i;

    string shiftedText;
    int val = 0;
    int valb = -8;
    for (unsigned char c : base64DecodedText) {
        if (base64_map[c] == -1) break;
        val = (val << 6) + base64_map[c];
        valb += 6;
        if (valb >= 0) {
            shiftedText.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }

    // Reverse Random ASCII Shift
    string originalText = shiftedText;
    for (char& c : originalText) {
        c = static_cast<char>((c - rand() % 256 + 256) % 256);  
    }

    
    ofstream outFile("decrypted_" + filename);
    if (!outFile) {
        return false; 
    }
    outFile << originalText;
    outFile.close();
    return true;
}
