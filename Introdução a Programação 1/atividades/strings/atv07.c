#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA], c;
    int qtd_vogais = 0;

    for (int i = 0; i < TAM_MAX_PALAVRA; i++)
        palavra[i] = NULL;

    printf("Entre com sua palavra\n");
    scanf("%s",palavra);
    getchar();
    printf("Entre com o caractere que voce substituir\n");
    scanf("%c",&c);

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
        if ((palavra[i] == 'a') || (palavra[i] == 'e') || (palavra[i] == 'i') || (palavra[i] == 'o') || (palavra[i] == 'u')) {
            qtd_vogais += 1;
            palavra[i] = c;
        }
    }
    printf("A sua palavra tem %i vogais\n",qtd_vogais);
    printf("Se as vogais forem trocados por seu caractere, ficara' da seguinter forma %s",palavra);
    
    return 0;
}