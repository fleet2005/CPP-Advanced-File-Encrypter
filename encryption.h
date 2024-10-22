#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string> //string content
#include <fstream>
#include <iostream> 
#include <windows.h> //for sleep
#include "VigenereCipher.h"
#include "Base64.h"
#include "Rot13.h"
#include "HybridAlgo.h"
#include "CaesarCipher.h"
#include "Starter.h"
#include "End.h"
#include "info.h"
#include "Strength.h"

using namespace std;

bool encryptFile(const string &filename, bool encrypt);

#endif 