#include <stdio.h>

#define QTD_NUMEROS 10

int main() {
    int a[QTD_NUMEROS],b[QTD_NUMEROS],c[QTD_NUMEROS*2];

    printf("Diga os valores de A e B na seguinte ordem: a b\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i %i",&a[i],&b[i]);
        getchar();
    }

    //ordenação índices pares
    for (int i = 0, j = 0; j < QTD_NUMEROS; i+=2, j++)
        c[i] = a[j];

    //ordenação índices ímpares
    for (int i = 1, j = 0; j < QTD_NUMEROS; i+=2, j++)
        c[i] = b[j];
    
    for (int i = 0; i < QTD_NUMEROS*2; i++) {
        printf("%i\n",c[i]);
    }
    
    return 0;
}