# Estrutura de decisão condicional

## #1

Elaborar um programa em linguagem C para somar dois números inteiros e mostrar o valor da soma na tela. Você só deve imprimir a mensagem se a soma dos números for maior que 10.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a,b, soma;
    printf("Digite os dois numeros\n");
    scanf("%i %i",&a,&b);
    soma = a + b;

    if (soma > 10) {
        printf("A soma eh: %i", soma);
    } else {
        printf("Sua soma deve ser maior que 10");
    }

    return 0;
}
```

## #2

Escreva um programa em que uma variável recebe um valor lido entre 20 e 100. Imprima na tela o valor gerado, caso seja divisível por 3 e por 5.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a;

    do {
        printf("Manda um numero entre 20 e 100 que divida por 3 e por 5\n");
        scanf("%i",&a);
    } while (!((a >= 20) && (a <= 100)));

    if (((a % 3) == 0) && ((a % 5) == 0)) {
        printf("Seu numero eh:%i",a);
    } else 
        printf("Oxe esse numero nao eh divisivel por 3 ou por 5");

        return 0;
}
```

## #3

Faça um programa que lê 2 valores A e B (inteiros) e informa se A é divisível por B ou não.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a,b;
    printf("Informe o valor de a e b\n");
    scanf("%i %i",&a,&b);

    if ((a % b) == 0) {
        printf("SIM, Teu numero %i eh divisivel por %i",a,b);
    } else {
        printf("NOPE, Teu numero %i n eh divisivel por %i",a,b);
    }

    return 0;
}
```

## #4

Entrar com sexo (caractere ‘m’ para masculino e ‘f’ para feminino) e idade de uma pessoa. Se a pessoa for do sexo feminino e tiver menos de 25 anos, imprimir a mensagem: ACEITA. Caso contrário, imprimir a mensagem: NÃO ACEITA.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char sexo;
    int idade;

    printf("Digite seu sexo(caractere 'm' para masculino e 'f' para feminino) e sua idade\n");
    scanf("%c %i",&sexo,&idade);
    
    if ((sexo == 'f') && (idade < 25)) {
        printf("ACEITA");
    } else {
        printf("NAO ACEITA");
    }
    
    
    return 0;
}
```

## #5

Escreva um programa que peça 3 notas (reais) para o usuários. Imprima “voce passou”, caso a média das notas seja maior ou igual a 7; caso contrário, imprima “voce nao passou”.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float nota1, nota2, nota3, media;
    printf("digite a nota em ordem: nota1 nota2 nota3\n");
    scanf("%f %f %f",&nota1,&nota2,&nota3);

    media = (nota1 + nota2 + nota3)/3;

    if (media >= 7) {
        printf("voce passou com %.2f",media);
    } else {
        printf("voce nao passou e ficou com %.2f",media);
    }
    
    return 0;
}
```

## #6

Uma empresa deseja dar 20% de aumento para aqueles funcionários que possuem salário menor ou igual a R$1000,00 e um aumento de 10% para aqueles que possuem salários maiores que R$1000,00. Escreva um programa que pede para o usuário digitar o seu salário. Imprima seu novo salário na tela.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float salario, novo_salario;

    printf("Digite seu salario:\n");
    scanf("%f",&salario);

    if (salario <= 1000) {
        novo_salario = 1.2*salario; 
    } else {
        novo_salario = 1.1*salario;
    }

    printf("Seu novo salario eh: R$%.2f",novo_salario);

    return 0;
}
```

## #7

Escreva um programa que peça ao usuário 3 valores reais: r, c1 e c2. O primeiro representa o raio de uma circunferência, e os outros dois valores representam o centro. Peça para o usuário digitar mais dois valores reais: p1 e p2, que representam as coordenadas de um ponto. Imprima “Estah dentro”, se o ponto (p1,p2) está dentro da circunferência, caso contrário, imprima “Estah fora”.

## #8

Um hotel cobra R$50,00 reais a diária e mais uma taxa de serviços. Faça um programa que lê a quantidade de dias que o hóspede ficou no hotel e imprime o valor total a pagar. A taxa de serviços é de:

- 15,30 por dia, se número de diárias <15
- 10,00 por dia, se número de diárias =15
- 8,50 por dia, se número de diárias >15

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int dias;
    float totalpg;

    printf("Digite quantos dias o hospede ficou hospedado\n");
    scanf("%i",&dias);

    if (dias < 15) {
        totalpg = 50*dias + 15.30*dias;
    } else if (dias == 15) {
        totalpg = 50*dias + 10*dias;
    } else if (dias > 15) 
        totalpg = 50*dias + 8.50*dias;
    
    printf("O total a pagar eh: R$%.2f", totalpg);
    
    return 0;
}
```

## #9

Depois da liberação do governo para as mensalidades dos planos de saúde, as pessoas começaram a fazer pesquisas para descobrir um bom plano, não muito caro. Um vendedor de plano de saúde apresentou a tabela a seguir.

- Até 10 anos – R$30,00
- Acima de 10 até 29 anos – R$60,00
- Acima de 29 até 45 anos – R$120,00
- Acima de 45 até 59 anos – R$150,00
- Acima de 59 até 65 anos – R$250,00
- Maior que 65 anos – R$400,00

Criar um algoritmo que entre com a idade de uma pessoa e imprimir o valor que ela deverá pagar.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int idade;
    float totalpg;

    printf("Digite sua idade\n");
    scanf("%i",&idade);

    if (idade <= 10) {
        totalpg = 30;
    } else if (idade <= 29) {
        totalpg = 60;
    } else if (idade <= 45) {
        totalpg = 120;
    } else if (idade <= 59) {
        totalpg = 150;
    } else if (idade <= 65) {
        totalpg = 250;
    } else if (idade > 65) {
        totalpg = 400;
    }

    printf("Total a pagar: R$%.2f", totalpg);
    
    return 0;
}
```

## #10

A nota final de um estudante é calculada a partir da média de três notas atribuídas entre o intervalo de 0 até 10, respectivamente, a um trabalho de laboratório, a uma avaliação semestral e a um exame final. De acordo com o resultado, mostre na tela se o aluno está reprovado (média <= 4), de recuperação (4 <= media < 7) ou se foi aprovado (media >= 7). Se o aluno for para a recuperação, leia a sua nota na recuperação, e verifique se a média desta nota com a nota final é maior ou igual a 5. Se for, imprima que o mesmo está aprovado na recuperação, caso contrário imprima que o mesmo está reprovado.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float trabalho, avaliacao, final;
    float media;

    printf("Diga suas notas de trabalho de laboratorio, avaliacao semestral e exame final na ordem: NN NN NN\n");
    scanf("%f %f %f",&trabalho, &avaliacao, &final);

    media = (trabalho + avaliacao + final)/3;

    if (media >= 7) {
        printf("Parabe'ns voce foi aprovado");
    } else if (media >= 4){
        float recuperacao, media_recuperacao;
        printf("Voce foi para a recuperacao, diga sua nota na mesma\n");
        scanf("%f",&recuperacao);

        media_recuperacao = (final+recuperacao)/2;

        if (media_recuperacao >= 5)
            printf("Voce foi aprovado na recuperacao");
        else 
            printf("Voce nao conseguiu passar na recuperacao");
    } else 
        printf("Voce foi reprovado");
    
    return 0;
}
```

## #11

Faça um programa que mostre ao usuário um menu com 4 opções de operações matemáticas (+, -, /, *). O usuário escolhe uma das opções e o seu programa então pede dois valores reais, realiza a operação e imprime o resultado na tela.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char operacao;
    float a,b;
    printf("Digite sua expressao no formato: a + b, a - b, a * b ou a / b\n");
    scanf("%f %c %f",&a,&operacao,&b);

    switch (operacao) {
    case '+':
        printf("%.2f",a + b);
        break;
    case '-':
        printf("%.2f",a - b);
        break;
    case '*':
        printf("%.2f",a * b);
        break;
    case '/':
        printf("%.2f", a / b);
        break;
    default:
        printf("Operacao desconhecida");
        break;
    }
    return 0;
}
```

## #12

Peça três valores ao usuários, A, B, C, e verifique se eles podem ser valores dos lados de um triângulo. Para ser triângulo, (A+B) > C e (A+C) > B e (B+C) > A.
Se não puder ser triângulo, imprima na tela que “nao pode ser triangulo”; caso contrário, imprima na tela qual é o triângulo formado: escaleno (todos os lados diferentes), isósceles (2 lados iguais e 1 diferente) ou equilátero (3 lados iguais).

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a,b,c;

    printf("Diga os tres lados do triangulo no formato: X Y Z\n");
    scanf("%i %i %i",&a,&b,&c);

    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
        if ((a == b) && (b == c) && (a == c))
            printf("O triangulo e equilatero");
        else if ((a == b) || (b == c) || (a == c))
            printf("O triangulo eh isoceles");
        else
            printf("O triangulo eh escaleno");
    }
    else
        printf("nao eh triangulo");
    return 0;
}
```

## #13

Você está desenvolvendo um sistema de controle de acesso a cinema. Este sistema deve pedir a idade do usuário, e em seguida imprimir as opções de filmes:

- Titanic (16 anos)
- Pica Pau (Livre)
- A volta de Jason (18 anos)
- Desistir

Se o usuário escolher o filme e não tiver idade suficiente, o sistema deve imprimir "Voce nao tem idade para assistir ao filme". Caso o usuário tenha idade para o filme, o sistema imprime "Voce comprou o filme tal. Bom filme!".

```c
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
```

## #14

O cardápio de uma lanchonete é o seguinte:

|  Especificação  | Código | Preço |
|:---------------:|:------:|:-----:|
| Cachorro Quente |   100  |  1.20 |
|  Bauru Simples  |   101  |  1.30 |
|  Bauru com ovo  |   102  |  1.50 |
|    Hamburguer   |   103  |  1.20 |
|  Cheeseburguer  |   104  |  1.30 |
|   Refrigerante  |   105  |  1.00 |

Implemente um programa que leia o código do item pedido, a quantidade que deseja comprar e, calcule e imprima o valor a ser pago por aquele lanche.

```c
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
```

## #15

Desenvolva um sistema de compra de bebidas. Este sistema, inicialmente, deve pedir para que o usuário informe a sua idade. Se a idade for menor que 18 anos, deve-se imprimir a seguinte mensagem: "você eh de menor e nao pode comprar bebidas". Caso o usuário tenha idade suficiente, o sistema de apresentar o seguinte menu:

- Whisky
- Vodka
- Cerveja
- Cachaça

Se o usuário escolher outra opção, o sistema deve imprimir “opção inválida”.

Se o usuário escolher a opção 1 (whisky), o seguinte menu deve ser impresso:

| Código |   Nome   | Preço |
|:------:|:--------:|:-----:|
|   100  | Whisky 1 |  200  |
|   101  | Whisky 2 |  150  |
|   102  | Whisky 3 |  140  |

Se o usuário escolher a opção 2 (Vodka), o seguinte menu deve ser impresso:

| Código |   Nome  |Preço |
|:------:|:-------:|:----:|
|   200  | Vodka 1 |  60  |
|   201  | Vodka 2 |  40  |
|   202  | Vodka 3 |  30  |

Se o usuário escolher a opção 3 (Cerveja), o seguinte menu deve ser impresso:

| Código |    Nome   |  Preço |
|:------:|:---------:|:------:|
|   300  | Cerveja 1 |  1.50  |
|   301  | Cerveja 2 |   2.0  |
|   302  | Cerveja 3 |   3.0  |

Se o usuário escolher a opção 4 (Cachaça), o seguinte menu deve ser impresso:

| Código |    Nome   |  Preço  |
|:------:|:---------:|:-------:|
|   400  | Cachaça 1 |    8.0  |
|   401  | Cachaça 2 |   20.0  |
|   402  | Cachaça 3 |   22.0  |

Uma vez direcionado ao menu escolhido, o usuário pode escolher a bebida que deseja e a quantidade. Se a quantidade for menor que 1, o sistema deve imprimir “quantidade inválida”. Se a quantidade for válida, ou seja, maior ou igual a 1, caso o usuário compre mais de 5 bebidas, receber desconto de 10%. Se comprar mais de 50 bebidas, o desconto é de 30%. Acima de 100 bebidas o desconto é de 35%.

O sistema deve imprimir na tela a bebida comprada, a quantidade e o valor final a ser pago.

```c
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
```
