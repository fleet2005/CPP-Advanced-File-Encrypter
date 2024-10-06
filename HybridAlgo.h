#ifndef HYBRID_ALGO_H
#define HYBRID_ALGO_H

#include <string>
using namespace std;

class HybridAlgo {
public:
     
    HybridAlgo(const string& key); 
     
    bool encrypt(const string& text, const string& filename, int& shiftValue);
     
    bool decrypt(const string& text, const string& filename, int& shiftValue);

private:
    string key;   
};

#endif  
