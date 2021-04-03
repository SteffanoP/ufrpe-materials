#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA];

    for (int i = 0; i < TAM_MAX_PALAVRA; i++)
        palavra[i] = NULL;

    printf("Diga sua palavra\n");
    scanf("%s",palavra);
    getchar();

    printf("Sua palavra invertida e' ");
    for (int i = TAM_MAX_PALAVRA; i >= 0; i--) {
        if (palavra[i] != NULL)
            printf("%c",palavra[i]);
    }
    
    
    return 0;
}