#include <stdio.h>

#define TAM_MAX_FRASE 81

int main() {
    char frase[TAM_MAX_FRASE];
    int qtd_brancos = 0, qtd_a = 0;

    printf("Por favor escreva uma frase com ate' 80 caracteres\n");
    gets(frase);

    for (int i = 0; i < TAM_MAX_FRASE; i++) {
        if (frase[i] == ' ')
            qtd_brancos += 1;

        if (frase[i] == 'a')
            qtd_a += 1;

        if ((frase[i] == 'a') || (frase[i] == 'e') || (frase[i] == 'i') || (frase[i] == 'o') || (frase[i] == 'u'))
            frase[i] = 'X';
    }
    
    printf("A sua frase ficou assim:\n");
    puts(frase);
    printf("Quantidade de espacos: %i\nQuantidade de letras 'a': %i",qtd_brancos,qtd_a);

    return 0;
}