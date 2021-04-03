#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_CLIENTES 3

typedef struct 
{
    char nome[21];
    int cpf;
    unsigned long numero_conta;
    float saldo;
} Conta;

int main() {
    srand(time(NULL));

    Conta clientes[QTD_CLIENTES];

    printf("Vamos criar as contas dos clientes\n");
    for (int i = 0; i < QTD_CLIENTES; i++)
    {
        printf("Cliente %i \n",i+1);
        printf("Diga seu nome\n");
        fgets(clientes[i].nome, 21, stdin);
        printf("Agora diga seu CPF\n");
        scanf("%i",&clientes[i].cpf);
        getchar();

        clientes[i].numero_conta = rand() % 10000000001;
        printf("Sua conta sera %lu\n",clientes[i].numero_conta);
        printf("Eh necessario que voce faca um deposito inicial\n");
        printf("Quanto voce deseja depositar?\n");
        scanf("%f",&clientes[i].saldo);
        getchar();
    }

    int opcao_menu;
    while (1)
    {
        printf("--- Menu de Operacoes ---\n");
        printf("1 - Saque\n");
        printf("2 - Deposito\n");
        printf("3 - Consultas\n");

        printf("Qual operacao voce deseja realizar?\n");
        scanf("%i",&opcao_menu);
        
        unsigned long numero_conta = 0;
        float valor_transacao = 0;
        switch (opcao_menu)
        {
        case 1:
            printf("Digite sua conta e o valor do saque\n");
            scanf("%lu %f",&numero_conta,&valor_transacao);
            getchar();
            break;
        case 2:
            printf("Digite sua conta e o valor do deposito\n");
            scanf("%lu %f",&numero_conta,&valor_transacao);
            getchar();
            
            break;
        case 3:
            printf("Digite sua conta\n");
            scanf("%lu",&numero_conta);
            getchar();
            
            break;
        
        default:
            printf("Operacao não identificada\n");
            break;
        }

        int cliente;
        for (cliente = 0; cliente < QTD_CLIENTES; cliente++)
        {
            if (numero_conta == clientes[cliente].numero_conta)
                break;
        }
        
        printf("Ola %s\n",clientes[cliente].nome);
        if (opcao_menu == 1) {
            clientes[cliente].saldo -= valor_transacao;
            printf("Saque Realizado com Sucesso\n");
            printf("Seu saldo agora eh %.2f\n",clientes[cliente].saldo);
        } else if (opcao_menu == 2) {
            clientes[cliente].saldo += valor_transacao;
            printf("Deposito Realizado com Sucesso\n");
            printf("Seu saldo agora eh %.2f\n",clientes[cliente].saldo);
        } else if (opcao_menu == 3) {
            printf("Seu saldo agora eh %.2f\n",clientes[cliente].saldo);
        }
        
    }
    
    
    return 0;
}