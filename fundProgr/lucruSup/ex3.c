#include <stdio.h>

struct Student{
    int nr;
    char nume[25];
};

int main() {
    int nrDeStudenti;
    printf("Scrie cati studenti o sa adaugi: "); scanf("%i", &nrDeStudenti);
    struct Student s[nrDeStudenti];
    for(int i=0; i<nrDeStudenti; i++) {
        printf("%i - Scrie numarul de ordine a studentului: ", i+1); scanf("%i", &s[i].nr);
        printf("%i - Scrie numele studentului: ", i+1); scanf("%s", &s[i].nume);
    }
    for(int i=0; i<nrDeStudenti; i++) {
        for(int j=i+1; j<nrDeStudenti; j++) {
            if(s[i].nr > s[j].nr) {
                struct Student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for(int i=0; i<nrDeStudenti; i++) {
        printf("%i - %s\n", s[i].nr, s[i].nume);
    }
    return 0;
}