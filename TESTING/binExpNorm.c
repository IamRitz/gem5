#include <stdio.h>
#include <math.h>

typedef unsigned long long int ull;

ull nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    ull res = 1;
    int i;
    r = (r < (n-r)) ? r : (n-r);
    for (i = 1; i <= r; ++i) {
        res *= n;
        res /= i;
        --n;
    }

    return res;
}

void BinExpTerms(int n, int A, int X) {
    int i;
    ull ncr;
    ull term;

    ull expA = pow(A, n);
    ull expX = 1ll;
    for (i = 0; i <= n; i++) {
        ncr = nCr(n, i);
        term = 1ll * ncr * expA * expX;
        printf("%lld (%dC%d * A^%d * X^%d)\n", term, n, i, n - i, i);
        expA /= A;
        expX *= X;
    }
}

int main() {
    int n, A, X;

    //printf("Enter the values of n, A, and X: ");
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

    for(int i=1; i<=100; ++i)
    {
      printf("Binomial Expansion Terms:\n");
      BinExpTerms(n, A, X);
    }

    return 0;
}
