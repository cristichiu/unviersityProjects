#include <stdio.h>

int fibb(int n) {
    if(n<=1) return 0;
    if(n<=3) return 1;
    return fibb(n-1) + fibb(n-2);
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%i", fibb(n));
    return 0;
}