#include "Base64.h"
#include <vector>

static const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

bool Base64::encrypt(const string& input, const string& filename) {
    string encoded;
    int val = 0, valb = -6;
    
    for (char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            encoded.push_back(BASE64_CHARS[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6) encoded.push_back(BASE64_CHARS[((val << 8) >> (valb + 8)) & 0x3F]);

    while (encoded.size() % 4) encoded.push_back('=');
    
    ofstream outFile("encrypted_" + filename);
    if (!outFile) {
        return false;
    }

    outFile << encoded;
    outFile.close();
    
    return true;
}

bool Base64::decrypt(const string& input, const string& filename) {
    vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T[BASE64_CHARS[i]] = i;
    
    string decoded;
    int val = 0, valb = -8;
    
    for (char c : input) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            decoded.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    
    ofstream outFile("decrypted_" + filename);
    if (!outFile) {
        return false;
    }

    outFile << decoded;
    outFile.close();

    return true;
}
