# Vetores Unidimensionais

## 1

Faça um programa que preencha um vetor com 10 números reais, calcule e mostre a quantidade de números negativos e a soma dos números positivos desse vetor.

```c
#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    float reais[QTD_NUMEROS], soma_positivos = 0;
    int qtd_negativos = 0;
    printf("Ola' por favor preencha a seguinte lista de nu'meros reais que eu te dou algumas info's sobre eles\n");

    for (int i = 0; i < QTD_NUMEROS; i++) {
        printf("Digite o nu'mero real %i de %i\n",i,QTD_NUMEROS);
        scanf("%f",&reais[i]);
        getchar();

        if (reais[i] < 0) 
            qtd_negativos += 1;
        else if (reais[i] > 0) 
            soma_positivos += reais[i];
        
    }

    printf("Quantidade de nu'meros negativos: %i\n", qtd_negativos);
    printf("Soma nu'meros positivos: %.2f\n", soma_positivos);
    
    return 0;
}
```

## 2

Faça um programa que pede que o usuário digite um número inteiro positivo maior que zero e armazene na variável TAM. Enquanto o usuário digitar um número inválido, peça para que ele redigite. Um vez definido o valor de TAM, crie um vetor com TAM elementos. Inicialize o vetor com valores aleatórios entre 0-100. Uma vez preenchido, armazene em um segundo vetor cada valor do primeiro vetor só que elevado ao quadrado. Imprima o segundo vetor.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long ler_apenas_se_for_inteiro();

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    
    int tam;
    
    do {
        printf("Por favor digite um nu'mero inteiro positivo!\n");
        tam = ler_apenas_se_for_inteiro();
    } while (tam <= 0);

    int numeros[tam];
    int numeros_quadrado[tam];
    for (int i = 0; i < tam; i++) {
        numeros[i] = rand() % 100;
        numeros_quadrado[i] = numeros[i]*numeros[i];
        printf("%i\n",numeros_quadrado[i]);
    }
    
    return 0;
}

long ler_apenas_se_for_inteiro() { //Solução para aceitar apenas números inteiros e NEGAR caracteres não númericos
    char buffer_de_entrada[64];
    char *onde_a_funcao_de_conversao_parou;

    while (1) {
        fgets(buffer_de_entrada, 64, stdin);
        long numero_lido = strtol(buffer_de_entrada, &onde_a_funcao_de_conversao_parou, 0); //Dica: Veja a referência da função strtol();

        /* Se o número resultante é zero e o ponteiro que aponta para o caractere da string
         * no final da conversão não andou é porque não ocorreu conversão, ou seja, falhou. Além disso, o caractere onde a conversão parou
         * tem que ser uma quebra de linha, caso contrário há caracteres não numéricos
         * que foram ignorados pelo strtol, o que significa que a entrada 
         * não possui somente números.
         * Créditos: Pablo Almeida
         */
        if ((numero_lido == 0 && onde_a_funcao_de_conversao_parou == buffer_de_entrada) || *onde_a_funcao_de_conversao_parou != '\n') {
            printf("Nu'mero inva'lido. Digite novamente.\n");
            continue;
        } else {
            return numero_lido;
        }
    }
}
```

## 3

Escreva um programa que leia 10 números inteiros e os armazene em um vetor. Imprima o vetor, o maior elemento e a posição que ele se encontra.

```c
#include <stdio.h>

#define QTD_NUMEROS 10
int main(int argc, char const *argv[]) {
    int numeros[QTD_NUMEROS], posicao_maior_numero = 0;

    printf("Diga 10 numeros e eu te digo o maior");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i",&numeros[i]);
        if (numeros[i] >= numeros[posicao_maior_numero])
            posicao_maior_numero = i;
    }

    printf("O maior numero eh %i e sua posicao eh %i", numeros[posicao_maior_numero],posicao_maior_numero);
    
    return 0;
}
```

## 4

Leia 10 números inteiros e armazene em um vetor. Em seguida imprima os elementos que são primos e suas respectivas posições no vetor.

```c
#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    int numeros[QTD_NUMEROS], numeros_primos[QTD_NUMEROS];

    printf("Diga 10 numeros e eu te digo quais sao primos\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i",&numeros[i]);
        if ((numeros[i] % 1) == 0) {
            int primo;
            if ((numeros[i] % numeros[i]) == 0)
                primo = 1;

            for (int x = 2; x < numeros[i]; x++) {
                if ((numeros[i] % x) == 0)
                    primo = 0;
            }
            
            if (primo == 1)
                numeros_primos[i] = 1;
            else
                numeros_primos[i] = 0;
        }
    }

    for (int i = 0; i < QTD_NUMEROS; i++) {
        if (numeros_primos[i] == 1)
            printf("O numero %i de posicao %i eh primo\n", numeros[i], i);
        
    }
    
    return 0;
}
```

## 5

Faça um programa que receba do usuário valores inteiros para dois vetores, A e B, com 10 números inteiros cada. Crie um novo vetor denominado C calculando C = A - B. Mostre na tela os dados do vetor C.

```c
#include <stdio.h>

#define QTD_NUMEROS 10

int main(int argc, char const *argv[]) {
    int a[QTD_NUMEROS], b[QTD_NUMEROS], c[QTD_NUMEROS];

    printf("Diga o valor de A e B e eu te digo A - B\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i %i",&a[i],&b[i]);
        getchar();
        c[i] = a[i] - b[i];
    }
    
    for (int i = 0; i < QTD_NUMEROS; i++) {
        printf("C = %i - %i = ",a[i],b[i]);
        printf("%i\n", c[i]);
    }
    
    return 0;
}
```

## 6

Faça um programa que leia dois vetores de 10 posições e calcule outro vetor contendo, nas posições pares os valores do primeiro e nas posições ímpares os valores do segundo.

```c
#include <stdio.h>

#define QTD_NUMEROS 10

int main() {
    int a[QTD_NUMEROS],b[QTD_NUMEROS],c[QTD_NUMEROS*2];

    printf("Diga os valores de A e B na seguinte ordem: a b\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        scanf("%i %i",&a[i],&b[i]);
        getchar();
    }

    //ordenação índices pares
    for (int i = 0, j = 0; j < QTD_NUMEROS; i+=2, j++)
        c[i] = a[j];

    //ordenação índices ímpares
    for (int i = 1, j = 0; j < QTD_NUMEROS; i+=2, j++)
        c[i] = b[j];
    
    for (int i = 0; i < QTD_NUMEROS*2; i++) {
        printf("%i\n",c[i]);
    }
    
    return 0;
}
```

## 7

Escrever um programa que:

1. leia um conjunto de 10 notas, armazenando-as em vetor,
2. calcule e imprima a sua média,
3. calcule e imprima o número de alunos com nota superior à média

```c
#include <stdio.h>

#define QTD_NOTAS 10

int main() {
    float notas[QTD_NOTAS], soma_media = 0, media;
    int qtd_notas_acima_media = 0;
    printf("Por favor insira as 10 notas:\n");

    for (int i = 0; i < QTD_NOTAS; i++) {
        scanf("%f",&notas[i]);
        getchar();
        soma_media += notas[i];
    }

    media = soma_media/QTD_NOTAS;
    
    for (int i = 0; i < QTD_NOTAS; i++) {
        if (notas[i] > media)
            qtd_notas_acima_media += 1;
    }

    printf("Me'dia: %.2f\n",media);
    printf("Notas acima da me'dia %i\n",qtd_notas_acima_media);
    
    return 0;
}
```

## 8

Faça um programa que cria um vetor de 10 elementos inteiros. Inicialize cada posição do vetor com o valor -1. Posições com o valor -1, significam que estão disponíveis.

O programa deve pedir para que o usuário digite dois valores: o valor a ser adicionado no vetor e o índice (entre 0-9) em que o valor digitado será inserido no vetor. Se o índice digitado diz respeito à uma posição disponível do vetor (valor igual a -1), o valor é inserido. Caso contrário, deve-se imprimir uma mensagem informando que aquela posição já foi preenchida. O programa deve ser encerrado quando todas as posições estiverem preenchidas

```c
#include <stdio.h>

#define QTD_ELEMENTOS 10

int main() {
    int vetor[QTD_ELEMENTOS], existe_elemento_disponivel;

    //Disponibilizar todos os vetores
    for (int i = 0; i < QTD_ELEMENTOS; i++) {
        vetor[i] = -1;
    }
    
    existe_elemento_disponivel = 1;
    
    do {
        int posicao;
        printf("Em qual posicao voce deseja inserir um elemento (0 - 9)?\n");
        scanf("%i",&posicao);
        getchar();

        if ((posicao < 0) || (posicao > 9)) {
            printf("Posicao inva'lida\n");
        } else if (vetor[posicao] == -1) {
            printf("Por favor digite o valor ao qual voce deseja preencher\n");
            scanf("%i",&vetor[posicao]);
            getchar();
        } else {
            printf("Essa posicao nao esta mais disponi'vel\n");
        }
        
        existe_elemento_disponivel = 0;
        for (int i = 0; i < QTD_ELEMENTOS; i++) {
            if (vetor[i] == -1)
                existe_elemento_disponivel = 1;
            
        }    
        
    } while (existe_elemento_disponivel == 1);

    printf("Todos os vetores foram preenchidos");
    
    return 0;
}
```

## 9

Criar um algoritmo que leia dois vetores de números inteiros, tendo cada um 10 e 20 elementos respectivamente, e apresentar os elementos que não são comuns aos dois vetores.

```c
#include <stdio.h>

#define TAM_VETOR_A 10
#define TAM_VETOR_B 20

int main() {
    int a[TAM_VETOR_A] = {0,1,2,3,4,5,6,7,8,9};
    int b[TAM_VETOR_B] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int posicao_n_comuns_b[TAM_VETOR_B];
    
    for (int i = 0; i < TAM_VETOR_B; i++) {
        for (int j = 0; j < TAM_VETOR_A; j++) {
            if (a[j] != b[i])
                posicao_n_comuns_b[i] = i;
            else {
                posicao_n_comuns_b[i] = NULL;
                j = TAM_VETOR_A;
            }
        }
    }

    for (int i = 0; i < TAM_VETOR_B; i++) {
        if (posicao_n_comuns_b[i] != NULL) 
            printf("%i \n",b[posicao_n_comuns_b[i]]);
    }

    return 0;
}
```

## 10

Inicialize um vetor com 20 números inteiros aleatórios entre 0 e 10. Escreva os elementos do vetor eliminando os elementos repetidos.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_NUMEROS_ALEATORIOS 20
#define QTD_NUMEROS_INTERVALO 11

int main() {
    int aleatorios[QTD_NUMEROS_ALEATORIOS], unicos[QTD_NUMEROS_INTERVALO];

    srand(time(NULL));
    printf("Os nu'meros aleato'rios sao: \n");
    for (int i = 0; i < QTD_NUMEROS_ALEATORIOS; i++) {
        aleatorios[i] = rand() % 11;
        printf("%i ", aleatorios[i]);
    }

    //Seta o valor inválido para -1, para não pegar valores lixo
    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++)
        unicos[i] = -1;

    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++) {
        for (int j = 0; j < QTD_NUMEROS_ALEATORIOS; j++) {
            if (i == aleatorios[j]) {
                unicos[i] = i;
                j = QTD_NUMEROS_ALEATORIOS;
            }
        }
    }
    
    for (int i = 0; i < QTD_NUMEROS_INTERVALO; i++) {
        if (unicos[i] != -1)
            printf("\n%i", unicos[i]);
    }
    
    return 0;
}
```

## 11

Faça um programa que leia dois vetores de 10 elementos. Crie um vetor que seja a união entre os 2 vetores anteriores, ou seja, que contém os números dos dois vetores sem repetição.

```c
#include <stdio.h>

#define QTD_ELEMENTOS 10

int main() {
    int a[QTD_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9};
    int b[QTD_ELEMENTOS] = {5,6,7,8,9,10,11,12,13,14};
    int uniao[QTD_ELEMENTOS*2];
    int uniao_comum[QTD_ELEMENTOS*2];

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        uniao_comum[i] = NULL;
    }

    //Função Soma (uniao += a + b)
    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        if (i < 10) {
            uniao[i] = a[i];
        } else if (i < 20) {
            uniao[i] = b[i-10];
        }
    }

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        for (int j = 0; j < QTD_ELEMENTOS*2; j++) {
            if (uniao[i] == uniao[j]) {
                uniao_comum[i] = uniao[i];
                j = QTD_ELEMENTOS*2;
            }
        }        
    }

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        if (uniao_comum != NULL)
            printf("%i\n", uniao_comum[i]);        
    }  

    return 0;
}
```

## 12

Leia um vetor com 10 números reais, ordene os elementos deste vetor de forma crescente (menor para o maior), e no final imprima os elementos do vetor ordenado.

```c
#include <stdio.h>

#define QTD_REAIS 10
int main() {
    float reais[QTD_REAIS] = {1.2,5.4,6.8,2.8,9.7,8.8,-4.3,5.6,3.5,-10};

    for (int i = 0; i < QTD_REAIS; i++) {
        for (int j = 0; j < QTD_REAIS; j++) {
            if (reais[i] < reais[j]) { //Se usado '<' irá ordenar de forma crescente, Se usado '>' irá ordenar de forma decrescente
                float buffer;
                buffer = reais[i];
                reais[i] = reais[j];
                reais[j] = buffer;
            }
        }
    }

    for (int i = 0; i < QTD_REAIS; i++) {
        printf("%.2f \n", reais[i]);
    }
    
    return 0;
}
```

## 13

Um sistema de controle de estoque armazena o código (inteiro), a quantidade em estoque (inteiro) e o preço unitário (float) das mercadorias. Fazer um programa que exiba um menu com as seguintes opções:

MENU

1. Cadastrar mercadoria
2. Consultar mercadoria
3. Valor total em mercadorias
4. Sair

Inicialmente não há nenhuma mercadoria cadastrada. A primeira opção permitirá que o usuário cadastre uma nova mercadoria informando todos os dados citados anteriormente.

A segunda opção permitirá que o usuário consulte o cadastro, informando o código da mercadoria.

A terceira opção permitirá a consulta do valor total do estoque, levando em conta todas as mercadorias cadastradas.

A quarta opção permitirá o término do programa.

```c
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
```

## Desafio

Faça um programa em C que leia do usuário um vetor de inteiros com ne posições no intervalo [5,200]. Ler repetitivamente o valor de n até que um valor válido seja digitado pelo usuário. Após a leitura dos n valores digitados pelo usuários algumas estatísticas devem ser extraídas deste vetor:

1. Imprimir na tela a Média do vetor;
2. Imprimir na tela a Mediana do vetor;
3. Imprimir na tela a quantidade de números ímpares e pares do vetor.

OBS:

- Os números reais devem ser impressos na tela com precisão de duas casas decimais;
- Assumir que o vetor já é digitado ordenado pelo usuário;
- A média aritmética simples corresponde a , onde x corresponde a cada elemento do vetor com n posições;
- O cálculo da mediana de dados ordenados de amostras de tamanho n pode ser realizado da seguinte forma: se n for ímpar, a mediana será o elemento central. Se n for par, a mediana será o resultado da média simples entre os elementos n/2 e (n/2)+1.

```c
#include <stdio.h>

#define QTD_MAXIMA_POSICOES 1000

int main() {
    int vetor[QTD_MAXIMA_POSICOES], posicao = 0;

    printf("Ola' usua'rio, digite nu'meros indefinidamente\n");
    printf("No intervalo de 5 'a 200 e eu te darei me'dia, mediana, quantidade de pares e i'mpares\n");
    printf("Logo digite de 1 em 1 os valores\n");
    printf("Para finalizar digite o valor '-1' e eu irei te dar as estati'sticas\n");

    do {
        int numero_lido;
        printf("Diga seu %i nu'mero\n",posicao+1);
        scanf("%i",&numero_lido);
        getchar();

        if ((numero_lido >= 5) && (numero_lido <= 200)) {
            vetor[posicao] = numero_lido;
            posicao += 1;
            printf("Nu'mero registrado!\n");
        } else if (numero_lido == -1) {
            printf("Cadastro de nu'meros finalizado!\n");
            posicao -= 1; /*Pois, como não há um novo número, 
                           *não há necessidade de reservar uma nova posição*/
            break;
        } else {
            printf("Nu'mero inva'lido!\n");
        }
        
    } while (1);
    
    int tamanho = posicao + 1;

    for (int i = 0; i < tamanho; i++) { //Para ver os valores cadastrados
        printf("%i \n", vetor[i]);
    }

    int soma_numeros = 0;
    float media;
    
    for (int i = 0; i < tamanho; i++) { //Calculo Média
        soma_numeros += vetor[i];
    }
    media = (float)soma_numeros/(float)tamanho;
    printf("A Me'dia dos nu'meros e' %.2f\n",media);
    
    //Para calcular a mediana é necessário por os números em ordem crescente, logo:
    int vetor_ordem_crescente[tamanho];
    float mediana;

    for (int i = 0; i < tamanho; i++) //Faz a cópia dos valores em vetor e põe em vetor_ordem_crescente
        vetor_ordem_crescente[i] = vetor[i];
    
    //Ordena os valores de vetor_ordem_crescente
    for (int i = 0; i < tamanho; i++) { 
        for (int j = 0; j < tamanho; j++) {
            if (vetor_ordem_crescente[i] < vetor_ordem_crescente[j]) {
                int buffer;
                buffer = vetor_ordem_crescente[i];
                vetor_ordem_crescente[i] = vetor_ordem_crescente[j];
                vetor_ordem_crescente[j] = buffer;
            }   
        }
    }

    if ((tamanho % 2) == 0) { //Função que obtém o valor central da ordem crescente, que neste caso, se trata da mediana
        mediana = (float)(vetor_ordem_crescente[(tamanho/2)-1]+vetor_ordem_crescente[tamanho/2])/2;
    } else {
        mediana = (vetor_ordem_crescente[tamanho/2]);
    }
    printf("A mediana e' %.2f\n",mediana);
    
    //Cálculo da quantidade de ímpares e pares
    int qtd_pares = 0, qtd_impares = 0;
    for (int i = 0; i < tamanho; i++) {
        if ((vetor[i] % 2) == 0) {
            qtd_pares +=1;
        } else {
            qtd_impares +=1;
        }
    }

    printf("O nu'mero de i'mpares e' %i e pares e' %i\n",qtd_impares,qtd_pares);    

    return 0;
}
```
