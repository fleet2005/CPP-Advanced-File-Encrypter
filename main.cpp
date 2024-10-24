#include <iostream>
#include "encryption.h"
#include <string> //for getline

using namespace std;
//initially unit testing and then incremental integration testing
int main()
{
    start();
   
    string filename;
    char mode;

    cout<<"Enter the filename: ";
    getline(cin >> ws, filename);

    cout<<"\n\n";
    
    Sleep(3000);

    cout<< "Please enter (e) for Encryption or (d) for Decryption: ";
    cin>>mode;

    if(mode == 'e' || mode == 'E')
    {
        if(encryptFile(filename, true))
        {
            cout<<"";
        }
        else
        {
            cerr<< "\n\nEncryption failed"<<endl;
        }
    }

    else if(mode=='d'||mode =='D')
    {
        if(encryptFile(filename,false))
        {
            cout<< "\n\nDecryption Done"<<endl;
        }   
        else
        {
            cerr<<"\n\nDecryption Failed"<<endl;
        }
    }

    else
    {
        cerr<<"Please enter either 'e' or 'd' "<<endl;
    }

    end();

    cout<<"Press any key and Enter to Terminate\n"<<endl;
    char x;
    cin>>x;

    return 0;
}