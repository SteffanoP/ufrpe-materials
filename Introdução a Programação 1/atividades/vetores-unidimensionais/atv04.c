#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    int numeros[QTD_NUMEROS], numeros_primos[QTD_NUMEROS];

    printf("Diga 10 numeros e eu te digo quais sao primos\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i",&numeros[i]);
        if ((numeros[i] % 1) == 0) {
            int primo;
            if ((numeros[i] % numeros[i]) == 0)
                primo = 1;

            for (int x = 2; x < numeros[i]; x++) {
                if ((numeros[i] % x) == 0)
                    primo = 0;
            }
            
            if (primo == 1)
                numeros_primos[i] = 1;
            else
                numeros_primos[i] = 0;
        }
    }

    for (int i = 0; i < QTD_NUMEROS; i++) {
        if (numeros_primos[i] == 1)
            printf("O numero %i de posicao %i eh primo\n", numeros[i], i);
        
    }
    
    return 0;
}
