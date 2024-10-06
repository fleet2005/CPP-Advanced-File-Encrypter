#include <iostream>
#include "encryption.h"
#include <string>

using namespace std;

int main()
{
    start();
   
    string filename;
    char mode;

    cout<<"Enter the filename: ";
    getline(cin >> ws, filename);

    cout<< "Encrypt(e) or Decrypt(d)?";
    cin>>mode;

    if(mode == 'e' || mode == 'E')
    {
        if(encryptFile(filename, true))
        {
            cout<< "Encryption Done"<<endl;
        }
        else
        {
            cerr<< "Encryption failed"<<endl;
        }
    }

    else if(mode=='d'||mode =='D')
    {
        if(encryptFile(filename,false))
        {
            cout<< "Decryption Done"<<endl;
        }   
        else
        {
            cerr<<"Decryption Failed"<<endl;
        }
    }

    else
    {
        cerr<<"Please enter either 'e' or 'd' "<<endl;
    }

    end();

    return 0;
}