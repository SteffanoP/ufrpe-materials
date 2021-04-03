#include <stdio.h>

#define PRECOCQ 1.2
#define PRECOBS 1.3
#define PRECOBO 1.5
#define PRECOHR 1.2
#define PRECOCR 1.3
#define PRECORF 1


int main(int argc, char const *argv[]) {
    int codigo, quantidade;
    float subtotal;

    printf("Aqui esta o cardapio\n");

    printf("|  Especificacao  | Codigo | Preco |\n");
    printf("|:---------------:|:------:|:-----:|\n");
    printf("| Cachorro Quente |   100  |  1.20 |\n");
    printf("|  Bauru Simples  |   101  |  1.30 |\n");
    printf("|  Bauru com ovo  |   102  |  1.50 |\n");
    printf("|    Hamburguer   |   103  |  1.20 |\n");
    printf("|  Cheeseburguer  |   104  |  1.30 |\n");
    printf("|   Refrigerante  |   105  |  1.00 |\n");

    printf("Digite o codigo do produto desejado e o quanto voce deseja comprar\n");

    scanf("%i %i",&codigo,&quantidade);

    switch (codigo) {
    case 100:
        subtotal = PRECOCQ * quantidade;
        break;
    case 101:
        subtotal = PRECOBS * quantidade;
        break;
    case 102:
        subtotal = PRECOBO * quantidade;
        break;
    case 103:
        subtotal = PRECOHR * quantidade;
        break;
    case 104:
        subtotal = PRECOCR * quantidade;
        break;
    case 105:
        subtotal = PRECORF * quantidade;
        break;
    default:
        printf("codigo invalido");
        break;
    }

    printf("Voce deve R$%.2f",subtotal);

    return 0;
}
