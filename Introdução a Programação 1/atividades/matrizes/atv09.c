/* Para essa questão é necessário observar que a movimentação do cavalo é sempre em L, logo será
 * sempre uma movimentação de 2 colunas e 1 linha OU 1 coluna e 2 linhas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX_TABULEIRO 8 //8x8

#define POSICAO_CAVALO_LINHA 4-1
#define POSICAO_CAVALO_COLUNA 4-1

#define QTD_MAX_PEDRAS 8

int main() {
    char tabuleiro[TAM_MAX_TABULEIRO][TAM_MAX_TABULEIRO];

    srand(time(NULL));

    //Seta todos os espaços como nulo, como se fosse o tabuleiro nu ( ͡° ͜ʖ ͡°)
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++){
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++)
            tabuleiro[i][j] = NULL;
    }

    //Posicionamento do cavalo
    tabuleiro[POSICAO_CAVALO_LINHA][POSICAO_CAVALO_COLUNA] = 'C';

    //Posicionamento randomizado das pedras
    for (int a = 0; a < QTD_MAX_PEDRAS; a++) {
        int i, j;
        do {
            i = rand() % 9;
            j = rand() % 9;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'P';
    }

    //Condição para capturar pedra
    for (int i = -2; i <= +2; i++) {
        if (i != 0) {
            if ((i == -2) || (i == 2)) { //Para as linhas -2 e +2
                for (int j = -1; j <= +1; j+=2) { //Para as colunas -1 e +1
                    if (tabuleiro[POSICAO_CAVALO_LINHA-i][POSICAO_CAVALO_COLUNA-j] == 'P') {
                        printf("Pode haver captura na linha %i e coluna %i\n",(POSICAO_CAVALO_LINHA-i)+1,(POSICAO_CAVALO_COLUNA-j)+1);
                    }
                } 
            }

            if ((i == -1) || (i == 1)) { //Para as linhas -1 e +1
                for (int j = -2; j <= +2; j += 4) { //Para as colunas -2 e +2
                    if (tabuleiro[POSICAO_CAVALO_LINHA - i][POSICAO_CAVALO_COLUNA - j] == 'P') {
                        printf("Pode haver captura na linha %i e coluna %i\n", (POSICAO_CAVALO_LINHA - i) + 1, (POSICAO_CAVALO_COLUNA - j) + 1);
                    }
                }
            }
        }
    }
    

    //Print do Tabuleiro
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == NULL)
                printf("   |", tabuleiro[i][j]);
            else
                printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}