#include <stdio.h>

int main() {
    char nome[20];

    printf("Diga seu nome e eu te dou as 4 primeiras letras dele\n");
    gets(nome);

    for (int i = 0; i < 4; i++){
        printf("%c",nome[i]);
    }
    
    return 0;
}