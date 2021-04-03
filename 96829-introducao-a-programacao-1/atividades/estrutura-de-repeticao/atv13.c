#include <stdio.h>

int main() {
    
    for (int i = 0; i < 6; i++) {
        int qtd_x, qtd_0;

        qtd_x = 5 - i;
        qtd_0 = i;

        for (int o = 0; o < qtd_0; o++) {
            printf("0");
        }

        for (int x = 0; x < qtd_x; x++) {
            printf("x");
        }  

        printf("\n");
    }

    return 0;
}
