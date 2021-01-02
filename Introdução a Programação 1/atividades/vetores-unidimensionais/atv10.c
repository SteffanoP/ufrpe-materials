#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_NUMEROS_ALEATORIOS 20
#define QTD_NUMEROS_INTERVALO 11

int main() {
    int aleatorios[QTD_NUMEROS_ALEATORIOS], unicos[QTD_NUMEROS_INTERVALO];

    srand(time(NULL));
    printf("Os nu'meros aleato'rios sao: \n");
    for (int i = 0; i < QTD_NUMEROS_ALEATORIOS; i++) {
        aleatorios[i] = rand() % 11;
        printf("%i ", aleatorios[i]);
    }

    //Seta o valor inválido para -1, para não pegar valores lixo
    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++)
        unicos[i] = -1;

    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++) {
        for (int j = 0; j < QTD_NUMEROS_ALEATORIOS; j++) {
            if (i == aleatorios[j]) {
                unicos[i] = i;
                j = QTD_NUMEROS_ALEATORIOS;
            }
        }
    }
    
    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++) {
        if (unicos[i] != -1)
            printf("\n%i", unicos[i]);
    }
    
    return 0;
}