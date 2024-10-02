// CaesarCipher.h
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>
using namespace std;

class CaesarCipher{

    public:
        CaesarCipher(int shift);
        bool performCaesarCipher(string& content, bool encrypt, const string& filename);

    private:
        int shift;
};



#endif
