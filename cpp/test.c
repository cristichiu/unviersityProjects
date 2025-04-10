#include <stdio.h>
#include <stdlib.h>

int main() {
    int puncte[8] = { 1, 2, 3, 4, 5, 6, 7, 8 }; 
    int muchii[7][2] = {{1,2}, {2,3}, {5,6}, {3,5}, {1,7}, {4,8}, {4,5}};
    int matriceDeIncidenta[8][7];
    int allocAlgGrafM = 1;
    int **formaAlgebricaGrafMuchii = malloc(sizeof(int*) * allocAlgGrafM);
    for(int i=0; i<8; i++) for(int j=0; j<7; j++) matriceDeIncidenta[i][j] = 0;
    for(int i=0; i<7; i++) {
        matriceDeIncidenta[muchii[i][0]-1][i] = 1;
        matriceDeIncidenta[muchii[i][1]-1][i] = 1;
    }
    printf("Muchii:\n");
    for(int i=0; i<7; i++) {
        printf("%d %d\n", muchii[i][0], muchii[i][1]);
    }
    printf("Matrice de incidenta:\n");
    for(int i=0; i<8; i++) {
        for(int j=0; j<7; j++) {
            printf("%d ", matriceDeIncidenta[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<8; i++) {
        int st = -1;
        for(int j=0; j<7; j++) {
            if(matriceDeIncidenta[i][j]) {
                if(st == -1) st = j+1; else {
                    formaAlgebricaGrafMuchii = realloc(formaAlgebricaGrafMuchii, sizeof(int*) * allocAlgGrafM);
                    formaAlgebricaGrafMuchii[allocAlgGrafM-1] = malloc(sizeof(int) * 2);
                    formaAlgebricaGrafMuchii[allocAlgGrafM-1][0] = st;
                    formaAlgebricaGrafMuchii[allocAlgGrafM-1][1] = j+1;
                    st = j+1;
                    allocAlgGrafM++;
                }
            }
        }
    }
    printf("Forma algebrica graf muchii:\n");
    for(int i=0; i<allocAlgGrafM-1; i++) {
        printf("%d %d\n", formaAlgebricaGrafMuchii[i][0], formaAlgebricaGrafMuchii[i][1]);
    }
    void DFS(int vs, int matDeInc[8][7]) {
        int n = 8;
        int flaguri[8] = {0,0,0,0,0,0,0,0};
        int allocParc = 0;
        int parcurgere[8] = {0,0,0,0,0,0,0,0};
        int current = vs;

        while(1) {
            if(flaguri[current-1] == 0) {
                flaguri[current-1] = 1;
                parcurgere[allocParc] = current;
                allocParc++;
            }
            int vecini = 0;
            for(int i=0; i<7; i++) {
                if(matDeInc[current-1][i]) {
                    for(int j=0; j<n; j++) {
                        if(matDeInc[j][i] && flaguri[j] == 0) {
                            current = j+1;
                            vecini = 1;
                            break;
                        }
                    }
                }
                if(vecini) break;
            }
            if(!vecini) {
                flaguri[current-1] = 2;
                if(current == vs) break;
                for(int i=7; i>=0; i--) {
                    if(flaguri[parcurgere[i] -1] == 1) {
                        current = parcurgere[i];
                        break;
                    }
                }
            }
        }

        for(int i=0; i<8; i++) {
            printf("%d - %d\n", flaguri[i], parcurgere[i]);
        }
    }
    DFS(2, matriceDeIncidenta);
    return 0;
}
