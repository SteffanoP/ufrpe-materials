#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    int a[QTD_NUMEROS], b[QTD_NUMEROS], c[QTD_NUMEROS];

    printf("Diga o valor de A e B e eu te digo A - B\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i %i",&a[i],&b[i]);
        getchar();
        c[i] = a[i] - b[i];
    }
    
    for (int i = 0; i < QTD_NUMEROS; i++) {
        printf("C = %i - %i = ",a[i],b[i]);
        printf("%i\n", c[i]);
    }
    
    return 0;
}
