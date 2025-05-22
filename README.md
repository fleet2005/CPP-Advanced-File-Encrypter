# Advanced Encryption Application

A robust C++ application that implements multiple encryption algorithms for secure file encryption and decryption.

## Features

- Multiple encryption algorithms:
  - Caesar Cipher
  - Vigenère Cipher
  - ROT13
  - Base64
  - Random ASCII Shift
  - Hybrid Algorithm (combination of multiple methods)
- File-based encryption and decryption
- Password strength analysis
- User-friendly command-line interface

## Prerequisites

- C++ compiler (supporting C++11 or later)
- Windows operating system (for the executable)

## Building from Source

1. Clone the repository:
```bash
git clone [repository-url]
```

2. Compile the source files:
```bash
g++ -o encryptionApp *.cpp
```

## Usage

1. Run the executable:
```bash
./encryptionApp
```

2. Follow the on-screen prompts:
   - Enter the filename to encrypt/decrypt
   - Choose encryption (e) or decryption (d) mode
   - Follow additional prompts for specific encryption methods

## Project Structure

- `main.cpp` - Main application entry point
- `encryption.h/cpp` - Core encryption functionality
- `CaesarCipher.h/cpp` - Caesar cipher implementation
- `VigenereCipher.h/cpp` - Vigenère cipher implementation
- `Rot13.h/cpp` - ROT13 implementation
- `Base64.h/cpp` - Base64 encoding/decoding
- `RandomAsciiShift.h/cpp` - Random ASCII shift implementation
- `HybridAlgo.h/cpp` - Hybrid encryption algorithm
- `Strength.h/cpp` - Password strength analysis
- `info.h/cpp` - Information display utilities
- `Starter.h/cpp` - Application startup utilities
- `End.h/cpp` - Application termination utilities

## Security Notes

- This application is for educational purposes
- Always keep your encryption keys secure
- Make backups of important files before encryption
- The hybrid algorithm provides stronger security than individual methods

## License

MIT

## Author

Vishal Srinivasan