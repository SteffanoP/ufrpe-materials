/* Uma empresa deseja dar 20% de aumento para aqueles funcionários 
que possuem salário menor ou igual a R$1000,00 e um aumento de 10%
para aqueles que possuem salários maiores que R$1000,00. Escreva um programa
que pede para o usuário digitar o seu salário. Imprima seu 
novo salário na tela.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float salario, novo_salario;

    printf("Digite seu salario:\n");
    scanf("%f",&salario);

    if (salario <= 1000) {
        novo_salario = 1.2*salario; 
    } else {
        novo_salario = 1.1*salario;
    }

    printf("Seu novo salario eh: R$%.2f",novo_salario);

    return 0;
}
