#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ht.h"

#define N 500
#define N_LINHAS 498
#define N_BLOCOS_LINHA 10
#define TAM_BLOCOS 6
#define M 1

FILE *arquivo;
int result;
char genoma[N][62];

char** separa_blocos(char *genoma, int tam_blocos, int qtd_blocos);
char* substring(char *destination, const char *source, int beg, int n);

int main()
{
  //Obtém o genoma por linhas
  arquivo = fopen("genoma.txt", "rt");
  for (int i; i < N_LINHAS; i++)
    fgets(genoma[i], sizeof(genoma[i]), arquivo);
  fclose(arquivo);
  
  //Cria a Hash Table
  HT *t = cria_ht(M);
  printf("M = %d\n", M);

  //Inserção + Separação dos blocos de genomas
  printf("Insere %d chaves.\n", N_LINHAS * N_BLOCOS_LINHA);
  for (int i = 0; i < N_LINHAS; i++) {
    char** bloco_genoma = separa_blocos(genoma[i], TAM_BLOCOS, N_BLOCOS_LINHA);
    for (int k = 0; k < N_BLOCOS_LINHA; k++) {
      //printf("%s ", bloco_genoma[k]);
      put(t, bloco_genoma[k]);
    }
  }

  //Salvamento do arquivo em .txt com separado \t
  saveHT(t, "blocos_genoma.txt", "\t");
  //Caso queira em formato .csv é interessante usar ;
  //saveHT(t, "blocos_genoma.csv", ";");

  return 0;
}

char** separa_blocos(char *genoma, int tam_blocos, int qtd_blocos) {
  char** blocos_genoma = (char**) malloc(sizeof(char*) * qtd_blocos);

  for (int i = 0; i < 10; i++) {
    char temp[7];
    int l = strlen(temp);
    substring(temp, genoma + (i * 6), 0, 6);
    blocos_genoma[i] = (char*) malloc(sizeof(char) * (l + 1));
    strcpy(blocos_genoma[i], temp);
  }

  return blocos_genoma;
}

char* substring(char *destination, const char *source, int beg, int n){
    strncpy(destination, (source + beg), n);
    
    return destination;
}