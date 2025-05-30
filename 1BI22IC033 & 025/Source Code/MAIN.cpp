#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "rsa.h"

void saveKeyToFile(const std::string& filename, std::pair<long long, long long> key) {
    std::ofstream out(filename);
    out << key.first << " " << key.second;
    out.close();
}

std::pair<long long, long long> loadKeyFromFile(const std::string& filename) {
    std::ifstream in(filename);
    long long first, second;
    in >> first >> second;
    in.close();
    return {first, second};
}

int main() {
    RSA rsa;
    int choice;

    do {
        std::cout << "\nWelcome to Secure Mail Transfer using RSA\n";
        std::cout << "\n1. Generate RSA Keys";
        std::cout << "\n2. Encrypt Message";
        std::cout << "\n3. Decrypt Message";
        std::cout << "\n4. Exit";
        std::cout << "\n\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            rsa.generateKeys();
            auto pub = rsa.getPublicKey();
            auto priv = rsa.getPrivateKey();
            saveKeyToFile("public_key.txt", pub);
            saveKeyToFile("private_key.txt", priv);
            std::cout << "\nGenerating RSA Keys...";
            std::cout << "\nPublic Key saved to public_key.txt";
            std::cout << "\nPrivate Key saved to private_key.txt\n";

        } else if (choice == 2) {
            std::string message;
            std::cout << "\nEnter the message to encrypt: ";
            std::getline(std::cin, message);

            auto pub = loadKeyFromFile("public_key.txt");
            std::ofstream out("ciphertext.txt");
            for (char ch : message) {
                long long encrypted = rsa.encrypt((int)ch, pub);
                out << encrypted << " ";
            }
            out.close();
            std::cout << "\nMessage encrypted successfully.";
            std::cout << "\nEncrypted text saved to ciphertext.txt\n";

        } else if (choice == 3) {
            auto priv = loadKeyFromFile("private_key.txt");
            std::ifstream in("ciphertext.txt");
            long long num;
            std::string decrypted;

            while (in >> num) {
                char ch = (char)rsa.decrypt(num, priv);
                decrypted += ch;
            }
            in.close();

            std::cout << "\nDecrypted message:\n" << decrypted << "\n";

        } else if (choice != 4) {
            std::cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    std::cout << "\nExiting program.\n";
    return 0;
}