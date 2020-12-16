/*Faça um programa que mostre ao usuário um menu com 4 opções de operações matemáticas (+, -, /, *). O usuário escolhe uma das opções e o seu programa então pede dois valores reais, realiza a operação e imprime o resultado na tela.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char operacao;
    float a,b;
    printf("Digite sua expressao no formato: a + b, a - b, a * b ou a / b\n");
    scanf("%f %c %f",&a,&operacao,&b);

    switch (operacao) {
    case '+':
        printf("%.2f",a + b);
        break;
    case '-':
        printf("%.2f",a - b);
        break;
    case '*':
        printf("%.2f",a * b);
        break;
    case '/':
        printf("%.2f", a / b);
        break;
    default:
        printf("Operacao desconhecida");
        break;
    }
    return 0;
}
