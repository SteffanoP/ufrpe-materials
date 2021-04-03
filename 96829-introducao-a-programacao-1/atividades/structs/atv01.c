#include <stdio.h>

#define TAM_MAX_NOME 21

#define QTD_PESSOAS 5

typedef struct 
{
    char nome[TAM_MAX_NOME];
    float altura;
    float peso;
    int cpf;
    char sexo;
} Pessoa;

int main() {
    Pessoa pessoas[5] = {
        {"Otavio", 1.45f, 66.0f, 11111111111, 'm'},
        {"Leticia", 1.66f, 80.0f, 22222222222, 'f'},
        {"Gustavo", 1.80f, 81.0f, 33333333333, 'm'},
        {"Eustaquio", 1.55f, 70.0f, 44444444444, 'm'},
        {"Fernanda", 1.70f, 64.0f, 55555555555, 'f'}
    };

    int cpf;

    printf("Digite seu CPF\n");
    scanf("%i",&cpf);

    for (int i = 0; i < QTD_PESSOAS; i++)
    {
        if (cpf == pessoas[i].cpf) {
            printf("Seu nome eh %s e seu IMC eh %.2f",pessoas[i].nome, pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura));
        }
    }

    return 0;
}

