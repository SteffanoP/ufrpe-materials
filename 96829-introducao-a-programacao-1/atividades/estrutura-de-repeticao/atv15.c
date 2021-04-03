#include <stdio.h>

int main() {
    int tamanho;

    printf("Diga o tamanho do Quadrado, de preferencia um numero impar\n");
    scanf("%i",&tamanho);
    if ((tamanho % 2) == 0) {
        /* Tamanho par*/   
        printf("Para tamanhos pares fica dificil de visualizar ;-;\n");
        printf("mas...\n");
    } 
        /*Tamanho ímpar*/
        int espaco, linhas;
        linhas = tamanho / 2;
        espaco = tamanho - 2;

        //Linhas superiores
        for (int i = 0; i < linhas; i++)
        {
            for (int a = 0; a < i; a++)
                printf(" ");
            
            printf("X");

            for (int b = 0; b < espaco; b++)
                printf(" ");
            espaco -= 2;

            printf("X");

            for (int a = 0; a < i; a++)
                printf(" ");

            printf("\n");
        }

        //Linha Central
        for (int i = 0; i < linhas; i++)
            printf(" ");

        printf("X");

        for (int i = 0; i < linhas; i++)
            printf(" ");

        printf("\n");
        espaco += 2;

        //Linhas inferiores
        for (int i = 0; i < linhas; i++) {
            for (int a = (linhas - 1); a > i; a--)
                printf(" ");

            printf("X");

            for (int b = 0; b < espaco; b++)
                printf(" ");
            espaco += 2;

            printf("X");

            for (int a = (linhas - 1); a > i; a--)
                printf(" ");

            printf("\n");
        }
    
    return 0;
}
