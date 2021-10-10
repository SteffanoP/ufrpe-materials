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

void mergeSort(int idx_i, int idx_f, int *);
void merge_veti(int idx_i_g1, int half_index, int idx_f_g2, int *);

int NOP_MSORT, NOP_QSORT;

int main(int argc, char const *argv[])
{
    int n, k, x = 42, r = 0;
    veti v;

    Randomize();

    FILE *saida;
    saida = fopen("dados.dat", "w");
    fprintf(saida, "n\t\tNOP_QSORT\tNOP_MSORT\n");

    for (n = TAM_INI; n <= TAM_MAX; n += INC)
    {
        v = criaveti(n);
        for (k = 0; k < n; k++)
            v[k] = RandomInteger(0, 100);

        NOP_MSORT = 0;
        insertionSort(n, v);
        mergeSort(0, n - 1, v);

        fprintf(saida, "%.4d\t%7d\t\t%5d \n", n, NOP_QSORT, NOP_MSORT);

        free(v);
    }

    fclose(saida);

    return 0;
}

/**
 * @param idx_i se refere ao index inicial do vetor
 * @param idx_f se refere ao index final do vetor
 * @param v se refere ao vetor de inteiros
 **/
void mergeSort(int idx_i, int idx_f, int v[])
{
    if (idx_i < idx_f)
    {
        int half_index = idx_i + (idx_f - idx_i)/2;
        mergeSort(idx_i, half_index, v);
        mergeSort(half_index + 1, idx_f, v);
        merge_veti(idx_i, half_index, idx_f, v);
    }
}

/**
 * @param idx_i_g1 se refere ao index inicial do vetor do 
 * grupo 1 (grupo da direita)
 * @param half_index se refere ao index central do vetor, 
 * também pode ser referenciado como o index final do vetor
 * do grupo 1 (grupo da direita)
 * @param idx_f_g2 se refere ao index final do grupo 2
 * (grupo da esquerda)
 * @param v se refere ao vetor de inteiros
 **/
void merge_veti(int idx_i_g1, int half_index, int idx_f_g2, int v[])
{
    int size_left_group = (half_index - idx_i_g1) + 1;
    int size_right_group = idx_f_g2 - half_index;
    
    veti left_group = criaveti(size_left_group);
    veti right_group = criaveti(size_right_group);

    for (int i = 0; i < size_left_group; i++)
        left_group[i] = v[idx_i_g1 + i];

    for (int i = 0; i < size_right_group; i++)
        right_group[i] = v[half_index + 1 + i];

    int index_right = 0, index_left = 0;
    int index_veti = idx_i_g1;
    
    do
    {
        if (left_group[index_left] <= right_group[index_right])
        {
            v[index_veti] = left_group[index_left];
            index_left++;
        }
        else
        {
            v[index_veti] = right_group[index_right];
            index_right++;
        }
        index_veti++;
        NOP_MSORT++;
    } while (index_left < size_left_group && index_right < size_right_group);

    while (index_left < size_left_group)
    {
        v[index_veti] = left_group[index_left];
        index_left++;
        index_veti++;
        NOP_MSORT++;
    }

    while (index_right < size_right_group)
    {
        v[index_veti] = right_group[index_right];
        index_right++;
        index_veti++;
        NOP_MSORT++;
    }

    free(left_group);
    free(right_group);
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
    NOP_QSORT = 0;
    for (int i = 1; i < n; i++)
    {
        int x = v[i]; //2
        int j = i - 1; //3

        while ((j >= 0) && (x < v[j]))
        {
            NOP_QSORT++;
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
    return v;
}

// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n)
{

    return (int *)malloc(n * sizeof(int));
}