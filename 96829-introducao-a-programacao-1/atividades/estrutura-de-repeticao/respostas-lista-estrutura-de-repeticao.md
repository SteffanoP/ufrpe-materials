# Lista de Estruturas de Repetição

## 1

Faça um programa que leia 10 números inteiros (positivos ou negativos). Imprima a média dos valores, ignorando os não positivos.

```c
/* Faça um programa que leia 10 números inteiros (positivos ou negativos). Imprima a média dos valores, ignorando os não positivos.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int num[10];
    float soma, qtd_medias = 0, media;

    printf("Digite os numeros\n");

    for (int i = 1; i <= 10; i++) {
        printf("Diga o numero %i\n", i);
        scanf("%i",&num[i]);
        getchar();
    }
    
    for (int i = 1; i <= 10; i++) {
        if (num[i] >= 0) {
            soma += num[i];
            qtd_medias += 1;
        }
    }

    media = soma/qtd_medias;

    printf("A media eh %.2f",media);

    return 0;
}
```

## 2

Escreva um programa que leia um número inteiro e calcule a soma de todos os divisores desse número, com exceção dele próprio. Ex: a soma dos divisores do número 66 é 1 + 2 + 3 + 6 + 11 + 22 + 33 = 78.

```c
/* Escreva um programa que leia um número inteiro e calcule a soma de todos os divisores desse número, com exceção dele próprio.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int num, soma;

    printf("Mano diz o numero ae\n");
    scanf("%i", &num);
    getchar();

    for (int i = 1; i < num; i++) {
        if ((num % i) == 0)
            soma += i;
    }

    printf("Tua soma eh %i\n",soma);
    
    return 0;
}
```

## 3

A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o salário e número de filhos. A prefeitura deseja saber:

1. média do salário da população;
2. média do número de filhos;
3. maior e menor salário;
4. percentual de habitantes com mais de 2 filhos.

A quantidade de habitantes que serão cadastrados é fornecida pelo usuário.

```c
#include <stdio.h>
#include <limits.h> // Para variável INT_MAX usada para calcular o menor salário possível

int main(int argc, char const *argv[]) {
    int qtd_habitantes;
    float soma_salario, soma_filhos, maior_salario = 0, menor_salario = INT_MAX, percentual_2filhos;

    printf("Bem vindo a pesquisa de Dezembro/2020\n");
    printf("Diga o numero de habitantes que voce deseja cadastrar nessa pesquisa\n");
    scanf("%i",&qtd_habitantes);
    getchar();


    for (int i = 0; i < qtd_habitantes; i++) {
        int filhos;
        float salario;

        printf("Passe os dados do habitante n %i de %i\n",i+1,qtd_habitantes);
        printf("Primeiro a renda familiar\n");
        scanf("%f",&salario);
        printf("E agora quantidade de filhos\n");
        scanf("%i",&filhos);

        soma_salario += salario;
        soma_filhos += filhos;

        if (salario > maior_salario)
            maior_salario = salario;

        if (salario < menor_salario)
            menor_salario = salario;
        
        if (filhos > 2) 
            percentual_2filhos += 1;
        
    }
    
    percentual_2filhos = percentual_2filhos/((float)qtd_habitantes);

    printf("Em lista o que a prefeitura quer saber eh:\n");
    printf("1. A media salarial da populacao: %.2f\n",(soma_salario/qtd_habitantes));
    printf("2. A media do numero de filhos: %2.f\n",(soma_filhos/qtd_habitantes));
    printf("3. O maior salario: %.2f e o menor salario: %.2f\n", maior_salario, menor_salario);
    printf("4. Percentual de habitantes com mais de 2 filhos: %.2f%%",(percentual_2filhos*100));

    return 0;
}
```

## 4

No dia da estreia do filme “Senhor dos Anéis”, uma grande emissora de TV realizou uma pesquisa logo após o encerramento do filme. Cada espectador respondeu a um questionário no qual constava sua idade e sua opinião em relação ao filme:

1. Excelente;
2. Bom;
3. Regular.

Crie um algoritmo que receba a idade e a opinião de 10 espectadores, calcule e imprima:

- A média das idades das pessoas que responderam excelente;
- a quantidade de pessoas que responderam regular;
- a percentagem de pessoas que responderam bom entre todos os expectadores analisados.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 0;
    int soma_idade_excelente, qtd_pessoas_regular,qtd_pessoas_bom, qtd_pessoas_excelente;
    float media_idade_excelente, porcentagem_pessoas_bom;
    
    while (i < 10) {
        int idade, avaliacao;

        printf("Ola caro espectador, responda o seguinte questionario sobre o filme 'O Senhor dos Aneis' para ganhar um presente\n");
        printf("Primeiro, Qual a sua idade?\n");
        scanf("%i",&idade);
        printf("E agora me diga uma coisa: Qual a sua avaliacao para esse filme\n");
        printf("1. Excelente\n");
        printf("2. Bom\n");
        printf("3. Regular\n");
        scanf("%i",&avaliacao);
        
        
        switch (avaliacao) {
        case 1:
            soma_idade_excelente += idade;
            qtd_pessoas_excelente += 1;
            break;
        case 2:
            qtd_pessoas_bom += 1;        
            break;
        case 3:
            qtd_pessoas_regular += 1;
            break;
        
        default:
            break;
        }
        
        i += 1;
    }
    
    media_idade_excelente = (float)soma_idade_excelente/(float)qtd_pessoas_excelente;

    porcentagem_pessoas_bom = (float)qtd_pessoas_bom/10;

    printf("Relatorio do questionario\n");
    printf("A media das pessoas que responderam excelente: %2.f\n", media_idade_excelente);
    printf("A quantidade de pessoas que responderam regular: %i\n", qtd_pessoas_regular);
    printf("A porcentagem das pessoas que responderam bom: %2.f\n",(porcentagem_pessoas_bom*100));

    
    return 0;
}
```

## 5

Dado um número inteiro positivo, verificar se o número é primo ou não. OBS: Número primo é aquele que possui apenas dois divisores, o número 1 e o próprio número.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i;
    int primo;

    printf("Manda um inteiro ai e vamo ver se ele eh primo ou nao\n");
    scanf("%i",&i);

    if ((i % 1) == 0) {
        if ((i % i) == 0)
            primo = 1;
        
        int x;
        for (x = 2; x < i; x++) {
            if ((i % x) == 0)
                primo = 0;
        }
    }

    if (primo == 1)
        printf("O numero eh primo");
    else
        printf("Nem eh primo");
    return 0;
}
```

## 6

Faça um programa que leia de forma indefinida vários números, calcule e mostre:

1. A soma dos números digitados
2. A quantidade de números digitados
3. A média de números digitados
4. O maior número digitado
5. O menor número digitado
6. A média dos números pares

Finalize a entrada de dados caso o usuário informe o valor 0.

```c
#include <stdio.h>
#include <float.h>

int main(int argc, char const *argv[]) {
    int contador_numero = 0, qtd_numeros;
    float i;
    float numero[100];
    float soma_numeros, media_numeros, maior_numero = 0, menor_numero = FLT_MAX, media_pares, soma_pares, qtd_pares;

    do  {
        printf("Manda teus numeros\n");
        scanf("%f",&i);
        getchar();
        
        if (i == 0)
            break;

        numero[contador_numero] = i;

        soma_numeros += numero[contador_numero];
        qtd_numeros = contador_numero + 1;

        if (numero[contador_numero] > maior_numero)
            maior_numero = numero[contador_numero];
        
        if (numero[contador_numero] < menor_numero)
            menor_numero = numero[contador_numero];

        if (((int)numero[contador_numero] % 2) == 0) {
            soma_pares += numero[contador_numero];
            qtd_pares += 1;
        }

        contador_numero += 1;
    } while (i > 0);

    media_numeros = soma_numeros/(float)qtd_numeros;
    media_pares = soma_pares/qtd_pares;

    printf("1. A soma dos numeros digitados: %.2f\n",soma_numeros);
    printf("2. A quantidade de numeros digitados: %i\n",qtd_numeros);
    printf("3. A media de numeros digitados: %.2f\n",media_numeros);
    printf("4. O maior numero digitado: %.2f\n",maior_numero);
    printf("5. O menor numero digitado: %.2f\n",menor_numero);
    printf("6. A media de numeros pares digitados: %.2f\n",media_pares);
    

    return 0;
}
```

## 7

Escreva um programa que pergunta um número ao usuário, e mostra sua tabuada completa (de 1 até 10).

Ex: Se o número lido foi 4, imprimir:
4x1 = 4
4x2 = 8
4x3 = 12
…
4x10 = 10

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero;
    
    printf("Diga o numero que eu te mando a tabuada\n");
    scanf("%i",&numero);

    for (int i = 1; i <= 10; i++) 
        printf("A tabuada de %ix%i=%i\n",numero,i,numero*i);
    
    return 0;
}
```

## 8

Desenvolva um sistema de verificação do usuário. Para isso, crie uma variável inteira chamada de senha e atribua a ela um número inteiro de 4 dígitos.
O programa deve pedir ao usuário uma senha, e verificar se a senha condiz com o valor armazenado na variável senha. Se a senha digitada não estiver correta, imprima “Senha Incorreta” e solicite novamente a senha. Se a senha digitada for a correta, deverá ser apresentada a mensagem “Senha Correta”. Vale salientar que o usuário só possui 3 tentativas para acertar a senha. Caso não acerte, deve ser impresso “acesso bloqueado”.

```c
#include <stdio.h>

#define SENHA 1234

int main(int argc, char const *argv[]) {
    int tentativa_senha;
    

    for (int i = 0; i < 3; i++) {
        printf("Digite sua senha: ");
        scanf("%i",&tentativa_senha);
        getchar();

        if (tentativa_senha == SENHA)  {
            printf("Senha Correta!\n");
            i = 3;
        } else if (i < 2){
            printf("Senha invalida, tente novamente\n");
        }  else {
            printf("Acesso Bloqueado\n");
            while (1);
        }
    }
    
    return 0;
}
```

## 9

Criar um programa que apresenta o seguinte menu:

1. Imprimir “Olá!”;
2. Imprimir "Bem vindo";
3. Sair do algoritmo.

Se o usuário digitar a opção 1 ou 2, a respectiva mensagem é impressa. Em seguida, o menu é impresso novamente para que o usuário faça uma nova escolha. O programa só é encerrado quando o usuário digitar 3 para sair.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int opcao;
    do {
        printf("O menu:\n");
        printf("1. Imprimir 'Ola'\n");
        printf("2. Imprimir 'Bem vindo'\n");
        scanf("%i", &opcao);
        switch (opcao) {
        case 1:
            printf("Ola'\n");
            break;
        
        case 2:
            printf("Bem vindo\n");
            break;
        
        default:
            break;
        }
        
    } while (opcao != 3);
    
    return 0;
}
```

## 10

A sequência de Fibonacci é uma sequência infinita composta por números que obedecem o seguinte padrão: 0 1 1 2 3 5 8 13…
Como pode se ver, os dois primeiros números (0 1) quando somados dão origem ao terceiro (1). De modo que o n-ésimo número é fruto da soma dos dois anteriores.
Crie um programa que pede ao usuário um número X, e imprima o X-ésimo valor da sequência.
Ex: Se o usuário digitar 6, o valor a ser impresso é 8, que é o sexto valor da sequência.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int ordem_fibonacci, numero_anterior = -1, numero_atual = 1, numero_fibonacci;

    printf("Eu te digo o numero da sequencia de fibonacci e tu me diz a ordem dele\n");
    scanf("%i", &ordem_fibonacci);


    for (int i = 0; i < ordem_fibonacci; i++) {
        numero_fibonacci = numero_anterior + numero_atual;
        numero_anterior = numero_atual;
        numero_atual = numero_fibonacci;
    }

    printf("O numero de sequencia %i na ordem em fibonacci eh %i",ordem_fibonacci,numero_fibonacci);
    
    return 0;
}
```

## 11

Faça um programa que simule a urna eletrônica. A tela a ser apresentada deverá ser da seguinte forma:
As opções são:

1. Candidato Jair Rodrigues
2. Candidato Carlos Luz
3. Candidato Neves Rocha
4. Nulo
5. Branco

Entre com o seu voto:
O programa deverá ler os votos dos eleitores e, quando o número 6 for lido, apresentar as seguintes informações: a) O número de votos de cada candidato; b) A porcentagem de votos nulos; c) A porcentagem de votos brancos; d) O candidato vencedor.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int votos[5], total_votos, candidato_ganhador;

    for (int i = 0; i <= 5; i++) {
        votos[i] = 0;
    }
    
    
    unsigned int opcao;
    do {
        printf("Vote nos seguintes candidatos:\n");
        printf("1. Candidato Jair Rodrigues\n");
        printf("2. Candidato Carlos Luz\n");
        printf("3. Candidato Neves Rocha\n");
        printf("4. Nulo\n");
        printf("5. Branco\n");
        scanf("%i", &opcao);
        getchar();

        if (opcao <= 5) 
            votos[opcao] += 1;
        else 
            printf("Opcao invalida");

    } while (opcao != 6);

    printf("A) Total de votos:\n");
    printf("Candidato Jair Rodrigues: %i votos\n", votos[1]);
    printf("Candidato Carlos Luz: %i votos\n", votos[2]);
    printf("Candidato Neves Rocha: %i votos\n", votos[3]);

    for (int i = 1; i <= 5; i++)
        total_votos += votos[i];

    printf("B) Votos Nulos: %.2f votos\n%%",((float)votos[4]/(float)total_votos)*100);
    printf("C) Votos Brancos: %.2f votos\n%%",((float)votos[5]/(float)total_votos)*100);

    for (int i = 2; i <= 3; i++) {
        if (votos[i - 1] > votos[i])
            candidato_ganhador = i - 1;
        else if (votos[i - 1] < votos[i])
            candidato_ganhador = i;
    }

    printf("D) O candidato vencedor eh: O Candidato %i\n",candidato_ganhador);

    return 0;
}
```

## 12

Crie um jogo de adivinhação que deve ser jogado entre dois usuários. O primeiro usuário deve digitar três caracteres distintos.O segundo usuário deve digitar uma tecla na tentativa de acertar um dos três caracteres. Caso a tecla digitada esteja correta, imprima uma mensagem informando que ele acertou e quantos caracteres restam para ele acertar. Caso ele erre, imprima na tela e informe quantos caracteres restam e o número de tentativas restantes (o usuário só pode digitar no máximo 15 caracteres). O jogo termina quando o usuário acerta todos os caracteres ou quando não possui mais tentativas.

```c
#include <stdio.h>

int main() {
    char c1,c2,c3;
    int contador_acertos;
    
    do {
        printf("Jogador 1, por favor, digite seus caracteres na seguinte ordem: A B C\n");
        scanf("%c %c %c",&c1,&c2,&c3);
        getchar();
        if ((c1 == c2) || (c1 == c3) || (c2 == c3)) {
            printf("Jogador 1, eh necessario que os caracteres sejam distintos\n");
        }
    } while ((c1 == c2) || (c1 == c3) || (c2 == c3));

    for (int i = 0; i < 15; i++) {
        char c;

        printf("Jogador 2, tente advinhar algum caractere\n");
        scanf("%c",&c);
        getchar();

        if (c == c1) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c1,3-contador_acertos,14-i);
            c1 = NULL;


        } else if (c == c2) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c2,3-contador_acertos,14-i);
            c2 = NULL;

        } else if (c == c3) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c3,3-contador_acertos,14-i);
            c3 = NULL;
            
        } else {
            printf("Voce nao acertou nenhum caractere e ainda tem %i chances\n",14-i);
        }

        if (contador_acertos == 3)
            i = 15;
    }

    if (contador_acertos == 3) {
        printf("Parabe'ns voce ganhou o jogo\n");
    } else {
        printf("Infelizmente voce nao ganhou o jogo\n");
    }
    
    printf("fim");

    return 0;
}
```

## 13

Usando apenas os comandos printf("0"), printf("*") e printf("\n") e usando laços aninhados, faça o seguinte aparecer na tela.

- xxxxx
- 0xxxx
- 00xxx
- 000xx
- 0000x
- 00000

```c
#include <stdio.h>

int main() {
    
    for (int i = 0; i < 6; i++) {
        int qtd_x, qtd_0;

        qtd_x = 5 - i;
        qtd_0 = i;

        for (int o = 0; o < qtd_0; o++) {
            printf("0");
        }

        for (int x = 0; x < qtd_x; x++) {
            printf("x");
        }  

        printf("\n");
    }

    return 0;
}

```

## 14

Dados um número inteiro N, N>0, e uma sequência com N números inteiros maiores do que zero, determinar o fatorial de cada número da sequência.

```c
/* Considere para essa questão o seguinte: dado um número n, destrinche suas fatoriais, ex: para n = 4, faça:
4! = 4. 3 . 2 . 1 = 24
3! = 3 . 2 . 1 = 6
2! = 2 . 1 = 2 
*/
#include <stdio.h>

int main() {
    int n;
    
    printf("Bem vindo a funcao vetorial!\n");
    printf("Aparentemente os matematicos estavam com preguica de calcular as fatoriais dos numeros\n");
    printf("Ou simplesmente de usarem a calculadora cientifica mesmo...\n");
    printf("Por favor diga o numero que voce deseja descobrir a fatorial\n");
    scanf("%i",&n);

    for (int a = n; a > 0; a--) {
        int fatorial = 1;
        printf("%i! = ", a);
        for (int i = a; i > 0; i--) {
            if (i != 1)
                printf("%i . ",i);
            else
                printf("%i",i);
            fatorial *= i;
        }
    
        printf(" = %i \n", fatorial);
    }
    return 0;
}
```

## 15

Crie um programa que desenhe a diagonal principal e a diagonal secundária do quadrado (o tamanho do quadrado deve ser fornecido pelo usuário), como a seguir:

Exemplo do quadrado com tamanho 5 (5 linhas e 5 colunas).

```md
X   X
 X X
  X
 X X
X   X
```

```c
#include <stdio.h>

int main() {
    int tamanho;

    printf("Diga o tamanho do Quadrado, de preferencia um numero impar\n");
    scanf("%i",&tamanho);
    if ((tamanho % 2) == 0) {
        /* Tamanho par*/   
        printf("Para tamanhos pares fica dificil de visualizar ;-;\n");
        printf("mas...\n");
    } 
        /*Tamanho ímpar*/
        int espaco, linhas;
        linhas = tamanho / 2;
        espaco = tamanho - 2;

        //Linhas superiores
        for (int i = 0; i < linhas; i++)
        {
            for (int a = 0; a < i; a++)
                printf(" ");
            
            printf("X");

            for (int b = 0; b < espaco; b++)
                printf(" ");
            espaco -= 2;

            printf("X");

            for (int a = 0; a < i; a++)
                printf(" ");

            printf("\n");
        }

        //Linha Central
        for (int i = 0; i < linhas; i++)
            printf(" ");

        printf("X");

        for (int i = 0; i < linhas; i++)
            printf(" ");

        printf("\n");
        espaco += 2;

        //Linhas inferiores
        for (int i = 0; i < linhas; i++) {
            for (int a = (linhas - 1); a > i; a--)
                printf(" ");

            printf("X");

            for (int b = 0; b < espaco; b++)
                printf(" ");
            espaco += 2;

            printf("X");

            for (int a = (linhas - 1); a > i; a--)
                printf(" ");

            printf("\n");
        }
    
    return 0;
}
```

## 16

Crie um algoritmo que simule o funcionamento de um caixa de supermercado. O caixa fica aberto até o fim do expediente e pode processar a compra de vários clientes.  Cada cliente pode comprar vários itens (1.Feijão - R$ 2.0, 2.Arroz - R$ 1.5, 3.Carne - R$ 10.0, 4. Tomate - R$ 3.0, 5. Cebola - R$ 2.5). Ao ler cada item deve ser exibida uma mensagem para o operador do caixa perguntando se há mais itens a serem processados. Ao final, exiba quanto a compra custou ao cliente. E então solicite do operador do caixa a informação se deseja fechar o caixa.  Quando o caixa for fechado, imprima quanto de dinheiro aquele caixa apurou no dia.

```c
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
```
