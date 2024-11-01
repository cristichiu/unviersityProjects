#include <stdio.h>

int main() {
    int nums[1000]; int n;
    printf("Scrie cate numere vei introduce: "); scanf("%d", &n);
    while(n <= 4 || n >= 1000) { printf("Scrie cate numere vei introduce 4<n<1000: "); scanf("%d", &n); }
    for(int i=0; i<n; i++) {
        printf("%d. Scrie numarul: ", i+1); scanf("%d", &nums[i]);
    }
    printf("Afisarea numerelor din din 5 in 5 pozitii: ");
    for(int i=0; i<n; i+=5) printf("%d ", nums[i]);
    return 0;
}