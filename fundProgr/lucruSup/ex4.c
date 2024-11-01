#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stringToInt(char *string) {
    int res = 0;
    int start = 0;
    int isNegative = 0;
    if(string[start] == '-') { start = 1; isNegative = 1; }
    for(int i=start; i<strlen(string); i++) {
        if((int)string[i] < 48 || (int)string[i] > 57) {
            printf("caracterul %c de pe pozitie %i - nu este valid pentru a fi transformat !!!\n", string[i], i+1);
            return 0;
        }
        res=res*10+((int)string[i]-48);
        // res += ((int) string[i]-48)*(int)(pow(10, strlen(string)-i-1)+.5);
    }
    if(isNegative) res*=-1;
    return res;
}
char *intToString(int num) {
    char *res = calloc(32, 1);
    int isNegative = 0;
    if(num<0) { num*=-1; isNegative = 1; }
    while(num) {
        // sprintf(res, "%s%c", res, (char)(num%10+48));
        sprintf(res, "%s%d", res, num%10);
        num /= 10;
    }
    if(isNegative) sprintf(res, "%s%c", res, '-');
    // for(int i=0; i<strlen(res)/2; i++) {
    //     char temp = res[strlen(res)-1-i];
    //     res[strlen(res)-1-i] = res[i];
    //     res[i] = temp;
    // }
    strrev(res);
    return res;
}

int main() {
    // printf("%s\n", intToString(-4219));
    // printf("%i\n", stringToInt("42159"));
    int x = stringToInt("124a");
    printf("%d", x);
    // printf("%s", intToString(stringToInt("-234")));
    return 0;
}