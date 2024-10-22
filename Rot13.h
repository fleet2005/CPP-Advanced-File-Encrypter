#ifndef ROT13_H
#define ROT13_H

#include <string> //string result
#include <fstream>
using namespace std;

class Rot13 {
public:
    bool encrypt(const string& text, const string& filename);
    bool decrypt(const string& text, const string& filename);
};

#endif // ROT13_H
