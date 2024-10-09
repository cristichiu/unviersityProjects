#include <stdio.h>

int main() {
    //ex 16
    int i=1, s = 0;
    printf("Scrie cifrele: ");
    while(i) {
        scanf("%d", &i);
        if(!(i%3)) s+=i;
    }
    printf("%d", s);
    return 0;
}