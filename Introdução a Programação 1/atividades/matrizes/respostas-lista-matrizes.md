# Matrizes

## 1

Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.

```c
#include <stdio.h>

#define TAM_MATRIZ_COLUNAS 4
#define TAM_MATRIZ_LINHAS 4

int main() {
    int numeros[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
    int qtd_num_maior_10 = 0;

    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            if (numeros[i][j] > 10)
                qtd_num_maior_10 = qtd_num_maior_10 + 1;
        }
    }

    printf("Sao %i numeros maiores que 10 na matriz",qtd_num_maior_10);
    
    return 0;
}
```

## 2

Preencha uma matriz 5 x 5 com valores aleatórios entre 0 e 100. Em seguida, leia um valor X. O programa deverá fazer uma busca por este valor na matriz e, ao final, escrever a localização (linha e coluna), caso a primeira instância desse valor seja encontrado. Caso não seja encontrado, imprimir a mensagem “nao encontrado”.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MATRIZ_COLUNAS 5
#define TAM_MATRIZ_LINHAS 5

int main() {
    int matriz[TAM_MATRIZ_COLUNAS][TAM_MATRIZ_LINHAS];
    int num_advinhar;

    srand(time(NULL));

    //Aleatoriza a matriz;
    for (int i = 0; i < TAM_MATRIZ_COLUNAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_LINHAS; j++) {
            matriz[i][j] = rand() % 101;
        }
    }

    printf("Diga o numero que voce quer procurar\n");
    scanf("%i",&num_advinhar);

    //Procura o número
    for (int i = 0; i < TAM_MATRIZ_COLUNAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_LINHAS; j++) {
            if (matriz[i][j] == num_advinhar) {
                printf("Numero encontrado na coluna %i e na linha %i",i,j);
                num_advinhar += 101;
            }
        }
    }
    
    //Se não encontrado o número, isto é executado:
    if (num_advinhar < 100)
        printf("Numero nao encontrado");

    return 0;
}
```

## 3

Preencha duas matrizes 4 x 4 de forma aleatória com valores entre 0 e 20, e escreva uma terceira com os maiores valores de cada posição das matrizes preenchidas.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MATRIZ_LINHAS 4
#define TAM_MATRIZ_COLUNAS 4

int main() {
    int matriz1[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int matriz2[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int matriz3[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];

    srand(time(NULL));

    //Aleatoriza as duas matrizes
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            matriz1[i][j] = rand() % 21;
            matriz2[i][j] = rand() % 21;
        }
    }
    
    //Compara os valores da matriz 1 e matriz 2, quanto aos seus maiores
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            if (matriz1[i][j] >= matriz2[i][j])
                matriz3[i][j] = matriz1[i][j];
            else if (matriz2[i][j] > matriz1[i][j])
                matriz3[i][j] = matriz2[i][j];
        }
    }

    //Print matriz3
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
            printf("%i ",matriz3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 4

Faça um programa para gerar automaticamente números entre 0 e 99 de uma cartela de bingo. Sabendo que a cartela deverá conter 5 linhas de 5 números, gere estes dados de modo a não ter números repetidos dentro da cartela. O programa deve exibir na tela a cartela gerada.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX_LINHAS 5
#define TAM_MAX_COLUNAS 5

int main() {
    int bingo[TAM_MAX_LINHAS][TAM_MAX_COLUNAS];

    srand(time(NULL));

    for (int i = 0; i < TAM_MAX_LINHAS; i++) {
        for (int j = 0; j < TAM_MAX_COLUNAS; j++) {
            int repeticao;

            do {
                repeticao = 0;
                bingo[i][j] = rand() % 100; //Gera os números
                for (int k = 0; k < TAM_MAX_LINHAS; k++) {
                    for (int l = 0; l < TAM_MAX_COLUNAS; l++) {
                        if ((bingo [i][j] == bingo[k][l]) && !((i == k) && (j == l))) //Verifica se foi repetido & se não é ele mesmo que se repete
                            repeticao = 1;
                    }   
                }
            } while (repeticao == 1); //Se repetido, realiza novamente a randomização do número de posição i,j
        }
    }

    //Visualiza a matriz do bingo
    for (int i = 0; i < TAM_MAX_LINHAS; i++) {
        for (int j = 0; j < TAM_MAX_COLUNAS; j++) {
            printf("%i ",bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

## 5

Leia uma matriz 5 x10 que se refere respostas de 10 questões de múltipla escolha, referentes a 5 alunos. Leia também um vetor de 10 posições contendo o gabarito de respostas que podem ser a, b, c ou d. Seu programa deverá comparar as respostas de cada candidato com o gabarito e emitir um vetor denominado resultado, contendo a pontuação correspondente a cada aluno. Imprima as notas o resultado de cada aluno.

OBS: Considere que cada questão vale 1 ponto.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_MAX_ALUNOS 5
#define QTD_MAX_PERGUNTAS 10

int main() {
    char resposta[QTD_MAX_ALUNOS][QTD_MAX_PERGUNTAS];
    char gabarito[QTD_MAX_PERGUNTAS] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b'};
    int resultado[QTD_MAX_ALUNOS];

    srand(time(NULL));

    //Zera os resultados
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        resultado[i] = 0;
    }


    //Aleatoriza a matriz de respostas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        for (int j = 0; j < QTD_MAX_PERGUNTAS; j++) {
            int aleatorio;
            aleatorio = rand() % 4;
            switch (aleatorio) {
            case 0:
                resposta[i][j] = 'a';
                break;
            case 1:
                resposta[i][j] = 'b';
                break;
            case 2:
                resposta[i][j] = 'c';
                break;
            case 3:
                resposta[i][j] = 'd';
                break;   
            default:
                break;
            }
        }
    }

    //Verifica as repostas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        for (int j = 0; j < QTD_MAX_PERGUNTAS; j++) {
            if (resposta[i][j] == gabarito[j]) 
                resultado[i] += 1;
        }
    }
    
    //Mostra o resultado
    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
        printf("O aluno %i tirou %i\n",i+1,resultado[i]);

    return 0;
}
```

## 6

Faça um programa que leia os nomes de 5 alunos. Além disso, leia uma matriz de 5 linhas e 4 colunas contendo as seguintes informações sobre cada aluno, sendo todas as informações do tipo inteiro:

- Primeira coluna: número de matrícula (use um inteiro)

- Segunda coluna: média das provas

- Terceira coluna: média dos trabalhos

- Quarta coluna: nota final

Elabore um programa que:

- Leia os nomes de cada aluno

- Leia as três primeiras informações de cada aluno

- Calcule a nota final como sendo a soma da média das provas e da média dos trabalhos

- Imprima o nome, a matrícula e a nota final do aluno que obteve a maior nota final (assuma que só existe uma maior nota)

- Imprima a média aritmética das notas finais

```c
#include <stdio.h>

#define TAM_MAX_NOME_ALUNOS 21

#define QTD_MAX_ALUNOS 5
#define QTD_MAX_INFO 4

int main() {
    char nome[QTD_MAX_ALUNOS][TAM_MAX_NOME_ALUNOS];
    float informacoes[QTD_MAX_ALUNOS][QTD_MAX_INFO], soma_notas = 0;
    int posicao_aluno_maior_nota;

    //Realiza a leitura de notas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        printf("Diga o nome do aluno %i\n", i+1);
        gets(nome[i]);
        
        printf("Diga o numero de matricula do aluno\n");
        scanf("%f",&informacoes[i][0]);
        getchar();
        
        printf("Diga sua media das provas\n");
        scanf("%f",&informacoes[i][1]);
        getchar();

        printf("Diga sua media dos trabalhos\n");
        scanf("%f",&informacoes[i][2]);
        getchar();

        informacoes[i][3] = informacoes[i][1]+informacoes[i][2];
    }

    //Separa a posição do aluno de maior nota
    for (int i = 1; i < QTD_MAX_ALUNOS; i++) {
        if (informacoes[i][3] > informacoes[i-1][3])
            posicao_aluno_maior_nota = i;
        else if (informacoes[i][3] < informacoes[i-1][3])
            posicao_aluno_maior_nota = i-1;
    }

    printf("O aluno %s de matricula %.0f, ",nome[posicao_aluno_maior_nota],informacoes[posicao_aluno_maior_nota][0]);
    printf("tirou a nota %.2f e ficou com a maior nota da sala\n",informacoes[posicao_aluno_maior_nota][3]);

    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
        soma_notas += informacoes[i][3];
    
    printf("A media das notas finais ficou em %.2f",(soma_notas/QTD_MAX_ALUNOS));
    
    return 0;
}
```

## 7

Faça um programa que leia duas matrizes 3 x 3 com valores reais. Ofereça ao usuário um menu de opções:

- Somar as duas matrizes

- Subtrair a primeira matriz da segunda

- Adicionar uma constante as duas matrizes

Nas duas primeiras opções uma terceira matriz 3 x 3 deve ser criada. Na terceira opção o valor da constante deve ser lido e cada valor da matriz deve ser somado ao valor lido.

```c
#include <stdio.h>

#define TAM_MATRIZ_LINHAS 3
#define TAM_MATRIZ_COLUNAS 3

int main() {
    float matriz1[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS], matriz2[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int opcao_usuario;

    printf("Voce ira preencher a matriz 1 da seguinte forma\n");
    printf("Ira digitar uma linha por vez e ira inserir as 3 colunas\n");
    printf("Ex:\n1 2 3\n4 5 6\n7 8 9\n");

    //Leitura de dados da matriz 1
    printf("Leitura da matriz 1\n");
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        printf("Digite a linha %i\n",i+1);
        scanf("%f %f %f",&matriz1[i][0],&matriz1[i][1],&matriz1[i][2]);
        getchar();
    }
    
    //Leitura de dados da matriz 2
    printf("Leitura da matriz 2\n");
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        printf("Digite a linha %i\n",i+1);
        scanf("%f %f %f",&matriz2[i][0],&matriz2[i][1],&matriz2[i][2]);
        getchar();
    }

    printf("Por favor me diga a operacao que deseja realizar\n");
    printf("1.Somar as duas matrizes\n");
    printf("2.Subtrair a primeira matriz da segunda\n");
    printf("3.Adicionar uma constante as duas matrizes\n");
    scanf("%i",&opcao_usuario);

    switch (opcao_usuario) {
        float matriz3[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
        float constante;

    case 1:
        
        printf("A matriz resultante sera:\n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                printf("%.2f ", matriz3[i][j]);
            }
            printf("\n");
        }
        
        break;

    case 2:
        
        printf("A matriz resultante sera:\n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
                printf("%.2f ", matriz3[i][j]);
            }
            printf("\n");
        }

        break;
    
    case 3:
        
        printf("A qual constante voce deseja adicionar nas duas matrizes?\n");
        scanf("%f",&constante);

        //Adição e print da matriz 1
        printf("A matriz 1 ficara da seguinte forma: \n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz1[i][j] += constante;
                printf("%.2f ", matriz1[i][j]);
            }
            printf("\n");
        }

        //Adição e print da matriz 2
        printf("\nA matriz 2 ficara da seguinte forma: \n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz2[i][j] += constante;
                printf("%.2f ", matriz2[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Opcao inva'lida");
        break;
    }

    return 0;
}
```

## 8

Em um tabuleiro 5x5, você precisa posicionar 5 inimigos, 2 heróis, 4 armas e 2 porções aleatoriamente. Ao final do programa, imprima a matriz com todas as peças posicionadas.

OBS: Os demais espaços devem estar livres.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_MAX_INIMIGOS 5
#define QTD_MAX_HEROIS 2
#define QTD_MAX_ARMAS 4
#define QTD_MAX_POCOES 2

#define TAM_MAX_TABULEIRO 5 //5x5

int main() {
    char tabuleiro[TAM_MAX_TABULEIRO][TAM_MAX_TABULEIRO];

    srand(time(NULL));

    //Seta todos os espaços como nulo, como se fosse o tabuleiro nu ( ͡° ͜ʖ ͡°)
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++) {
            tabuleiro[i][j] = NULL;
        }
    }

    //Posicionamento inimigos
    for (int a = 0; a < QTD_MAX_INIMIGOS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'I';
    }

    //Posicionamento armas
    for (int a = 0; a < QTD_MAX_ARMAS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'A';
    }

    //Posicionamento heróis
    for (int a = 0; a < QTD_MAX_HEROIS; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'H';
    }

    //Posicionamento porções
    for (int a = 0; a < QTD_MAX_POCOES; a++) {
        int i,j;
        do {
            i = rand() % 5;
            j = rand() % 5;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'P';
    }
    
    //Print do Tabuleiro
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++) {
            if (tabuleiro[i][j] == NULL) 
                printf("   |",tabuleiro[i][j]);
            else 
                printf(" %c |",tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## 9

Você está jogando xadrez com um amigo, cada um com 8 pedras. Porém, você possui apenas um único cavalo. Dada a localização do seu cavalo e a forma como o cavalo se movimenta (em L), verifique se você consegue derrubar uma pedra do seu adversário em uma jogada.

```c
/* Para essa questão é necessário observar que a movimentação do cavalo é sempre em L, logo será
 * sempre uma movimentação de 2 colunas e 1 linha OU 1 coluna e 2 linhas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX_TABULEIRO 8 //8x8

#define POSICAO_CAVALO_LINHA 4-1
#define POSICAO_CAVALO_COLUNA 4-1

#define QTD_MAX_PEDRAS 8

int main() {
    char tabuleiro[TAM_MAX_TABULEIRO][TAM_MAX_TABULEIRO];

    srand(time(NULL));

    //Seta todos os espaços como nulo, como se fosse o tabuleiro nu ( ͡° ͜ʖ ͡°)
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++){
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++)
            tabuleiro[i][j] = NULL;
    }

    //Posicionamento do cavalo
    tabuleiro[POSICAO_CAVALO_LINHA][POSICAO_CAVALO_COLUNA] = 'C';

    //Posicionamento randomizado das pedras
    for (int a = 0; a < QTD_MAX_PEDRAS; a++) {
        int i, j;
        do {
            i = rand() % 9;
            j = rand() % 9;

        } while (tabuleiro[i][j] != NULL);
        tabuleiro[i][j] = 'P';
    }

    //Condição para capturar pedra
    for (int i = -2; i <= +2; i++) {
        if (i != 0) {
            if ((i == -2) || (i == 2)) { //Para as linhas -2 e +2
                for (int j = -1; j <= +1; j+=2) { //Para as colunas -1 e +1
                    if (tabuleiro[POSICAO_CAVALO_LINHA-i][POSICAO_CAVALO_COLUNA-j] == 'P') {
                        printf("Pode haver captura na linha %i e coluna %i\n",(POSICAO_CAVALO_LINHA-i)+1,(POSICAO_CAVALO_COLUNA-j)+1);
                    }
                } 
            }

            if ((i == -1) || (i == 1)) { //Para as linhas -1 e +1
                for (int j = -2; j <= +2; j += 4) { //Para as colunas -2 e +2
                    if (tabuleiro[POSICAO_CAVALO_LINHA - i][POSICAO_CAVALO_COLUNA - j] == 'P') {
                        printf("Pode haver captura na linha %i e coluna %i\n", (POSICAO_CAVALO_LINHA - i) + 1, (POSICAO_CAVALO_COLUNA - j) + 1);
                    }
                }
            }
        }
    }
    

    //Print do Tabuleiro
    for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
        for (int j = 0; j < TAM_MAX_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == NULL)
                printf("   |", tabuleiro[i][j]);
            else
                printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
