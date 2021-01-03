#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tam;
    srand(time(NULL));
    
    printf("Qual o tamanho do texto que voce pretende digitar?\n");
    scanf("%i",&tam);
    getchar();
    tam += 1; //para o ultimo digito
    char texto[tam];

    for (int i = 0; i < tam; i++)
        texto[i] = NULL;
    
    printf("Por favor digite seu texto abaixo\n");
    gets(texto);

    for (int i = 0; i < tam; i++) {
        int aleatorio = rand() % 2;

        if ((aleatorio == 0) && ((texto[i]) >= 65) && (texto[i] <= 90))
            texto[i] += 32; //Ver Tabela ASCII
        
        if ((aleatorio == 1) && ((texto[i]) >= 97) && (texto[i] <= 122))
            texto[i] -= 32; //Ver Tabela ASCII
    }
    
    printf("Seu texto enlouqueceu e ficou assim:\n");
    puts(texto);

    return 0;
}