#include <stdio.h>
int main() {
    // ex 16 V21
    int a, b, d;
    printf("Scrie nr de saptamani: "); scanf("%d", &a);
    printf("Scrie nr de zile: "); scanf("%d", &b);
    printf("Scrie distanta: "); scanf("%d", &d);
    b += a*7;
    int h = b*24;
    printf("%.2f km/h", d/(float)h);
    return 0;
}