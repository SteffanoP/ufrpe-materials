#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"
#include "random.c"

#define TAM_INI 100
#define TAM_MAX 5000
#define INC 100

// simpio.h e random.h vêm da biblioteca de
// Eric Roberts, acessível por exemplo em
// https://www.ime.usp.br/~pf/Roberts/C-library/standard/

typedef int *veti; // Apelida de "veti" ("vetor de inteiros") o tipo "int *".

veti criaveti(int);
veti insertionSort(int n, int *);
int buscaLinear(int, int, int *);
int buscaBinaria(int, int, int *);

int NOP, NOP_SORT, NOP_BUSCA_LINEAR, NOP_BUSCA_BINARIA;

int main()
{

    int n, k, x = 42, r = 0;
    veti v;

    Randomize();

    FILE *saida;
    saida = fopen("dados.dat", "w");
    fprintf(saida, "n\t\tNOP_BLINEAR\tNOP_SORT\tNOP_BBINÁRIA\tNOP\n");

    for (n = TAM_INI; n <= TAM_MAX; n += INC)
    {
        v = criaveti(n);
        for (k = 0; k < n; k++)
            v[k] = RandomInteger(0, 100);

        x = RandomInteger(0, 100);
        r = buscaLinear(x, n, v);
        NOP = 0;
        v = insertionSort(n, v);
        r = buscaBinaria(x, n, v);

        fprintf(saida, "%04.d\t%d\t\t\t%d\t\t%d\t\t\t\t%d\n", n, NOP_BUSCA_LINEAR, NOP_SORT, NOP_BUSCA_BINARIA, NOP);

        free(v);
    }

    fclose(saida);

    return 0;
}

/**
 * A função de ordenamento insertionSort visa ordenar um vetor de 
 * inteiros por meio do método de inserção. Esse método é
 * caracterizado em dois conjuntos de valores, um conjunto de
 * valores organizado e outro desorganizado; inicialmente todos
 * os números estão desorganizados e a cada iteração um valor é
 * inserido na posição mais adequada para a ordenação no conjunto
 * de valores ordenados.
 * 
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return o vetor de inteiros ordenado de forma ascendente.
 **/
veti insertionSort(int n, int v[]) 
{
    NOP_SORT = 0;
    for (int i = 1; i < n; i++)
    {
        int x = v[i]; //2
        int j = i - 1; //3

        while ((j >= 0) && (x < v[j]))
        {
            NOP++;
            NOP_SORT++;
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
    return v;
}

/**
 * A função de busca linear visa buscar um valor especificado dentro de 
 * um vetor de inteiros. A função realiza uma iteração por meio de um 
 * método while do qual irá iterar até encontrar o valor correspondente 
 * a busca.
 * 
 * @param x se refere ao número que a função de busca irá buscar.
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return a posição do número x no vetor de inteiros (v[]).
 **/
int buscaLinear(int x, int n, int v[])
{
    int k;
    k = n - 1;
    NOP_BUSCA_LINEAR = 0;
    while (k >= 0 && v[k] != x)
    {
        k -= 1;
        NOP_BUSCA_LINEAR++;
    }
    return k;
}

/**
 * A função de busca binária visa buscar um valor especificado dentro de
 * um vetor de inteiros ordenado, nesse caso de forma ascendente. A 
 * função realiza diversas iterações até encontrar o número especificado,
 * o fator chave dessa busca é que esta se inicia sempre no meio de um
 * conjunto de números, logo o vetor de inteiro é sempre dividido ao meio
 * em suas buscas.
 * 
 * @param x se refere ao número que a função de busca irá buscar.
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return a posição do número x no vetor de inteiros (v[]).
 **/
int buscaBinaria(int x, int n, int v[])
{
    int i, f, m;
    i = 0;
    f = n;
    NOP_BUSCA_BINARIA = 0;
    while (i <= f)
    {
        NOP++;
        NOP_BUSCA_BINARIA++;
        m = (i + f)/2;
        if (x == v[m])
            return m;
        
        if (x < v[m])
            f = m - 1;
        else
            i = m + 1;
    }
    return -1;
}

// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n)
{

    return (int *)malloc(n * sizeof(int));
}