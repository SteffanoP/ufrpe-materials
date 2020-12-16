#include <stdio.h>

int main(int argc, char const *argv[]) {
    int idade;
    float totalpg;

    printf("Digite sua idade\n");
    scanf("%i",&idade);

    if (idade <= 10) {
        totalpg = 30;
    } else if (idade <= 29) {
        totalpg = 60;
    } else if (idade <= 45) {
        totalpg = 120;
    } else if (idade <= 59) {
        totalpg = 150;
    } else if (idade <= 65) {
        totalpg = 250;
    } else if (idade > 65) {
        totalpg = 400;
    }

    printf("Total a pagar: R$%.2f", totalpg);
    
    return 0;
}
