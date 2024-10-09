#include <stdio.h>

int main() {
    //ex 11
    int a, b, rescd, rescm;
    printf("Scrie 2 numere diferite sortate crescator prin spatiu: ");
    scanf("%d %d", &a, &b);
    for(int i=2; i<=a; i++) {
        if(!(a%i) && !(b%i)) {
            rescd = i;
        }
    }
    for(int i=1; i<=a*b; i++) {
        if(!(i%a) && !(i%b)) {
            rescm = i; break;
        }
    }
    printf("%d\n%d", rescd, rescm);
    return 0;
}