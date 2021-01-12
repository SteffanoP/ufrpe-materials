#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX_LINHAS 5
#define TAM_MAX_COLUNAS 5

int main() {
    int bingo[TAM_MAX_LINHAS][TAM_MAX_COLUNAS];

    srand(time(NULL));

    for (int i = 0; i < TAM_MAX_LINHAS; i++) {
        for (int j = 0; j < TAM_MAX_COLUNAS; j++) {
            int repeticao;

            do {
                repeticao = 0;
                bingo[i][j] = rand() % 100; //Gera os números
                for (int k = 0; k < TAM_MAX_LINHAS; k++) {
                    for (int l = 0; l < TAM_MAX_COLUNAS; l++) {
                        if ((bingo [i][j] == bingo[k][l]) && !((i == k) && (j == l))) //Verifica se foi repetido & se não é ele mesmo que se repete
                            repeticao = 1;
                    }   
                }
            } while (repeticao == 1); //Se repetido, realiza novamente a randomização do número de posição i,j
        }
    }

    //Visualiza a matriz do bingo
    for (int i = 0; i < TAM_MAX_LINHAS; i++) {
        for (int j = 0; j < TAM_MAX_COLUNAS; j++) {
            printf("%i ",bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}