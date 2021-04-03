# Strings

## 1

Receber um nome e imprimir as 4 primeiras letras do nome.

```c
#include <stdio.h>

int main() {
    char nome[20];

    printf("Diga seu nome e eu te dou as 4 primeiras letras dele\n");
    gets(nome);

    for (int i = 0; i < 4; i++){
        printf("%c",nome[i]);
    }
    
    return 0;
}
```

## 2

Ler nome, e idade, se idade maior ou igual a 18 anos, imprime o nome da pessoa e a frase “deve votar”, caso contrário imprimir “Não é obrigado a votar”.

```c
#include <stdio.h>

int main() {
    char nome[20];
    int idade;

    printf("Por favor me diga seu nome\n");
    gets(nome);

    printf("Ola' %s",nome);
    printf(" me diga sua idade e eu lhe digo se voce deve votar\n");
    scanf("%i",&idade);
    getchar();

    if (idade >= 18) {
        printf("%s voce deve votar!\n", nome);
    } else {
        printf("%s voce nao e' obrigado a votar\n", nome);
    }
    printf("Obrigado!");

    return 0;
}
```

## 3

Crie uma programa que lê uma string e um caractere, e retorne o número de vezes que esse caractere aparece na string.

```c
#include <stdio.h>

#define TAMANHO_STRING 51

int main() {
    char string[TAMANHO_STRING], c;
    int contador_repeticao = 0;
    
    printf("Manda tua string pra eu estudar ela\n");
    gets(string);
    printf("Agora me diz o caractere que tu quer saber quantas vezes se repete na String\n");
    scanf("%c",&c);

    for (int i = 0; i < TAMANHO_STRING; i++) {
        if (string[i] == c) {
            contador_repeticao += 1;
        }
    }
    
    printf("Esse caractere aparece %i vezes nessa String", contador_repeticao);

    return 0;
}
```

## 4

Crie um programa que recebe uma string e um caractere, e apague (substitua por ‘ ’ (espaço)) todas as ocorrências desse caractere na string.

```c
#include <stdio.h>

int main() {
    char string[51], c;

    printf("Diga a String\n");
    gets(string);
    printf("Agora me diga o caractere que voce pretende substituir o espaco\n");
    scanf("%c",&c);

    for (int i = 0; i < 51; i++) {
        if (string[i] == ' ') 
            string[i] = c;       
    }

    printf("Sua String e' %s",string);

    return 0;
}
```

## 5

Digite um nome, calcule e retorne quantas letras tem esse nome

```c
#include <stdio.h>

#define TAMANHO_NOME_MAXIMO 21

int main() {
    char nome[TAMANHO_NOME_MAXIMO];
    int qtd_letras = 0;

    for (int i = 0; i < TAMANHO_NOME_MAXIMO; i++)
        nome[i] = NULL;
    
    printf("Diga seu nome\n");
    gets(nome);

    for (int i = 0; i < TAMANHO_NOME_MAXIMO; i++) {
        if((nome[i] != NULL) && (nome[i] != ' '))
            qtd_letras += 1;
    }

    printf("O nome %s possui %i letras\n",nome,qtd_letras);
    
    return 0;
}
```

## 6

Receba uma palavra e imprima de trás-para-frente.

```c
#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA];

    for (int i = 0; i < TAM_MAX_PALAVRA; i++)
        palavra[i] = NULL;

    printf("Diga sua palavra\n");
    scanf("%s",palavra);
    getchar();

    printf("Sua palavra invertida e' ");
    for (int i = TAM_MAX_PALAVRA; i >= 0; i--) {
        if (palavra[i] != NULL)
            printf("%c",palavra[i]);
    }
    
    
    return 0;
}
```

## 7

Receber uma palavra, calcule quantas vogais (a, e, i, o, u) possui essa palavra. Entre com um caractere (vogal ou consoante) e substitua todas as vogais da palavra dada por esse caractere.

```c
#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA], c;
    int qtd_vogais = 0;

    for (int i = 0; i < TAM_MAX_PALAVRA; i++)
        palavra[i] = NULL;

    printf("Entre com sua palavra\n");
    scanf("%s",palavra);
    getchar();
    printf("Entre com o caractere que voce substituir\n");
    scanf("%c",&c);

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
        if ((palavra[i] == 'a') || (palavra[i] == 'e') || (palavra[i] == 'i') || (palavra[i] == 'o') || (palavra[i] == 'u')) {
            qtd_vogais += 1;
            palavra[i] = c;
        }
    }
    printf("A sua palavra tem %i vogais\n",qtd_vogais);
    printf("Se as vogais forem trocados por seu caractere, ficara' da seguinter forma %s",palavra);
    
    return 0;
}
```

## 8

Crie um programa que pede ao usuário o tamanho do texto que deseja digitar. Em seguida, o programa pede ao usuário que digite um texto. O programa deve transformar alguns dos caracteres em maiúsculos, outros em minúsculos e outros permanecem como estão. Para isso, você deve navegar por cada caracter do texto, e gerar um número aleatório 0 ou 1. Se o número gerado for 0, o caracter atual é convertido para minúsculo, se o número for 1, o caracter é convertido para maiúsculo. Imprima o texto resultante.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tam;
    srand(time(NULL));
    
    printf("Qual o tamanho do texto que voce pretende digitar?\n");
    scanf("%i",&tam);
    getchar();
    tam += 1; //para o ultimo digito
    char texto[tam];

    for (int i = 0; i < tam; i++)
        texto[i] = NULL;
    
    printf("Por favor digite seu texto abaixo\n");
    gets(texto);

    for (int i = 0; i < tam; i++) {
        int aleatorio = rand() % 2;

        if ((aleatorio == 0) && ((texto[i]) >= 65) && (texto[i] <= 90))
            texto[i] += 32; //Ver Tabela ASCII
        
        if ((aleatorio == 1) && ((texto[i]) >= 97) && (texto[i] <= 122))
            texto[i] -= 32; //Ver Tabela ASCII
    }
    
    printf("Seu texto enlouqueceu e ficou assim:\n");
    puts(texto);

    return 0;
}
```

## 9

Crie um programa que compara duas strings. Imprima ‘Eh igual’, se o valor das duas strings for igual. Caso contrário, imprima “Nao eh igual”.

```c
#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR 21

int main() {
    char str1[TAM_MAX_STR], str2[TAM_MAX_STR];

    printf("Diga a String 1\n");
    gets(str1);
    printf("Diga a String 2\n");
    gets(str2);

    if (strcmp(str1,str2) == 0) { //Ver strcmp()
        printf("As duas Strings sao iguais\n");
    } else {
        printf("As duas Strings sao diferentes\n");
    }
    
    return 0;
}
```

## 10

Fazer um programa que:

1. leia uma frase de 80 caracteres, incluindo brancos,
2. conte e imprima quantos brancos existem na frase,
3. conte e imprima quantas vezes a letra ‘a’ aparece,
4. substitua as vogais pelo caracter ‘X’.

```c
#include <stdio.h>

#define TAM_MAX_FRASE 81

int main() {
    char frase[TAM_MAX_FRASE];
    int qtd_brancos = 0, qtd_a = 0;

    printf("Por favor escreva uma frase com ate' 80 caracteres\n");
    gets(frase);

    for (int i = 0; i < TAM_MAX_FRASE; i++) {
        if (frase[i] == ' ')
            qtd_brancos += 1;

        if (frase[i] == 'a')
            qtd_a += 1;

        if ((frase[i] == 'a') || (frase[i] == 'e') || (frase[i] == 'i') || (frase[i] == 'o') || (frase[i] == 'u'))
            frase[i] = 'X';
    }
    
    printf("A sua frase ficou assim:\n");
    puts(frase);
    printf("Quantidade de espacos: %i\nQuantidade de letras 'a': %i",qtd_brancos,qtd_a);

    return 0;
}
```

## 11

Escreva um programa que leia a idade e o primeiro nome de várias pessoas. Seu programa deve terminar quando uma idade negativa for digitada. Ao terminar, seu programa deve escrever o nome e a idade da pessoa mais jovem e mais velha.

```c
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define QTD_MAX_PESSOAS 1000

#define TAM_MAX_NOME 21

int main() {
     char nome_maior_idade[TAM_MAX_NOME], nome_menor_idade[TAM_MAX_NOME];
     int maior_idade = 0, menor_idade = INT_MAX;
    
    while (1) {
        char nome[TAM_MAX_NOME];
        int idade;

        printf("Diga seu nome\n");
        scanf("%s",nome);
        getchar();
        printf("Agora diga sua idade\n");
        scanf("%i",&idade);
        getchar();

        if (idade < 0)   
            break;        

        if (idade < menor_idade) {
            menor_idade = idade;
            strcpy(nome_menor_idade,nome);
        }
        
        if (idade > maior_idade) {
            maior_idade = idade;
            strcpy(nome_maior_idade,nome);
        }
    } 

    printf("Pessoa de maior idade: %s\n",nome_maior_idade);
    printf("Pessoa de menor idade: %s\n",nome_menor_idade);
    
    return 0;
}
```

## 12

Escreva um programa que recebe uma string S e inteiros não-negativos I e J. Concatene a frase "Ola mundo" com o segmento S[I..J]. Imprima o texto concatenado.

```c
#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR 51

int main() {
    char str[TAM_MAX_STR];
    char str_hw[TAM_MAX_STR] = "Ola mundo";
    int i,j;
    
    printf("Diga sua String\n");
    gets(str);
    printf("Agora diga as posicoes que voce deseja concatenar: i j\n");
    scanf("%i %i",&i,&j);

    for (int a = 0; a <= (j-i); a++) 
        str[a] = str[a+i];
    
    strncat(str_hw,str,(j-i));

    printf("A String concatenada eh: %s",str_hw);
    
    return 0;
}
```

## 13

Escreva um programa que leia um número N de palavras e diga qual das palavras é a primeira e a última na ordem alfabética.

```c
#include <stdio.h>
#include <string.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char maior_palavra[TAM_MAX_PALAVRA] = "", menor_palavra[TAM_MAX_PALAVRA] = "";

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) //Maior palavra possível
        menor_palavra[i] = 'Z';
    

    while (1) {
        char palavra[TAM_MAX_PALAVRA];

        printf("Diga sua palavra\n");
        scanf("%s",palavra);
        getchar();

        if ((strcmp(palavra, maior_palavra)) > 0 )
            strcpy(maior_palavra,palavra);

        if ((strcmp(palavra, menor_palavra)) < 0 )
            strcpy(menor_palavra,palavra);

        printf("Maior palavra eh: %s\n",maior_palavra);
        printf("Menor palavra eh: %s\n",menor_palavra);
    }
    return 0;
}
```

## 14

O código de César é uma das mais simples e conhecidas técnicas de criptografia. É um tipo de substituição na qual cada letra do texto é substituída por outra, que se apresenta no alfabeto abaixo dela um número fixo de vezes. Por exemplo, com uma troca de três posições, ‘A’ seria substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente um programa que faça uso desse Código de César (3 posições), entre com uma string e retorne a string codificada. Exemplo: String: a ligeira raposa marrom saltou sobre o cachorro cansado, Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR (com caracteres maiúsculos)

OBS: Os caracteres 'x', 'y' e 'z', que são os três últimos devem ser substituídos por 'A', 'B' e 'C' respectivamente.

OBS2: O caracter ' ' (espaço deve ser mantido)

```c
#include <stdio.h>

#define TAM_MAX_STR 101

int main() {
    char str[TAM_MAX_STR];
    
    printf("Diga sua string\n");
    gets(str);

    for (int i = 0; i < TAM_MAX_STR; i++) { //Consultar tabela ASCII para compreender o algoritmo
        if ((str[i] >= 97) && (str[i] <= 119)) { //Condição para as letras de a à w
            str[i] -= 32; //Transforma quaisquer minúsculos em maiúsculos
            str[i] += 3; //Condição de codificação
        } else if ((str[i] >= 65) && (str[i] <= 87)) { //Condição para as letras de A à W
            str[i] += 3;
        } else if ((str[i] >= 120) && (str[i] <= 122)) { //Condição para as letras x, y e z
            str[i] -= 32; //Transforma quaisquer minúsculos em maiúsculos
            str[i] -= 23; //Condição de codificação especial das letras x, y e z
        } else if ((str[i] >= 88) && (str[i] <= 90)) { ////Condição para as letras X, Y e Z
            str[i] -= 23; //Condição de codificação especial das letras X, Y e Z
        }
    }

    printf("A sua string fica assim:\n %s",str);
    
    return 0;
}
```

## 15

Implemente um programa que leia duas strings, str1 e str2, e um valor inteiro positivo N. Concatene a str2 N vezes com str1.

```c
#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR1 1001
#define TAM_MAX_STR2 51

int main() {
    char str1[TAM_MAX_STR1], str2[TAM_MAX_STR2];
    int qtd_cat;

    printf("Por favor diga a String 1\n");
    gets(str1);
    printf("Por favor diga a String 2\n");
    gets(str2);

    printf("Agora me diga quantas vezes voce pretende concatenar a str2 com a str1?\n");
    scanf("%i",&qtd_cat);

    for (int i = 0; i < qtd_cat; i++) {
        strcat(str1,str2);
    }

    printf("A String 1 fica assim:\n%s",str1);
    
    return 0;
}
```

## 16

O jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta, tendo como dica o número de letras e o tema ligado à palavra. A cada letra errada, o usuário perde uma tentativa (o número é determinado pelo programador). O jogo termina ou com o acerto da palavra ou com o término do número de tentativas.

Para começar o jogo se imprime um underline correspondente ao lugar de cada letra.

Por exemplo, para a palavra "AMOR", se escreve:

```md
A M O R ------> _ _ _ _
```

O jogador que tenta adivinhar a palavra deve ir dizendo as letras que podem existir na palavra. Cada letra que ele acerta é escrita no espaço correspondente.

```md
A M O R→ A _ O R
```

Caso a letra não exista nessa palavra, imprime-se que a letra está incorreta, e reduz-se o número de tentativas.

```c
#include <stdio.h>

#define TAM_MAX_PALAVRA 21

int main() {
    char palavra[TAM_MAX_PALAVRA], rascunho_palavra[TAM_MAX_PALAVRA];
    int tentativas_erradas = 0;

    printf("Ola, diga a palavra (use letras maiusculas) que voce deseja advinhar\n");
    scanf("%s",palavra);
    getchar();

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
        if ((palavra[i] >= 65) && (palavra[i] <= 90)) {
            rascunho_palavra[i] = '_';
        }
    }

    for (int i = 0; i < TAM_MAX_PALAVRA; i++) 
        printf("%c ",rascunho_palavra[i]);
    

    printf("Voce tem 3 chances de acertar as letras\n");
    while (tentativas_erradas < 3) {
        char letra;
        int erro = 1;
        printf("Diga uma letra\n");
        scanf("%c",&letra);
        getchar();

        for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
            if (palavra[i] == letra) { //Testa cada letra individualmente
                rascunho_palavra[i] = letra;
                erro = 0;
            }
        }
        
        if (erro == 1)  //Verifica que foi errado e enumera tentativa errada
            tentativas_erradas += 1;

        erro = NULL;
        for (int i = 0; i < TAM_MAX_PALAVRA; i++) {
            printf("%c ", rascunho_palavra[i]); //print do rascunho da palavra
            if (rascunho_palavra[i] == '_') {
                erro = 1;
            }    
        }
        
        if (erro == NULL) {
            tentativas_erradas = NULL;
            break;
        }
        
        printf("Voce tem %i chances de 3 chances\n",3-tentativas_erradas);
    }
    
    if (tentativas_erradas == NULL) {
        printf("Parabens, voce ganhou a palavra era %s",palavra);
    } else {
        printf("Infelizmente voce perdeu o jogo, a palavra era %s",palavra);
    }

    return 0;
}
```
