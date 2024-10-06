#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <fstream>
#include <iostream>
#include "VigenereCipher.h"
#include "Base64.h"
#include "Rot13.h"
#include "HybridAlgo.h"
#include "CaesarCipher.h"
#include "Starter.h"
#include "End.h"

using namespace std;

bool encryptFile(const string &filename, bool encrypt);

#endif 