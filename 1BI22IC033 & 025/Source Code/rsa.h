#ifndef RSA_H
#define RSA_H

#include <string>
#include <vector>

class RSA {
public:
    RSA();
    void generateKeys();
    std::pair<long long, long long> getPublicKey();
    std::pair<long long, long long> getPrivateKey();
    long long encrypt(int plaintext, std::pair<long long, long long> pubKey);
    int decrypt(long long ciphertext, std::pair<long long, long long> privKey);

private:
    long long p, q, n, phi, e, d;
    long long gcd(long long a, long long b);
    long long modInverse(long long a, long long m);
    long long modPow(long long base, long long exp, long long mod);
    bool isPrime(long long num);
};

#endif