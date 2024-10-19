#ifndef STIVA_H
#define STIVA_H

typedef struct {
    int *data;
    int capacity;
    int addCycle;
    int top;
} stiva_q;

stiva_q* init_q(int capacity, int addCycle);
int isEmpty_q(stiva_q *st);
void print_q(stiva_q *st);
int peek_q(stiva_q *st);
int push_q(stiva_q *st, int val);
int pop_q(stiva_q *st);
void freeAll_q(stiva_q *st);

#endif