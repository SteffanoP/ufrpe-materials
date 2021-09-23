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
int busca(int, int, int *);
int maximo(int, int *);
int twosum(int, int, int *);

int NOP;

int main()
{

    int n, k, x = 42, r = 0;
    veti v;

    Randomize();

    FILE *saida;
    saida = fopen("dados.dat", "w");

    for (n = TAM_INI; n <= TAM_MAX; n += INC)
    {
        v = criaveti(n);
        for (k = 0; k < n; k++)
            v[k] = RandomInteger(0, 100);

        x = RandomInteger(0, 100);
        //r = maximo(n, v);
        //r = busca(x, n, v);
        r = twosum(x, n, v);
        fprintf(saida, "%d %d\n", n, NOP);

        free(v);
    }

    fclose(saida);

    return 0;
}

int busca(int x, int n, int v[])
{
    int k;
    k = n - 1;
    NOP = 0;
    while (k >= 0 && v[k] != x)
    {
        k -= 1;
        NOP++;
    }
    return k;
}

int maximo(int n, int v[])
{
    int k, m = v[0];
    NOP = 0;
    for (k = 1; k < n; k++)
    {
        NOP++;
        if (v[k] > m)
            m = v[k];
    }
    return m;
}

int twosum(int k, int n, int v[])
{

    int i, j, r;

    NOP = 0;
    r = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            NOP++;
            if (v[i] + v[j] == k)
                r = 1;
        }

    return r;
}

// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n)
{

    return (int *)malloc(n * sizeof(int));
}