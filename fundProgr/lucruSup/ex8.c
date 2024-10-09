#include <stdio.h>

void bubble(int size, int *data[size]) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(data[j] > data[j+1]) {
                int temp = *data[j];
                *data[j] = *data[j+1];
                *data[j+1] = temp;
            }
        }
    }
}

int main() {
    int size = 5;
    int *data[size];
    *data[0] = 2; *data[1] = 1; *data[2] = 4; *data[3] = 3; *data[4] = 5;
    bubble(size, data);
    printf("%d", data[0]);

    return 0;
}