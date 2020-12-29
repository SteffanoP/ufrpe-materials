#include <stdio.h>

int main(int argc, char const *argv[]) {
    int opcao;
    do {
        printf("O menu:\n");
        printf("1. Imprimir 'Ola'\n");
        printf("2. Imprimir 'Bem vindo'\n");
        scanf("%i", &opcao);
        switch (opcao) {
        case 1:
            printf("Ola'\n");
            break;
        
        case 2:
            printf("Bem vindo\n");
            break;
        
        default:
            break;
        }
        
    } while (opcao != 3);
    
    return 0;
}
