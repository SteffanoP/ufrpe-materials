// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html

#include "ll.h"

typedef struct ht_ HT;
struct ht_ {
    int M;
    celula** V;
};

int hash(char*, int);
HT *cria_ht(int);
void put(HT *, char*);
int get(HT *, char*);
void printHT(HT *);
void saveHT(HT *, char*, char*);