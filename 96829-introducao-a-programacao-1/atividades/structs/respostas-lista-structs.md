# Structs

## 1

Escrever um programa que cadastre o nome, a altura, o peso, o cpf e sexo de algumas pessoas. Para isso, você deve criar uma struct Pessoa com esses dados:

1. Cadastre 5 pessoas com as informações necessárias.
2. Peça para o usuário informar um cpf. Se o cpf existir, imprima o nome e o IMC da pessoa encontrada.

```c
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
```

## 2

Escreva um programa que simule contas bancárias, com as seguintes especificações:

- Ao iniciar o programa vamos criar contas bancárias para três clientes.
- Cada conta cliente terá o nome, CPF.
- Cada conta terá número da conta, cpf do cliente e saldo;
- No ato da criação da conta o cliente precisará fazer um depósito inicial.
- Após as contas serem criadas, o sistema deverá possibilitar realizações de saques ou depósitos nas contas. OBS: Crie um menu com essas opções.
- Para fazer qualquer operação, o cliente deverá informar o número da conta e o valor.
- Sempre que uma operação de saque ou depósito for realizada, o sistema deverá imprimir o nome do titular e o saldo final da conta.

```c
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
```

## 3

Crie um sistema de agenda telefônica. Para isto, você deve criar a struct Contato, que possui nome e telefone. Neste sistema, existe um menu com as seguintes opções:

- Inserir um contato
- Visualizar todos os contatos
- Alterar nome ou numero do contato
- Sair
