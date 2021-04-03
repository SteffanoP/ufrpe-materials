#include <stdio.h>

#define TAM_MATRIZ_COLUNAS 4
#define TAM_MATRIZ_LINHAS 4

int main() {
    int numeros[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
    int qtd_num_maior_10 = 0;

    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            if (numeros[i][j] > 10)
                qtd_num_maior_10 = qtd_num_maior_10 + 1;
        }
    }

    printf("Sao %i numeros maiores que 10 na matriz",qtd_num_maior_10);
    
    return 0;
}