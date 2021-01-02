#include <stdio.h>

#define TAM_VETOR_A 10
#define TAM_VETOR_B 20

int main() {
    int a[TAM_VETOR_A] = {0,1,2,3,4,5,6,7,8,9};
    int b[TAM_VETOR_B] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int posicao_n_comuns_b[TAM_VETOR_B];
    
    for (int i = 0; i < TAM_VETOR_B; i++) {
        for (int j = 0; j < TAM_VETOR_A; j++) {
            if (a[j] != b[i])
                posicao_n_comuns_b[i] = i;
            else {
                posicao_n_comuns_b[i] = NULL;
                j = TAM_VETOR_A;
            }
        }
    }

    for (int i = 0; i < TAM_VETOR_B; i++) {
        if (posicao_n_comuns_b[i] != NULL) 
            printf("%i \n",b[posicao_n_comuns_b[i]]);
    }

    return 0;
}