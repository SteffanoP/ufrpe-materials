/*Escreva um programa em que uma variável recebe um valor lido entre 20 e 100. 
Imprima na tela o valor gerado, caso seja divisível por 3 e por 5. */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a;

    do {
        printf("Manda um numero entre 20 e 100 que divida por 3 e por 5\n");
        scanf("%i",&a);
    } while (!((a >= 20) && (a <= 100)));

    if (((a % 3) == 0) && ((a % 5) == 0)) {
        printf("Seu numero eh:%i",a);
    } else 
        printf("Oxe esse numero nao eh divisivel por 3 ou por 5");

        return 0;
}
