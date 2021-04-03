#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MATRIZ_COLUNAS 5
#define TAM_MATRIZ_LINHAS 5

int main() {
    int matriz[TAM_MATRIZ_COLUNAS][TAM_MATRIZ_LINHAS];
    int num_advinhar;

    srand(time(NULL));

    //Aleatoriza a matriz;
    for (int i = 0; i < TAM_MATRIZ_COLUNAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_LINHAS; j++) {
            matriz[i][j] = rand() % 101;
        }
    }

    printf("Diga o numero que voce quer procurar\n");
    scanf("%i",&num_advinhar);

    //Procura o número
    for (int i = 0; i < TAM_MATRIZ_COLUNAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_LINHAS; j++) {
            if (matriz[i][j] == num_advinhar) {
                printf("Numero encontrado na coluna %i e na linha %i",i,j);
                num_advinhar += 101;
            }
        }
    }
    
    //Se não encontrado o número, isto é executado:
    if (num_advinhar < 100)
        printf("Numero nao encontrado");

    return 0;
}