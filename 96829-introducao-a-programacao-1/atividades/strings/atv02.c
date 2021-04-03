#include <stdio.h>

int main() {
    char nome[20];
    int idade;

    printf("Por favor me diga seu nome\n");
    gets(nome);

    printf("Ola' %s",nome);
    printf(" me diga sua idade e eu lhe digo se voce deve votar\n");
    scanf("%i",&idade);
    getchar();

    if (idade >= 18) {
        printf("%s voce deve votar!\n", nome);
    } else {
        printf("%s voce nao e' obrigado a votar\n", nome);
    }
    printf("Obrigado!");

    return 0;
}