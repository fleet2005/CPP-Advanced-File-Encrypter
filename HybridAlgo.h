#ifndef HYBRID_ALGO_H
#define HYBRID_ALGO_H

#include <string>
using namespace std;

class HybridAlgo {
public:
     
    HybridAlgo(const string& key); 
     
    bool encrypt(const string& text, const string& filename);
     
    bool decrypt(const string& text, const string& filename);

private:
    string key;   
};

#endif  
