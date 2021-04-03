#include <stdio.h>

#define QTD_REAIS 10
int main() {
    float reais[QTD_REAIS] = {1.2,5.4,6.8,2.8,9.7,8.8,-4.3,5.6,3.5,-10};

    for (int i = 0; i < QTD_REAIS; i++) {
        for (int j = 0; j < QTD_REAIS; j++) {
            if (reais[i] < reais[j]) { //Se usado '<' irá ordenar de forma crescente, Se usado '>' irá ordenar de forma decrescente
                float buffer;
                buffer = reais[i];
                reais[i] = reais[j];
                reais[j] = buffer;
            }
        }
    }

    for (int i = 0; i < QTD_REAIS; i++) {
        printf("%.2f \n", reais[i]);
    }
    
    return 0;
}