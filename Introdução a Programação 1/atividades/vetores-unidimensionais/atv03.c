#include <stdio.h>

#define QTD_NUMEROS 10
int main(int argc, char const *argv[]) {
    int numeros[QTD_NUMEROS], posicao_maior_numero = 0;

    printf("Diga 10 numeros e eu te digo o maior");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i",&numeros[i]);
        if (numeros[i] >= numeros[posicao_maior_numero])
            posicao_maior_numero = i;
    }

    printf("O maior numero eh %i e sua posicao eh %i", numeros[posicao_maior_numero],posicao_maior_numero);
    
    return 0;
}
