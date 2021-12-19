#include "ht.h"
#include <stdlib.h>
#include <stdio.h>


// Cria uma nova tabela de hashing com colis�es
// tratadas por encadeamento
HT *cria_ht(int M) {
    HT *t = malloc(sizeof(HT));
    t->M = M;
    t->V = malloc (M * sizeof (celula *));
    for(int k = 0; k < M; t->V[k++] = NULL);
    return t;
}

int hash(char* ch, int M) {
  unsigned h = 0;
  for (int i = 0; ch[i] != '\0'; i++) 
    h = (h * 256 + ch[i]) % M;
  return h;
}


// Insere uma chave ch na tabela de hashing t.
// Se ch n�o pertence � tabela, o valor da nova
// c�lula criada � 1.
// Se j� pertence, incrementa o valor.

void put(HT *t, char* ch) {
    int h = hash (ch, t->M);
    celula *p = t->V[h];

    p = busca(ch, p);
    if (p != NULL) 
      p->v += 1;
    else
      t->V[h] = insere(ch, 1, t->V[h]);
}

// Devolve o valor associado � chave ch na tabela t.
// Se ch n�o est� na tabela, devolve -1.
int get(HT *t, char* ch) {

    int h = hash (ch, t->M);
    celula *p = t->V[h];

    p = busca(ch, p);

    return p ? p->v : -1;

}

void printHT(HT *t) {

    int k;
    celula *p;

    for(k = 0; k < t->M; k++) {
        printf("%d: ", k);
        for(p = t->V[k]; p != NULL; p = p->prox)
            printf("(%s, %d) ", p->chave, p->v);
        printf("\n");
    }

}

/**
  * @param t corresponde a hash table.
  * @param titulo_arq corresponde ao título 
  * do arquivo com o formato;
  * @param separador corresponde ao separador 
  * do arquivo.
  **/
void saveHT(HT *t, char* titulo_arq, char* separador) {
  FILE *saida;
  saida = fopen(titulo_arq, "w");

  fprintf(saida, "Base%sOcorrências\n", separador);
  
  int k;
  celula *p;

  for(k = 0; k < t->M; k++) {
    for(p = t->V[k]; p != NULL; p = p->prox)
      fprintf(saida, "%s%s%d\n", p->chave, separador, p->v);
  }
  
  free(p);
  fclose(saida);
}