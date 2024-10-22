#include "CaesarCipher.h"
#include <cctype>
#include <string.h>
#include <fstream>

using namespace std;
//The scope resolution operator (::) is essential for 
//defining member functions and constructors outside of the class declaration.

CaesarCipher::CaesarCipher(int shift) : shift(shift) {} //1st shift is parameter value, 2nd is private member variable which stores the shift value, and 3rd is again the parameter value which gets assigned to the 2nd shift(private member)
//same as this->shift = shift;

bool CaesarCipher::performCaesarCipher(string& content, bool encrypt, const string& filename)
{
    int effectiveShift = encrypt ? shift : -shift;

    for(char& ch:  content)
    {
        if(isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch-base+effectiveShift+26)%26 + base);
        }
    }

    ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename);
    if (!outFile) {
        return false; 
        }
    outFile << content;  
    outFile.close();  
    
    return true;  
}