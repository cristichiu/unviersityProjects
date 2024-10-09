#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("./txt/citire.txt", "r");
    char a[100][256];
    int count = 0;
    while(fgets(a[count], 256, file) != NULL && count < 100) { a[count][strlen(a[count])-1] = '\0'; count++; }
    char match[256]; int countApp = 0;
    printf("Scrie cuvantul pe care sa-l numar: "); scanf("%s", match);
    for(int i=0; i<count; i++) if(!(strcmp(a[i], match))) countApp++;
    printf("am numarat ca a aparut de %i ori", countApp);
    fclose(file);
    return 0;
}