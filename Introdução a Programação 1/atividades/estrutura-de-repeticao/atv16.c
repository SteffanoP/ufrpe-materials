#include <stdio.h>

#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)

#define SENHA_CAIXA 123

#define PRECO_FEIJAO 2
#define PRECO_ARROZ 1.5
#define PRECO_CARNE 10
#define PRECO_TOMATE 3
#define PRECO_CEBOLA 2.5

int main(int argc, char const *argv[]) {
    int caixa_ativo, senha;

    for (int i = 0; i < 3; i++) {
        printf("Digite a senha para ativar o caixa\n");
        scanf("%i",&senha);
        getchar();

        if (senha == SENHA_CAIXA) {
            caixa_ativo = 1;
            i = 4;
        } else {
            printf("Senha incorreta! (Tentativa %i/3)\n",i+1);
        }
    }
    
    while (caixa_ativo == 1) {
        char opcao_operacao;
        printf("Digite o codigo da operacao:\n");
        printf("Iniciar nova compra: 'S'\n");
        printf("Fechar atividade do caixa: 'F'\n");
        scanf("%c",&opcao_operacao);
        getchar();

        if (opcao_operacao == 'S') {
            int opcao_carrinho = 1; //Redundante, para aplicacoes no futuro talvez...
            int total_quantidade = 0;
            float subtotal_carrinho = 0;

            while (opcao_carrinho == 1) {
                int opcao_compra;
                printf("---- Menu de produtos ----\n");
                printf("Co'digo\tItem\tPreco(R$)\n");
                fputs("1\tFeijao\t"STRINGIFY(PRECO_FEIJAO)"\n",stdout);
                fputs("2\tArroz\t"STRINGIFY(PRECO_ARROZ)"\n",stdout);
                fputs("3\tCarne\t"STRINGIFY(PRECO_CARNE)"\n",stdout);
                fputs("4\tTomate\t"STRINGIFY(PRECO_TOMATE)"\n",stdout);
                fputs("5\tCebola\t"STRINGIFY(PRECO_CEBOLA)"\n",stdout);
                printf("Digite o codigo do item a ser comprado\n");

                scanf("%i",&opcao_compra);
                getchar();

                switch (opcao_compra) {
                    int quantidade;
                    char opcao_finalizar;

                case 1:
                    printf("Quanto voce deseja adicionar?\n");
                    scanf("%i",&quantidade);
                    total_quantidade += quantidade;
                    subtotal_carrinho += (quantidade*PRECO_FEIJAO);
                    break;

                case 2:
                    printf("Quanto voce deseja adicionar?\n");
                    scanf("%i",&quantidade);
                    total_quantidade += quantidade;
                    subtotal_carrinho += (quantidade*PRECO_ARROZ);
                    break;

                case 3:
                    printf("Quanto voce deseja adicionar?\n");
                    scanf("%i",&quantidade);
                    total_quantidade += quantidade;
                    subtotal_carrinho += (quantidade*PRECO_CARNE);
                    break;

                case 4:
                    printf("Quanto voce deseja adicionar?\n");
                    scanf("%i",&quantidade);
                    total_quantidade += quantidade;
                    subtotal_carrinho += (quantidade*PRECO_TOMATE);
                    break;

                case 5:
                    printf("Quanto voce deseja adicionar?\n");
                    scanf("%i",&quantidade);
                    total_quantidade += quantidade;
                    subtotal_carrinho += (quantidade*PRECO_CEBOLA);
                    break;

                case 6:
                    printf("Voce deseja finalizar a compra?(S/N)\n");
                    scanf("%c",&opcao_finalizar);

                    if (opcao_finalizar == 'S')
                        opcao_carrinho = 0;

                    break;
            
                default:
                    printf("Entrada inva'lida\n");
                    break;
                }

                printf("Quantidade de items no carrinho: %i\n",total_quantidade);
                printf("Subtotal do carrinho: R$ %.2f\n", subtotal_carrinho);
            }    
            printf("Total a pagar R$ %.2f\n\n", subtotal_carrinho);
        }
        
        if (opcao_operacao == 'F')
            caixa_ativo = 0;
    }
    printf("Caixa Fechado!");
    
    return 0;
}
