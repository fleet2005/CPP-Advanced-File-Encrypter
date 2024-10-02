#include "HybridAlgo.h"

HybridAlgo::HybridAlgo(const string& key) : vigenere(key), key(key) {}

bool HybridAlgo::encrypt(const string& text, const string& filename) {
     
    string shiftedText = RandomAsciiShift::encrypt(text);
        
    string base64EncodedText = Base64::encode(shiftedText); 
     
    string finalEncryptedText = vigenere.encrypt(base64EncodedText);
    
    return finalEncryptedText;
}

bool HybridAlgo::decrypt(const string& text) {
     
    string base64DecodedText = vigenere.decrypt(text);
    
    
    string shiftedText = Base64::decode(base64DecodedText);
    
     
    string originalText = RandomAsciiShift::reverseShift(shiftedText);
    
    return originalText;
}
