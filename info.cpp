#include "info.h"
using namespace std;

void info()
{
cout<<"\n\n"<<endl;

cout << R"(
        /==========================================================================\
        ||                           ENCRYPTION APP HELP MANUAL                   ||
        ||========================================================================||
        ||                                                                        ||
        || 1. Vigenere Cipher                                                     ||
        ||    ----------------                                                    ||
        ||    What it does:                                                       ||
        ||    The Vigenere cipher is a method of encrypting alphabetic text by    ||
        ||    using a series of different Caesar ciphers based on the letters of  ||
        ||    a keyword.                                                          ||
        ||                                                                        ||
        ||    How it works:                                                       ||
        ||    Each letter in the plaintext is shifted along some number of        ||
        ||    positions defined by the corresponding letter of the keyword.       ||
        ||    The shift is cyclical, so the keyword repeats itself for long       ||
        ||    messages.                                                           ||
        ||                                                                        ||
        ||    Usage:                                                              ||
        ||    1. Enter the text to be encrypted or decrypted.                     ||
        ||    2. Provide a keyword for the cipher.                                ||
        ||    3. The algorithm shifts each letter based on the keyword provided.  ||
        ||                                                                        ||
        || 2. Caesar Cipher                                                       ||
        ||    ---------------                                                     ||
        ||    What it does:                                                       ||
        ||    The Caesar cipher is a substitution cipher where each letter in the ||
        ||    plaintext is shifted by a fixed number of positions in the alphabet.||
        ||                                                                        ||
        ||    How it works:                                                       ||
        ||    A uniform shift value (e.g., 3) is chosen, and each letter in the   ||
        ||    plaintext is shifted by that many positions.                        ||
        ||    For example, with a shift of 3, A becomes D, B becomes E, and so on.||
        ||                                                                        ||
        ||    Usage:                                                              ||
        ||    1. Enter the text to be encrypted or decrypted.                     ||
        ||    2. Provide the shift value (number of positions to shift).          ||
        ||    3. The text will be transformed by shifting all characters uniformly||
        ||       by the chosen value.                                             ||
        ||                                                                        ||
        || 3. Base64 Encoding                                                     ||
        ||    ----------------                                                    ||
        ||    What it does:                                                       ||
        ||    Base64 is an encoding scheme that converts binary data into an      ||
        ||    ASCII string format by encoding it into a base 64 representation.   ||
        ||                                                                        ||
        ||    How it works:                                                       ||
        ||    It divides the binary data into chunks of 6 bits and maps them to   ||
        ||    a set of 64 printable characters (A-Z, a-z, 0-9, +, /). Padding     ||
        ||    characters '=' are added if the input length is not divisible by 3. ||
        ||                                                                        ||
        ||    Usage:                                                              ||
        ||    1. Provide the data to be encoded or decoded.                       ||
        ||    2. The algorithm converts the input to/from Base64 format.          ||
        ||                                                                        ||
        || 4. Rot13 Cipher                                                        ||
        ||    -------------                                                       ||
        ||    What it does:                                                       ||
        ||    Rot13 is a simple letter substitution cipher that replaces a letter ||
        ||    with the 13th letter after it in the alphabet.                      ||
        ||                                                                        ||
        ||    How it works:                                                       ||
        ||    Each letter in the text is rotated by 13 positions. Since there are ||
        ||    26 letters in the alphabet, applying Rot13 twice restores the       ||
        ||    original text.                                                      ||
        ||                                                                        ||
        ||    Usage:                                                              ||
        ||    1. Enter the text to be encrypted or decrypted.                     ||
        ||    2. The algorithm performs the Rot13 transformation.                 ||
        ||                                                                        ||
        || 5. Hybrid Algorithm                                                    ||
        ||    ----------------                                                    ||
        ||    What it does:                                                       ||
        ||    The Hybrid algorithm combines Random ASCII Shifting, Base64         ||
        ||    encoding, and Vigenère cipher to encrypt text using multiple steps. ||
        ||                                                                        ||
        ||    How it works:                                                       ||
        ||    1. First, each character is shifted by a random ASCII value.        ||
        ||    2. Then, the shifted text is Base64 encoded.                        ||
        ||    3. Finally, the encoded text is encrypted using the Vigenère cipher.||
        ||                                                                        ||
        ||    Usage:                                                              ||
        ||    1. Enter the text to be encrypted.                                  ||
        ||    2. Provide the Vigenère cipher keyword.                             ||
        ||    3. The algorithm performs the three-step encryption. The user must  ||
        ||       provide the random shift value for decryption later.             ||
        ||                                                                        ||
        \\==========================================================================/
        )" << endl;

        cout<<"\n\n\n"<<endl;

    return;

}

