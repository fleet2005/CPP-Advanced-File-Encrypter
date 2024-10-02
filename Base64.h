#ifndef BASE64_H
#define BASE64_H

#include <string>
#include <fstream>
using namespace std;

class Base64 {
public:
    bool encrypt(const string& input, const string& filename);
    bool decrypt(const string& input, const string& filename);
};

#endif // BASE64_H
