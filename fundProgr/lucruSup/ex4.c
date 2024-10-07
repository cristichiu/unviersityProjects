#include <stdio.h>
#include <string.h>
#include <math.h>

int stringToInt(char *string) {
    float res = 0;
    for(int i=0; i<strlen(string); i++) {
        if((int)string[i] < 48 || (int)string[i] > 57) {
            printf("caracterul %c de pe pozitie %i - nu este valid pentru a fi transformat !!!\n", string[i], i+1);
            return 0;
        }
        res += ((int) string[i]-48)*pow(10, strlen(string)-i-1);
    }
    return (int)res;
}
char *intToString(int num) {
    char *res = calloc(32, sizeof(char));
    while(num) {
        
    }
}

int main() {
    printf("%i", stringToInt("000099900"));
    return 0;
}