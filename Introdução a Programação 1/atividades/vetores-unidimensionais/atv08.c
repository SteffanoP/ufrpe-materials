#include <stdio.h>

#define QTD_ELEMENTOS 10

int main() {
    int vetor[QTD_ELEMENTOS], existe_elemento_disponivel;

    //Disponibilizar todos os vetores
    for (int i = 0; i < QTD_ELEMENTOS; i++) {
        vetor[i] = -1;
    }
    
    existe_elemento_disponivel = 1;
    
    do {
        int posicao;
        printf("Em qual posicao voce deseja inserir um elemento (0 - 9)?\n");
        scanf("%i",&posicao);
        getchar();

        if ((posicao < 0) || (posicao > 9)) {
            printf("Posicao inva'lida\n");
        } else if (vetor[posicao] == -1) {
            printf("Por favor digite o valor ao qual voce deseja preencher\n");
            scanf("%i",&vetor[posicao]);
            getchar();
        } else {
            printf("Essa posicao nao esta mais disponi'vel\n");
        }
        
        existe_elemento_disponivel = 0;
        for (int i = 0; i < QTD_ELEMENTOS; i++) {
            if (vetor[i] == -1)
                existe_elemento_disponivel = 1;
            
        }    
        
    } while (existe_elemento_disponivel == 1);

    printf("Todos os vetores foram preenchidos");
    
    return 0;
}