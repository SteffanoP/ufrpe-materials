#include <stdio.h>

#define QTD_NOTAS 10

int main() {
    float notas[QTD_NOTAS], soma_media = 0, media;
    int qtd_notas_acima_media = 0;
    printf("Por favor insira as 10 notas:\n");

    for (int i = 0; i < QTD_NOTAS; i++) {
        scanf("%f",&notas[i]);
        getchar();
        soma_media += notas[i];
    }

    media = soma_media/QTD_NOTAS;
    
    for (int i = 0; i < QTD_NOTAS; i++) {
        if (notas[i] > media)
            qtd_notas_acima_media += 1;
    }

    printf("Me'dia: %.2f\n",media);
    printf("Notas acima da me'dia %i\n",qtd_notas_acima_media);
    
    return 0;
}