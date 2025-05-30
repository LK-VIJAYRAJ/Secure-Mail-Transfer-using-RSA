#include "rsa.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

RSA::RSA() {
    srand(time(0));
    generateKeys();
}

bool RSA::isPrime(long long num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0) return false;
    return true;
}

long long RSA::gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long RSA::modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long RSA::modInverse(long long a, long long m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

void RSA::generateKeys() {
    do {
        p = rand() % 50 + 10;
    } while (!isPrime(p));

    do {
        q = rand() % 50 + 10;
    } while (!isPrime(q) || q == p);

    n = p * q;
    phi = (p - 1) * (q - 1);

    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    d = modInverse(e, phi);
}

std::pair<long long, long long> RSA::getPublicKey() {
    return {e, n};
}

std::pair<long long, long long> RSA::getPrivateKey() {
    return {d, n};
}

long long RSA::encrypt(int plaintext, std::pair<long long, long long> pubKey) {
    return modPow(plaintext, pubKey.first, pubKey.second);
}

int RSA::decrypt(long long ciphertext, std::pair<long long, long long> privKey) {
    return modPow(ciphertext, privKey.first, privKey.second);
}