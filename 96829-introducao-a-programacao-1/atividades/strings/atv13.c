#include <stdio.h>
#include <string.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char maior_palavra[TAM_MAX_PALAVRA] = "", menor_palavra[TAM_MAX_PALAVRA] = "";

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) //Maior palavra possível
        menor_palavra[i] = 'Z';
    

    while (1) {
        char palavra[TAM_MAX_PALAVRA];

        printf("Diga sua palavra\n");
        scanf("%s",palavra);
        getchar();

        if ((strcmp(palavra, maior_palavra)) > 0 )
            strcpy(maior_palavra,palavra);

        if ((strcmp(palavra, menor_palavra)) < 0 )
            strcpy(menor_palavra,palavra);

        printf("Maior palavra eh: %s\n",maior_palavra);
        printf("Menor palavra eh: %s\n",menor_palavra);
    }
    return 0;
}