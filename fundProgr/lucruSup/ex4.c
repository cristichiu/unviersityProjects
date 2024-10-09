#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stringToInt(char *string) {
    float res = 0;
    int start = 0;
    int isNegative = 0;
    if(string[start] == '-') { start = 1; isNegative = 1; }
    for(int i=start; i<strlen(string); i++) {
        if((int)string[i] < 48 || (int)string[i] > 57) {
            printf("caracterul %c de pe pozitie %i - nu este valid pentru a fi transformat !!!\n", string[i], i+1);
            return 0;
        }
        res += ((int) string[i]-48)*pow(10, strlen(string)-i-1);
    }
    if(isNegative) res*=-1;
    return (int)res;
}
char *intToString(int num) {
    char *res = calloc(32, 1);
    int isNegative = 0;
    if(num<0) { num*=-1; isNegative = 1; }
    while(num) {
        char *temp = calloc(1, 1);
        sprintf(temp, "%c", (char)(num%10+48));
        strcat(res, temp);
        num /= 10;
    }
    if(isNegative) { char *temp = calloc(1, 1); sprintf(temp, "%c", '-'); strcat(res, temp); }
    for(int i=0; i<strlen(res)/2; i++) {
        char temp = res[strlen(res)-1-i];
        res[strlen(res)-1-i] = res[i];
        res[i] = temp;
    }
    return res;
}

int main() {
    printf("%s\n", intToString(-4219));
    printf("%i", stringToInt("4219"));
    return 0;
}