#include <stdio.h>
int main() {
    // ex 5 V21
    int n;
    printf("Ion spune: ");
    scanf("%d", &n);
    printf("Vasile spune: ");
    for(int i=n-2; i<=n+2; i++) {
        printf("%d ", i);
    }
    return 0;
}