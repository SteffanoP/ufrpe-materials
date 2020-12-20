/* Faça um programa que leia 10 números inteiros (positivos ou negativos). Imprima a média dos valores, ignorando os não positivos.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int num[10];
    float soma, qtd_medias = 0, media;

    printf("Digite os numeros\n");

    for (int i = 1; i <= 10; i++) {
        printf("Diga o numero %i\n", i);
        scanf("%i",&num[i]);
        getchar();
    }
    
    for (int i = 1; i <= 10; i++) {
        if (num[i] >= 0) {
            soma += num[i];
            qtd_medias += 1;
        }
    }

    media = soma/qtd_medias;

    printf("A media eh %.2f",media);

    return 0;
}
