#include <stdio.h>

int main(int argc, char const *argv[]) {
    char opcao;
    int idade;

    printf("Escolha a opcao de filme que voce deseja assistir:\nFilme\t\t\t\tOpcao\nTitanic (16 anos)\t\tT\nPica Pau (Livre)\t\tP\nA volta de Jason (18 anos)\tA\n");
    scanf("%c",&opcao);

    printf("Agora diga a sua idade\n");
    scanf("%i",&idade);

    switch (opcao) {
    case 'T':
        if(idade >= 16)
            printf("Voce comprou o filme Titanic. Bom Filme!");
        else
            printf("Voce nao tem idade para assistir ao filme");
        break;
    case 'P':
            printf("Voce comprou o filme Pica Pau. Bom Filme!");
        break;
    case 'A':
        if(idade >= 18)
            printf("Voce comprou o filme A volta de Jason. Bom Filme!");
        else
            printf("Voce nao tem idade para assistir ao filme");
        break;
    default:
        printf("Opcao invalida");
        break;
    }
    return 0;
}
