/* Escreva um programa que leia um número inteiro e calcule a soma de todos os divisores desse número, com exceção dele próprio.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int num, soma;

    printf("Mano diz o numero ae\n");
    scanf("%i", &num);
    getchar();

    for (int i = 1; i < num; i++) {
        if ((num % i) == 0)
            soma += i;
    }

    printf("Tua soma eh %i\n",soma);
    
    return 0;
}
