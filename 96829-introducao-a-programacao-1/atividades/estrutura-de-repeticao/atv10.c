#include <stdio.h>

int main(int argc, char const *argv[]) {
    int ordem_fibonacci, numero_anterior = -1, numero_atual = 1, numero_fibonacci;

    printf("Eu te digo o numero da sequencia de fibonacci e tu me diz a ordem dele\n");
    scanf("%i", &ordem_fibonacci);


    for (int i = 0; i < ordem_fibonacci; i++) {
        numero_fibonacci = numero_anterior + numero_atual;
        numero_anterior = numero_atual;
        numero_atual = numero_fibonacci;
    }

    printf("O numero de sequencia %i na ordem em fibonacci eh %i",ordem_fibonacci,numero_fibonacci);
    
    return 0;
}
