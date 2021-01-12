#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_MAX_INIMIGOS 5
#define QTD_MAX_HEROIS 2
#define QTD_MAX_ARMAS 4
#define QTD_MAX_POCOES 2

#define TAM_MAX_TABULEIRO 5 //5x5

int main() {
    char tabuleiro[TAM_MAX_TABULEIRO][TAM_MAX_TABULEIRO];

    srand(time(NULL));

    //Seta todos os espaços como nulo, como se fosse o tabuleiro nu ( ͡° ͜ʖ ͡°)
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++) {
            tabuleiro[i][j] = NULL;
        }
    }

    //Posicionamento inimigos
    for (int a = 0; a < QTD_MAX_INIMIGOS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'I';
    }

    //Posicionamento armas
    for (int a = 0; a < QTD_MAX_ARMAS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'A';
    }

    //Posicionamento heróis
    for (int a = 0; a < QTD_MAX_HEROIS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'H';
    }

    //Posicionamento porções
    for (int a = 0; a < QTD_MAX_POCOES; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'P';
    }
    
    //Print do Tabuleiro
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++) {
            if (tabuleiro[i][j] == NULL) 
                printf("   |",tabuleiro[i][j]);
            else 
                printf(" %c |",tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}