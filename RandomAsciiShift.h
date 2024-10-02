#ifndef RANDOM_ASCII_SHIFT_H
#define RANDOM_ASCII_SHIFT_H

#include <string>
#include <fstream>
using namespace std;

class RandomAsciiShift {
    public:
        bool encrypt(const string& text, const string& filename);
        bool decrypt(const string& text, const string& filename);
        
    private:
        static int getRandomShift();   
};

#endif // RANDOM_ASCII_SHIFT_H
