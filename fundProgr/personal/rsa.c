#include <stdio.h>

// Funcție pentru calcularea GCD (cel mai mare divizor comun)
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Funcție pentru exponențiere modulară rapidă
unsigned long long power_mod(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Funcție pentru a găsi inversul modular folosind algoritmul extins Euclid
unsigned long long mod_inverse(unsigned long long e, unsigned long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    
    while (newr != 0) {
        long long quotient = r / newr;
        t = t - quotient * newt;
        long long temp = t;
        t = newt;
        newt = temp;
        
        long long tempr = r;
        r = newr;
        newr = tempr - quotient * newr;
    }
    
    if (t < 0) {
        t = t + phi;
    }
    
    return t;
}

// Funcție pentru generarea cheilor RSA
void generate_rsa_keys(unsigned long long p, unsigned long long q, unsigned long long *n, unsigned long long *e, unsigned long long *d) {
    *n = p * q; // n = p * q
    unsigned long long phi = (p - 1) * (q - 1); // φ(n) = (p - 1) * (q - 1)
    
    *e = 3; // Alegem o valoare mică pentru e, cum ar fi 3
    while (gcd(*e, phi) != 1) { // Asigurăm că gcd(e, φ(n)) = 1
        (*e)++;
    }
    
    // Calculăm d, inversul modular al lui e față de φ(n)
    *d = mod_inverse(*e, phi);
}

// Funcție pentru criptare RSA
unsigned long long encrypt(unsigned long long message, unsigned long long e, unsigned long long n) {
    return power_mod(message, e, n);
}

// Funcție pentru decriptare RSA
unsigned long long decrypt(unsigned long long ciphertext, unsigned long long d, unsigned long long n) {
    return power_mod(ciphertext, d, n);
}

int main() {
    unsigned long long p = 4259; // Primul număr prim
    unsigned long long q = 4261; // Al doilea număr prim
    unsigned long long n, e, d;

    // Generăm cheile RSA
    generate_rsa_keys(p, q, &n, &e, &d);
    
    printf("Cheia publică: (e = %llu, n = %llu)\n", e, n);
    printf("Cheia privată: (d = %llu, n = %llu)\n", d, n);
    
    unsigned long long message = 65; // Mesajul de criptat
    printf("Mesaj original: %llu\n", message);

    // Criptăm mesajul
    unsigned long long ciphertext = encrypt(message, e, n);
    printf("Mesaj criptat: %llu\n", ciphertext);

    // Decriptăm mesajul
    unsigned long long decrypted_message = decrypt(ciphertext, d, n);
    printf("Mesaj decriptat: %llu\n", decrypted_message);
    
    return 0;
}
