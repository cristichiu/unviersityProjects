#include <stdio.h>

void afisareaMatrice(int rand, int col, int matri[rand][col]) {
    for(int i=0; i<rand; i++) {
        for(int j=0; j<col; j++) {
            printf("    %i ", matri[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int rand1, col1, rand2, col2;
    printf("Scrie cate randuri si cate coloane o sa aiba prima matrice:\n");
    printf("    Randuri: "); scanf("%i", &rand1);
    printf("    Coloane: "); scanf("%i", &col1);
    printf("Scrie cate randuri si cate coloane o sa aiba a 2-a matrice:\n");
    printf("    Randuri: "); scanf("%i", &rand2);
    printf("    Coloane: "); scanf("%i", &col2);

    int mat1[rand1][col1], mat2[rand2][col2];
    printf("Scriem matricea 1: \n");
    for(int i=0; i<rand1; i++) {
        for(int j=0; j<col1; j++) {
            mat1[i][j] = 0;
            printf("    Scrie elementul %i din randul %i: ", j+1, i+1);
            scanf("%i", &mat1[i][j]);
        }
    }
    printf("Scriem matricea 2: \n");
    for(int i=0; i<rand2; i++) {
        for(int j=0; j<col2; j++) {
            mat2[i][j] = 0;
            printf("    Scrie elementul %i din randul %i: ", j+1, i+1);
            scanf("%i", &mat2[i][j]);
        }
    }
    printf("Afisam matricea 1: \n");
    afisareaMatrice(rand1, col1, mat1);
    printf("Afisam matricea 2: \n");
    afisareaMatrice(rand2, col2, mat2);

    if(rand1 == rand2 && col1 == col2) {
        int sum[rand1][col1];
        for(int i=0; i<rand1; i++) {
            for(int j=0; j<col1; j++) {
                sum[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        printf("Afisam suma matricelor: \n");
        afisareaMatrice(rand1, col1, sum);
    } else printf("Adunarea matricelor nu este posibila!\n");
    if(col1 == rand2) {
        int prd[rand1][col2];
        for(int i=0; i<rand1; i++) {
            for(int j=0; j<col2; j++) {
                prd[i][j] = 0;
                for(int z=0; z<col1; z++) {
                    prd[i][j] += mat1[i][z]*mat2[z][j];
                }
            }
        }
        printf("Afisam produsul matricelor: \n");
        afisareaMatrice(rand1, col2, prd);
    } else printf("Inmultirea matricelor nu este posibila");

    return 0;
}