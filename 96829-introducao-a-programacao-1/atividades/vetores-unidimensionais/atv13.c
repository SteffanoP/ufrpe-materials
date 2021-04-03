/* Considere que as posições serão os códigos */
#include <stdio.h>

#define TAM_MAX_CODIGO 10

int main() {
    int opcao_menu = 0;
    int codigos[TAM_MAX_CODIGO], codigo_atual = 0;
    for (int i = 0; i < TAM_MAX_CODIGO; i++) //Disponibiliza todos os códigos
        codigos[i] = -1; //Estabelece o notificador -1 como código disponível

    codigos[0] = 0; //Código 000 é setado como inválido;

    do {
        //Variáveis produtos
        int quantidade[TAM_MAX_CODIGO];
        float precos[TAM_MAX_CODIGO];

        printf("MENU\n");
        printf("1. Cadastrar Mercadoria;\n");
        printf("2. Consultar Mercadoria;\n");
        printf("3. Valor total em Mercadorias;\n");
        printf("4. Sair;\n");
        scanf("%i",&opcao_menu);
        getchar();
        
        while (opcao_menu == 1) {
            for (int i = 0; i < TAM_MAX_CODIGO; i++) {
                if (codigos[i] == -1) { //Verifica o próximo código disponível para cadastro
                    codigo_atual = i;
                    codigos[i] = i;
                    i = TAM_MAX_CODIGO;
                }
            }
            //A alocação de código é feita dinâmicamente
            printf("Cadastre o seu produto(%03i) da seguinte forma: Quantidade Preco\n",codigo_atual);
            scanf("%i %f", &quantidade[codigo_atual],&precos[codigo_atual]);
            getchar();
            
            //Visualização do cadastro
            printf("Co'digo\tQuantidade\tPreco\n");
            printf("%03i\t%i\t%.2f\n", codigos[codigo_atual],quantidade[codigo_atual],precos[codigo_atual]);
            
            char opcao_continua;
            printf("Deseja cadastrar algum outro produto?(S/N)\n");
            scanf("%c",&opcao_continua);
            getchar();
            if (opcao_continua == 'N')
                opcao_menu = 0;
        }

        if (opcao_menu == 2) {
            printf("Digite o codigo do produto que voce deseja consultar\n");
            scanf("%i",&codigo_atual);
            printf("Co'digo\tQuantidade\tPreco\n");
            printf("%03i\t%i\t%.2f\n", codigos[codigo_atual],quantidade[codigo_atual],precos[codigo_atual]);
            opcao_menu = 0;
        }

        if (opcao_menu == 3) {
            float vt_mercadorias = 0;

            for (int i = 0; i < TAM_MAX_CODIGO; i++) {
                if (codigos[i] != -1) //Calcula o subtotal de todos os produtos válidos
                    vt_mercadorias += (float)quantidade[i]*(float)precos[i];
            }
            printf("%.2f\n",vt_mercadorias);

            opcao_menu = 0;
        }

    } while (opcao_menu != 4);
    printf("Obrigado!");
    
    return 0;
}