#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

#include <string>
using namespace std;

class VigenereCipher {
public:
    VigenereCipher(const string& key);        
    bool encrypt(const string& text, const string& filename);    
    bool decrypt(const string& text, const string& filename);    

private:
    string key;                               
    char shiftChar(char c, int shift);       
};

#endif // VIGENERE_CIPHER_H
