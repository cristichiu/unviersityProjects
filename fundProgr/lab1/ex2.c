#include <stdio.h>
int main() {
    // ex 8 V21
    char x,y,z;
    printf("Scrie 3 cifre separate prin spatiu intre 0 si 9: ");
    scanf("%c %c %c", &x, &y, &z);
    getchar();
    printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c",
            y,z,x, x,z,y, z,y,x, z,x,y, y,x,z);
    return 0;
}