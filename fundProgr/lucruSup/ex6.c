#include <stdio.h>

int main() {
    FILE *f1, *f2, *res;
    f1 = fopen("./txt/f1.txt", "r");
    f2 = fopen("./txt/f2.txt", "r");
    res = fopen("./txt/res.txt", "w");

    int xf1, xf2;

    while(fscanf(f1, "%d", &xf1) != EOF && fscanf(f2, "%d", &xf2) != EOF) {
        printf("%d %d ", xf1, xf2);
        fprintf(res, "%d %d ", xf1, xf2);
    }

    fclose(f1);
    fclose(f2);
    fclose(res);

    return 0;
}