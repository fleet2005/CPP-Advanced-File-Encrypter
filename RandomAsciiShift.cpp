#include "RandomAsciiShift.h"
#include <cstdlib>    
#include <ctime>    

int RandomAsciiShift::getRandomShift() {
    srand(time(0));  
    return rand() % 256;  
}

bool RandomAsciiShift::encrypt(const string& text, const string& filename) {
    string result = text;
    int shift = getRandomShift();
    
    for (char& c : result) {
        c = (c + shift) % 256;  
    }
    

    ofstream outFile("encrypted_" + filename);
    if (!outFile) {
        return false;
    }

    outFile << result;
    outFile.close();
    return true;
}

bool RandomAsciiShift::decrypt(const string& text, const string& filename) {
    string result = text;
    int shift = getRandomShift();
    
    for (char& c : result) {
        c = (c - shift + 256) % 256;  
    }

    ofstream outFile("decrypted_" + filename);
    if (!outFile) {
        return false;
    }

    outFile << result;
    outFile.close();

    return true;
}
