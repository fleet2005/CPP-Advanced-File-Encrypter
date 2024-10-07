@echo off
  
g++ main.cpp encryption.cpp VigenereCipher.cpp Rot13.cpp CaesarCipher.cpp Base64.cpp HybridAlgo.cpp Starter.cpp End.cpp info.cpp -o encryptionApp
 
if %errorlevel% neq 0 (
    echo Compilation failed. Please check the code for errors.
) else (
    echo Compilation successful. Running the program...
    start cmd /c encryptionApp
)

pause
