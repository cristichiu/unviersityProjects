#include <stdio.h>

int main() {
    int col, row;
    printf("Scrie cate randuri o sa aiba tabelul: "); scanf("%d", &row);
    printf("Scrie cate coloane o sa aiba tabelul: "); scanf("%d", &col);
    int tab[row][col];
    int maxColIndex, maxNum = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("Scrie elementul din row %d si col %d: ", i+1, j+1); scanf("%d", &tab[i][j]);
            if(tab[i][j] > maxNum) {
                maxNum = tab[i][j];
                maxColIndex = j;
            }
        }
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("Coloana %d are nr maxim: ", maxColIndex+1);
    for(int i=0; i<row; i++) {
        printf("%d ", tab[i][maxColIndex]);
    }
    return 0;
}