#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Pick g from Z*_p
// Pick random x, y from Z*_p
// Alice computes g^x mod p
// Alice sends A and g^x to Bob
// Bob computes g^y mod p and Sig_B(A, B, g^x, g^y)
// Bob sends B, g^y and SigB(A, B, g^x, g^y)
// Alice computes SigA(A, B, g^y, g^x)
// Alice send SigA(A, B, g^y, g^x) to Bob
// Both compute K = g^xy mod p

// 2048 
// What is A and B?
// How do I compute SigA and SigB?


void power(mpz_t g, mpz_t pow, mpz_t mod, mpz_t res) {
    mpz_powm(res, g, pow, mod);
}


int main(){
    mpz_t p, g, x, y, a, b, ka, kb;

    // Initializing variables
    mpz_init(p);
    mpz_init(g);
    mpz_init(x);
    mpz_init(y);
    mpz_init(a);
    mpz_init(b);
    mpz_init(ka);
    mpz_init(kb);

    // Taking arbitrary inputs
    printf("Input modulus p: ");
    gmp_scanf("%Zd", p);
    gmp_printf("\nThe public parameter p: %Zd", p);
    printf("Input generator g: ");
    gmp_scanf("%Zd", g);
    gmp_printf("\nThe generator g: %Zd", p);
    printf("Input Alice's x: ");
    gmp_scanf("%Zd", x);
    gmp_printf("\nAlice's x: %Zd", x);
    printf("Input Bob's y: ");
    gmp_scanf("%Zd", y);
    gmp_printf("Bob's y: %Zd", y);

    // Generating g^exp mod p
    power(g, x, p, a);
    power(g, y, p, b);

    // Generating keys
    power(a, x, p, ka);
    power(b, y, p, kb);

    // Printing keys
    gmp_printf("Alice's private key ka: %Zd", ka);
    gmp_printf("Bob's private key kb: %Zd", kb);


    return 0;
}