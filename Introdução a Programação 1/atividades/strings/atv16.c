#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA], rascunho_palavra[TAM_MAX_PALAVRA];
    int tentativas_erradas = 0;

    printf("Ola, diga a palavra (use letras maiusculas) que voce deseja advinhar\n");
    scanf("%s",palavra);
    getchar();

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
        if ((palavra[i] >= 65) && (palavra[i] <= 90)) {
            rascunho_palavra[i] = '_';
        }
    }

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) 
        printf("%c ",rascunho_palavra[i]);
    

    printf("Voce tem 3 chances de acertar as letras\n");
    while (tentativas_erradas < 3) {
        char letra;
        int erro = 1;
        printf("Diga uma letra\n");
        scanf("%c",&letra);
        getchar();

        for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
            if (palavra[i] == letra) { //Testa cada letra individualmente
                rascunho_palavra[i] = letra;
                erro = 0;
            }
        }
        
        if (erro == 1)  //Verifica que foi errado e enumera tentativa errada
            tentativas_erradas += 1;

        erro = NULL;
        for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
            printf("%c ", rascunho_palavra[i]); //print do rascunho da palavra
            if (rascunho_palavra[i] == '_') {
                erro = 1;
            }    
        }
        
        if (erro == NULL) {
            tentativas_erradas = NULL;
            break;
        }
        
        printf("Voce tem %i chances de 3 chances\n",3-tentativas_erradas);
    }
    
    if (tentativas_erradas == NULL) {
        printf("Parabens, voce ganhou a palavra era %s",palavra);
    } else {
        printf("Infelizmente voce perdeu o jogo, a palavra era %s",palavra);
    }

    return 0;
}