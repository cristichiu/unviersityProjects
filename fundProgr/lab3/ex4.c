#include <stdio.h>

int main() {
    //ex 15
    int i=1, s = 0;
    printf("Scrie cifrele: ");
    while(i) {
        scanf("%d", &i);
        if(!(i%2)) s+=i;
    }
    printf("%d", s);
    return 0;
}