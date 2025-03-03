#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void strrev(char *str) {
    if (!str || !*str) return;
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int atoi2(char *num) {
    int negative = num[0] == '-' ? 1 : 0;
    int start = negative ? 1 : 0;
    int res = 0;
    for(int i=start; i<strlen(num); i++) {
        if(num[i] >= '0' && num[i] <= '9') {
            res = res*10+(num[i] - '0');
        } else return res;
    }
    return negative ? -res : res;
}

float atof2(char *num) {
    char *token = strtok(num, ".,");
    int intPart = atoi2(token);
    token = strtok(NULL, ".,");
    int floatPart = token == NULL ? 0 : atoi2(token);
    int cpyFloatPart = floatPart;
    int count = 1;
    while(cpyFloatPart) {
        count *= 10;
        cpyFloatPart /= 10;
    }
    return intPart + (intPart < 0 ? -floatPart/(float)count : floatPart/(float)count);
}

char *itoa2(int num) {
    char *res = calloc(50, 1);
    int negative = num<0 ? 1 : 0;
    num = negative ? num*=-1 : num;
    while(num) {
        sprintf(res, "%s%d", res, num%10);
        num /= 10;
    }
    if(negative) sprintf(res, "%s%c", res, '-');
    strrev(res);
    return res;
}

char *ftoa2(float num) {
    char *str = calloc(50, 1);
    int negative = num<0 ? 1 : 0;
    if(negative) num*=-1; 
    int intPart = num*1000000;
    if (negative) strcat(str, "-");
    strcat(str, itoa2(intPart));
    char temp = str[strlen(str)-6];
    str[strlen(str)-6] = '.';
    for(int i=5; i<strlen(str); i--) {
        char temp2 = str[strlen(str) - i];
        str[strlen(str) - i] = temp;
        temp = temp2;
    }
    return str;
}

int main() {
    // testare fiecare:
    char inputForCharToFloat[] = "-1245,9";
    printf("%d\n", atoi2("4124"));
    printf("%f\n", atof2(inputForCharToFloat));
    printf("%s\n", itoa2(-1456));
    printf("%s\n", ftoa2(16.314999));
    return 0;
}