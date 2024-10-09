#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef void (*sort)(int, int[]);

void bubble(int size, int data[size]) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void insertion(int size, int data[size]) {
    for(int i=1; i<size; i++) {
        int j=i;
        while(j>=1 && data[j-1] > data[j]) {
            int temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
}

void selection(int size, int data[size]) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(data[i] > data[j]) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void sortF(int size, int data[size], sort func) { func(size, data); }

int main() {
    srand(time(0));
    clock_t start, end;
    double totalTime;

    int size = 50000;
    int data[size];
    for(int i=0; i<size; i++) data[i] = rand();

    start = clock();    
    // sortF(size, data, bubble); // 9.751000 secunde 50000
    // sortF(size, data, insertion); // 2.865000 secunde 50000
    // sortF(size, data, selection); // 9.764000 secunde 50000
    end = clock();

    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%f secunde", totalTime);

    return 0;
}