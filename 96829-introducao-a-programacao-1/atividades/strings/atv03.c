#include <stdio.h>

#define TAMANHO_STRING 51

int main() {
    char string[TAMANHO_STRING], c;
    int contador_repeticao = 0;
    
    printf("Manda tua string pra eu estudar ela\n");
    gets(string);
    printf("Agora me diz o caractere que tu quer saber quantas vezes se repete na String\n");
    scanf("%c",&c);

    for (int i = 0; i < TAMANHO_STRING; i++) {
        if (string[i] == c) {
            contador_repeticao += 1;
        }
    }
    
    printf("Esse caractere aparece %i vezes nessa String", contador_repeticao);

    return 0;
}