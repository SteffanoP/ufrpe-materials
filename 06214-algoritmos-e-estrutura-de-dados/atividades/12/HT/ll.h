// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html

typedef struct reg celula;
struct reg {
   char*  chave;
   int        v;
   celula *prox;
};

celula *insere (char*, int, celula *);
celula *busca (char*, celula *);
