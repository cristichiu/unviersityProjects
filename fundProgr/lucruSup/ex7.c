#include <stdio.h>
#include <stdlib.h>

struct Stiva {
    int *data;
    int capacity;
    int addCycle;
    int top;
};

struct Stiva* init(int capacity, int addCycle) {
    struct Stiva *st = (struct Stiva*)malloc(sizeof(struct Stiva));
    if(addCycle <=0) addCycle = 1;
    st->capacity = capacity;
    st->top = -1;
    st->addCycle = addCycle;
    st->data = (int*)malloc(capacity*sizeof(int));
    return st;
}

int isEmpty(struct Stiva *st) {
    return st->top == -1;
}

void print(struct Stiva *st) {
    if(isEmpty(st)) {
        printf("Aceasta stiva este goala.\n");
    } else {
        for(int i=0; i<=st->top; i++) {
            printf("%d\n", st->data[i]);
        }
    }
}

int peek(struct Stiva *st) {
    if(isEmpty(st)) return 0; else return st->data[st->top];
}

int push(struct Stiva *st, int val) {
    if(st->top >= st->capacity-1) {
        st->capacity += st->addCycle;
        st->data = (int*)realloc(st->data, st->capacity*sizeof(int));
    }
    st->data[++st->top] = val;
    return st->data[st->top];
}

int pop(struct Stiva *st) {
    if(isEmpty(st)) {
        return 0;
    } else {
        int res = st->data[st->top--];
        return res;
    }
}

void freeAll(struct Stiva *st) {
    free(st->data);
    free(st);
}

int main() {
    struct Stiva *st = init(5, 1);
    for(int i=0; i<10; i++) {
        push(st, i);
    }
    print(st);
    pop(st);
    printf("aici- %d\n", peek(st));
    freeAll(st);
    return 0;
}