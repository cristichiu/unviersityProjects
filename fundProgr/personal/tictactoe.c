#include <stdio.h>

void tableShow(char table[9]) {
    for(int i=0; i<9; i+=3) {
        for(int j=i; j<i+3; j++) {
            if(table[j]==0) printf("%d ", j+1);
            if(table[j]==1) printf("x ");
            if(table[j]==4) printf("o ");
        }
        printf("\n");
    }
}

int findWin(char table[9]) {
    char posibleWins[8] = {
        // verifica diagonalele
        table[0]+table[4]+table[8],
        table[2]+table[4]+table[6],
        // verificarea randurilor
        table[0]+table[1]+table[2],
        table[3]+table[4]+table[5],
        table[6]+table[7]+table[8],
        // verificarea coloanelor
        table[0]+table[3]+table[6],
        table[1]+table[4]+table[7],
        table[2]+table[5]+table[8],
    };
    for(int i=0; i<8; i++) {
        if(posibleWins[i] == 3) return 3;
        if(posibleWins[i] == 12) return 12;
    }
    int prd = table[0];
    for(int i=1; i<9; i++) prd*=table[i];
    if(prd) return 100;
    return 0;
}

int main() {
    char table[9] = {0,0,0,
                     0,0,0,
                     0,0,0};
    int isXTurn = 1;
    while(!findWin(table)) {
        tableShow(table);
        int select;
        isXTurn ? printf("Randul lui x: ") : printf("Randul lui o: "); scanf("%d", &select);
        if(!table[select-1]) {
            table[select-1] = isXTurn ? 1:4;
            isXTurn = isXTurn ? 0:1;
        } else {
            printf("------------------------------------\n");
            printf("Ai selectat un patratel completat deja\n");
        }
        printf("------------------------------------\n");
    }
    tableShow(table);
    if(findWin(table) == 3) printf("x a castigat");
    if(findWin(table) == 12) printf("o a castigat");
    if(findWin(table) == 100) printf("Draw");
    return 0;
}