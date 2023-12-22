#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

void BinExpTerms(int n, int A, int X) {
    int i;
    ull ncr;
    ull term;

    ull expA = pow(A, n);
    ull expX = 1;
    for (i = 0; i <= n; i++) {
        asm volatile("comb %0, %1,%2\n":"=r"(ncr):"r"(n),"r"(i):);
        term = ncr * expA * expX;
        printf("%lld (%dC%d * A^%d * X^%d)\n", term, n, i, n - i, i);
        expA /= A;
        expX *= X;
    }
}

int main() {
    int n, A, X;

    //printf("(Custom Instruction)Enter the values of n, A, and X: ");
    //scanf("%d %d %d", &n, &A, &X);

    n = 20;
    A = 1;
    X = 1;

    printf("n: %d\n", n);
    printf("A: %d\n", A);
    printf("X: %d\n", X);

    if (n < 0) {
        printf("Invalid input. n should be a non-negative integer.\n");
        return 1;
    }

    printf("Binomial Expansion Terms:\n");
    for(int i=1; i<=100; ++i)
      BinExpTerms(n, A, X);

    return 0;
}
