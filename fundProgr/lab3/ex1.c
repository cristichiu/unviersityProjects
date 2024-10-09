#include <stdio.h>

int main() {
    //ex 12
    int a, b, c, res;
    printf("Scrie 3 numere diferite sortate crescator prin spatiu: ");
    scanf("%d %d %d", &a, &b, &c);
    for(int i=2; i<=a; i++) {
        if(!(a%i) && !(b%i) && !(c%i)) {
            res = i;
        }
    }
    printf("%d", res);
    return 0;
}