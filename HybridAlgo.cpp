#include "HybridAlgo.h"
#include <fstream> //for file handling
#include <iostream> //cincout
#include <vector> //for base 64 decoding
#include <cctype> // For tolower and toupper
#include <cstdlib>   // for rand() and srand()
#include <ctime>    // For time(0) to seed rand()

using namespace std;

HybridAlgo::HybridAlgo(const string& key) {
    // Convert the key to uppercase for Vigenere cipher
    for (char c : key) {
        if (isalpha(c)) {
            this->key += toupper(c);
        }
    }
}

// Encrypt function with a single Random ASCII Shift, Base64 Encode, and Vigenere Cipher
bool HybridAlgo::encrypt(const string& text, const string& filename, int& shiftValue) {
    // Initialize random seed and generate a single random shift value
    srand(time(0));
    shiftValue = rand() % 256;

    // Random ASCII Shift using the single shift value
    string shiftedText = text;
    for (char& c : shiftedText) {
        c = static_cast<char>((c + shiftValue) % 256);
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
            base64EncodedText.push_back(base64_chars[(val >> valb) & 0x3F]); //00111111 6 bits
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

    // Save encrypted text to file
    ofstream outFile("encrypted_" + filename);
    if (!outFile) {
        return false; 
    }
    outFile << finalEncryptedText;
    outFile.close();
    cout<<"\n Your Shift Value is : "<< shiftValue << endl;
    return true;
}

// Decrypt function using the provided shift value
bool HybridAlgo::decrypt(const string& text, const string& filename, int& shiftValue) {
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
    for (int i = 0; i < 64; i++) base64_map[base64_chars[i]] = i; //101 vc //100 str

    string shiftedText;
    int val = 0;
    int valb = -8;
    for (unsigned char c : base64DecodedText) {
        if (base64_map[c] == -1) break;
        val = (val << 6) + base64_map[c];
        valb += 6;
        if (valb >= 0) {
            shiftedText.push_back(char((val >> valb) & 0xFF)); // 11111111 8 bits
            valb -= 8;
        }
    }

    // Reverse Random ASCII Shift using the provided single shift value
    string originalText = shiftedText;
    for (char& c : originalText) {
        c = static_cast<char>((c - shiftValue + 256) % 256);
    }

    // Save decrypted text to file
    ofstream outFile("decrypted_" + filename);
    if (!outFile) {
        return false; 
    }
    outFile << originalText;
    outFile.close();
    return true;
}
