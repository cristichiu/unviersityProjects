#include <stdio.h>
#include <stdlib.h>

#define db "./db.txt"

typedef struct Carte {
    int id;
    char titlu[50], autor[50];
    int an_publicare;
    int deleted;
} Carte;

void fAdd() {
    Carte el, buffer;
    FILE *forID = fopen(db, "rb");
    if(forID == NULL) {
        el.id = 1;
    } else {
        fseek(forID, 0, SEEK_END);
        long dim = ftell(forID);
        if (dim == 0) {
            el.id = 1;
        } else {
            fseek(forID, -sizeof(Carte), SEEK_CUR);
            fread(&buffer, sizeof(Carte), 1, forID);
            el.id = buffer.id + 1;
        }
    }
    fclose(forID);
    printf("Scrie titlu-ul: "); scanf("%s", &el.titlu);
    printf("Scrie autor-ul: "); scanf("%s", &el.autor);
    printf("Scrie an-ul: "); scanf("%d", &el.an_publicare);
    el.deleted = 0;
    FILE *file = fopen(db, "ab");
    if(file == NULL) return;
    fwrite(&el, sizeof(Carte), 1, file);
    fclose(file);
}

void fShow() {
    FILE *file = fopen(db, "rb");
    if(file == NULL) return;
    Carte buffer;
    printf("\n====================================\nID | titlu | autor | an de publicare\n------------------------------------\n\n");
    while(fread(&buffer,sizeof(Carte),1,file) == 1) {
        if(!buffer.deleted) printf("%d | %s | %s | %d\n", buffer.id, buffer.titlu, buffer.autor, buffer.an_publicare);
    }
    printf("\n====================================\n\n");
    fclose(file);
}

void fDelete() {
    int id_;
    printf("Scrie ID-ul cartii pe care vrei sa o stergi: "); scanf("%d", &id_);
    FILE *file = fopen(db, "r+b");
    if(file == NULL) return;
    Carte buffer;
    while(fread(&buffer,sizeof(Carte),1,file) == 1) {
        if(id_ == buffer.id) {
            fseek(file, -sizeof(Carte), SEEK_CUR);
            buffer.deleted = 1;
            fwrite(&buffer, sizeof(Carte), 1, file);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Nu am gasit acest element.\n");
}

enum options { show = 1 , add , delete };

int main() {
    while(1) {
        enum options opt;
        printf("1 - show\n2 - add\n3 - delete\nScrie optiunea ta: "); scanf("%d", &opt);
        switch(opt) {
            case show: fShow(); break;
            case add: fAdd(); break;
            case delete: fDelete(); break;
        }
    }
    return 0;
}