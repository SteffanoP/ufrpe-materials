#include <stdio.h>

#define TAMANHO_NOME_MAXIMO 21

int main() {
    char nome[TAMANHO_NOME_MAXIMO];
    int qtd_letras = 0;

    for (int i = 0; i < TAMANHO_NOME_MAXIMO; i++)
        nome[i] = NULL;
    
    printf("Diga seu nome\n");
    gets(nome);

    for (int i = 0; i < TAMANHO_NOME_MAXIMO; i++) {
        if((nome[i] != NULL) && (nome[i] != ' '))
            qtd_letras += 1;
    }

    printf("O nome %s possui %i letras\n",nome,qtd_letras);
    
    return 0;
}