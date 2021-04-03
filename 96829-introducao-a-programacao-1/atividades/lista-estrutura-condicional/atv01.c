/* Elaborar um programa em linguagem C para somar dois números inteiros e mostrar o valor da soma na tela. 
Você só deve imprimir a mensagem se a soma dos números for maior que 10. */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a,b, soma;
    printf("Digite os dois numeros\n");
    scanf("%i %i",&a,&b);
    soma = a + b;

    if (soma > 10) {
        printf("A soma eh: %i", soma);
    } else {
        printf("Sua soma deve ser maior que 10");
    }

    return 0;
}

