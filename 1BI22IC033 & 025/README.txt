
Secure Mail Transfer using RSA 
Description:
------------
This project simulates secure mail/message transfer using the RSA cryptographic algorithm in C++.
It allows a user to generate RSA keys, encrypt a message, and decrypt it using the appropriate key files.

Project Structure:
------------------
rsa.h – Header file with the RSA class declaration

rsa.cpp – C++ source file implementing all RSA functions: key generation, encryption, decryption
main.cpp – Main file where:
Keys are generated
A character is taken from the user
The character is encrypted and then decrypted

How to Compile:
---------------
Use a C++ compiler like g++ to compile all files. For example:
    g++ main.cpp rsa.cpp encrypt.cpp decrypt.cpp -o SecureMail

How to Run:
-----------
1. Run the executable: ./SecureMail
2. Choose option 1 to generate RSA keys (stored in .txt files).
3. Choose option 2 to enter a plaintext message and encrypt it.
4. Choose option 3 to decrypt the encrypted message and display the original text.

Output:
-------
- The encrypted message is saved in 'ciphertext.txt'.
- The decrypted message is printed to the terminal.

Note:
-----
Ensure all source files and key files are in the same directory for the program to function properly.
