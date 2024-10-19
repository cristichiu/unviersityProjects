#include <stdio.h>
#include <stdlib.h>
#include "../../extern/stiva_q.h"

stiva_q* init_q(int capacity, int addCycle) {
    stiva_q *st = (stiva_q*)malloc(sizeof(stiva_q));
    if(addCycle <=0) addCycle = 1;
    st->capacity = capacity;
    st->top = -1;
    st->addCycle = addCycle;
    st->data = (int*)malloc(capacity*sizeof(int));
    return st;
}

int isEmpty_q(stiva_q *st) {
    return st->top == -1;
}

void print_q(stiva_q *st) {
    if(isEmpty_q(st)) {
        printf("Aceasta stiva este goala.\n");
    } else {
        for(int i=0; i<=st->top; i++) {
            printf("%d\n", st->data[i]);
        }
    }
}

int peek_q(stiva_q *st) {
    if(isEmpty_q(st)) return 0; else return st->data[st->top];
}

int push_q(stiva_q *st, int val) {
    if(st->top >= st->capacity-1) {
        st->capacity += st->addCycle;
        st->data = (int*)realloc(st->data, st->capacity*sizeof(int));
    }
    st->data[++st->top] = val;
    return st->data[st->top];
}

int pop_q(stiva_q *st) {
    if(isEmpty_q(st)) {
        return 0;
    } else {
        int res = st->data[st->top--];
        return res;
    }
}

void freeAll_q(stiva_q *st) {
    free(st->data);
    free(st);
}