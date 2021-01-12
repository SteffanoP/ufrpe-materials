#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MATRIZ_LINHAS 4
#define TAM_MATRIZ_COLUNAS 4

int main() {
    int matriz1[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int matriz2[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int matriz3[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];

    srand(time(NULL));

    //Aleatoriza as duas matrizes
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            matriz1[i][j] = rand() % 21;
            matriz2[i][j] = rand() % 21;
        }
    }
    
    //Compara os valores da matriz 1 e matriz 2, quanto aos seus maiores
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            if (matriz1[i][j] >= matriz2[i][j])
                matriz3[i][j] = matriz1[i][j];
            else if (matriz2[i][j] > matriz1[i][j])
                matriz3[i][j] = matriz2[i][j];
        }
    }

    //Print matriz3
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            printf("%i ",matriz3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
