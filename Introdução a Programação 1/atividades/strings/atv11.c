#include <stdio.h>
#include <limits.h>
#include <string.h>

#define QTD_MAX_PESSOAS 1000

#define TAM_MAX_NOME 21

int main() {
     char nome_maior_idade[TAM_MAX_NOME], nome_menor_idade[TAM_MAX_NOME];
     int maior_idade = 0, menor_idade = INT_MAX;
    
    while (1) {
        char nome[TAM_MAX_NOME];
        int idade;

        printf("Diga seu nome\n");
        scanf("%s",nome);
        getchar();
        printf("Agora diga sua idade\n");
        scanf("%i",&idade);
        getchar();

        if (idade < 0)   
            break;        

        if (idade < menor_idade) {
            menor_idade = idade;
            strcpy(nome_menor_idade,nome);
        }
        
        if (idade > maior_idade) {
            maior_idade = idade;
            strcpy(nome_maior_idade,nome);
        }
    } 

    printf("Pessoa de maior idade: %s\n",nome_maior_idade);
    printf("Pessoa de menor idade: %s\n",nome_menor_idade);
    
    return 0;
}