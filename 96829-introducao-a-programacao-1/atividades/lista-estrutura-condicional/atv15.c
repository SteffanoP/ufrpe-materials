#include <stdio.h>

#define PRECOWH1 200
#define PRECOWH2 150
#define PRECOWH3 140

#define PRECOVO1 60
#define PRECOVO2 40
#define PRECOVO3 30

#define PRECOCE1 1.5
#define PRECOCE2 2
#define PRECOCE3 3

#define PRECOCA1 8
#define PRECOCA2 20
#define PRECOCA3 22

int main(int argc, char const *argv[]) {
    int idade;

    printf("Digite sua idade\n");
    scanf("%i",&idade);
    getchar();

    if (idade >= 18) {
        printf("Ta aqui o menu oh:");
        printf("Voce quer Whisky(W), Vodka(V), Cerveja(J) ou Cachaca(C)?\n");
        char opcao_tbebida;
        scanf("%c",&opcao_tbebida);
        getchar();

        switch (opcao_tbebida) {
        case 'W':
            printf("Escolha sua opcao:\n");
            printf("| Codigo |   Nome   | Preco |\n");
            printf("|:------:|:--------:|:-----:|\n");
            printf("|   100  | Whisky 1 |  200  |\n");
            printf("|   101  | Whisky 2 |  150  |\n");
            printf("|   102  | Whisky 3 |  140  |\n");
            break;
        case 'V':
            printf("Escolha sua opcao:\n");
            printf("| Codigo |   Nome  |Preco |\n");
            printf("|:------:|:-------:|:----:|\n");
            printf("|   200  | Vodka 1 |  60  |\n");
            printf("|   201  | Vodka 2 |  40  |\n");
            printf("|   202  | Vodka 3 |  30  |\n");
            break;
        case 'J':
            printf("Escolha sua opcao:\n");
            printf("| Codigo |    Nome   |  Preco |\n");
            printf("|:------:|:---------:|:------:|\n");
            printf("|   300  | Cerveja 1 |  1.50  |\n");
            printf("|   301  | Cerveja 2 |   2.0  |\n");
            printf("|   302  | Cerveja 3 |   3.0  |\n");
            break;
        case 'C':
            printf("Escolha sua opcao:\n");
            printf("| Codigo |    Nome   |  Preco  |\n");
            printf("|:------:|:---------:|:-------:|\n");
            printf("|   400  | Cachaça 1 |    8.0  |\n");
            printf("|   401  | Cachaça 2 |   20.0  |\n");
            printf("|   402  | Cachaça 3 |   22.0  |\n");
            break;
        default:
            printf("Opcao invalida");
            break;
        }

        int opcao_cbebida, qtd_bebidas;
        float subtotal;
        printf("Digite o codigo:");
        scanf("%i",&opcao_cbebida);
        getchar();
        printf("Quantas quantidades voce deseja?");
        scanf("%i",&qtd_bebidas);

        switch (opcao_cbebida) {
        case 100:
            subtotal = PRECOWH1;
            break;
        case 101:
            subtotal = PRECOWH2;
            break;
        case 102:
            subtotal = PRECOWH3;
            break;
        case 200:
            subtotal = PRECOVO1;
            break;
        case 201:
            subtotal = PRECOVO2;
            break;
        case 202:
            subtotal = PRECOVO3;
            break;
        case 300:
            subtotal = PRECOCE1;
            break;
        case 301:
            subtotal = PRECOCE2;
            break;
        case 302:
            subtotal = PRECOCE3;
            break;
        case 400:
            subtotal = PRECOCA1;
            break;
        case 401:
            subtotal = PRECOCA2;
            break;
        case 402:
            subtotal = PRECOCA3;
            break;
        default:
            printf("Opcao invalida");
            break;
        }

        if (qtd_bebidas >= 1) {
            if (qtd_bebidas > 100)
                subtotal = (subtotal * qtd_bebidas) * 0.65;
            else if (qtd_bebidas > 50)
                subtotal = (subtotal * qtd_bebidas) * 0.70;
            else if (qtd_bebidas > 5)
                subtotal = (subtotal * qtd_bebidas) * 0.90;
            else
                subtotal = subtotal * qtd_bebidas;
        } else
            printf("Quantidade invalida");

        printf("O seu subtotal e: R$%.2f",subtotal);
    } else 
        printf("Voce eh de menor e nao pode comprar bebidas");
    
    return 0;
}
