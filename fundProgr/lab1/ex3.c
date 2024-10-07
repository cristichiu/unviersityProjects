#include <stdio.h>
int main() {
    // ex 12 V21
    int a, b;
    printf("Scrie 2 numere intregi separate prin spatiu: ");
    scanf("%d %d", &a, &b);
    printf("a=%d\nb=%d\n\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("a=%d\nb=%d", a, b);
    return 0;
}