#include <stdio.h>

int sum(int n) {
    if(n<=1) return 1;
    return sum(n-1) + n;
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%i", sum(n));
    return 0;
}