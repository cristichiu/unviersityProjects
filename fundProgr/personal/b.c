#include <stdio.h>

// Funcție pentru exponențiere modulară rapidă
unsigned long long power_mod(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod; // Aplicăm mod înainte de începerea buclei

    while (exp > 0) {
        // Dacă exp este impar, înmulțim cu baza
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Exp este împărțit la 2
        exp = exp >> 1;
        // Creștem baza
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    unsigned long long base = 123456789, exp = 987654321, mod = 1000000007;
    
    printf("Rezultatul: %llu\n", power_mod(base, exp, mod));
    
    return 0;
}