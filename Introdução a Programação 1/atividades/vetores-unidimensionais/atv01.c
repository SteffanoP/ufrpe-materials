#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    float reais[QTD_NUMEROS], soma_positivos = 0;
    int qtd_negativos = 0;
    printf("Ola' por favor preencha a seguinte lista de nu'meros reais que eu te dou algumas info's sobre eles\n");

    for (int i = 0; i < QTD_NUMEROS; i++) {
        printf("Digite o nu'mero real %i de %i\n",i,QTD_NUMEROS);
        scanf("%f",&reais[i]);
        getchar();

        if (reais[i] < 0) 
            qtd_negativos += 1;
        else if (reais[i] > 0) 
            soma_positivos += reais[i];
        
    }

    printf("Quantidade de nu'meros negativos: %i\n", qtd_negativos);
    printf("Soma nu'meros positivos: %.2f\n", soma_positivos);
    
    return 0;
}
