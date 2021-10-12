#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"
#include "random.c"
#include <string.h>

#define TAM_INI 50000
#define TAM_MAX 1000000
#define INC 50000

// simpio.h e random.h vêm da biblioteca de
// Eric Roberts, acessível por exemplo em
// https://www.ime.usp.br/~pf/Roberts/C-library/standard/

typedef int *veti; // Apelida de "veti" ("vetor de inteiros") o tipo "int *".

veti criaveti(int);

veti quickSort(int arr_count, int *);
void quickSortIterative(int *, int l, int h);
void smartQuickSort(int arr_count, int *);

//veti quickSortIterative(int arr_count, int *);
int posiciona(int s, int e, int *, int pivot);

int particiona(int *, int l, int h);
void troca(int *a, int *b);

int NOP, NOP_REC, NOP_ITER, NOP_S_ITER;

int main(int argc, char const *argv[])
{
    int n, k, x = 42, r = 0;
    veti v, y, z;

    Randomize();

    FILE *saida;
    saida = fopen("dados.dat", "w");
    fprintf(saida, "n\t\tNOP_REC\t\tNOP_ITER\tNOP_S_ITER\n");

    for (n = TAM_INI; n <= TAM_MAX; n += INC)
    {
        v = criaveti(n);
        y = criaveti(n);
        z = criaveti(n);
        for (k = 0; k < n; k++) {
            v[k] = RandomInteger(0, 100);
            y[k] = RandomInteger(0, 100);
            z[k] = RandomInteger(0, 100);
        }
        
        NOP_REC = 0;
        v = quickSort(n, v);
        NOP_ITER = 0;
        quickSortIterative(y, 0, n - 1);
        NOP_S_ITER = 0;
        smartQuickSortIterative(z, 0, n - 1);

        fprintf(saida, "%.4d\t%7d\t\t%7d\t\t%7d \n", n, NOP_REC, NOP_ITER, NOP_S_ITER);

        free(v);
    }

    fclose(saida);

    return 0;
}

veti quickSort(int arr_count, veti arr)
{
    //This condition is not necessary, but we get our
    //result faster than doing a new quicksort
    if (arr_count == 2)
    {
        if (arr[0] < arr[1])
            return arr;
        else
        {
            int b = arr[0];
            arr[0] = arr[1];
            arr[1] = b;
            return arr;
        }
    }

    veti left =  criaveti(arr_count);
    veti equal = criaveti(arr_count);
    veti right = criaveti(arr_count);

    //Storing the pivot
    int pivot = arr[0];

    //Dividing
    int index_left = 0, index_equal = 0, index_right = 0;
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] < pivot)
            left[index_left++] = arr[i];
        else if (arr[i] == pivot)
            equal[index_equal++] = arr[i];
        else
            right[index_right++] = arr[i];

        NOP_REC++;
    }

    if (index_left > 1) {
        left = quickSort(index_left, left);
    }

    if (index_right > 1) {
        right = quickSort(index_right, right);
    }

    //Group all together
    veti a = criaveti(arr_count);
    memcpy(a, left, index_left * sizeof(index_left));
    memcpy(a + index_left, equal, index_equal * sizeof(int));
    memcpy(a + index_left + index_equal, right, index_right * sizeof(int));

    //Getting free of our Arrays
    free(left);
    free(equal);
    free(right);

    return a;
}

int particiona(int arr[], int start, int end)
{
    int l = start, r = end;
    int pivot = arr[(start + end) / 2];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;

        if (l <= r) {
            troca(&arr[l], &arr[r]);
            l++;
            r--;
        }
        NOP_ITER++;
        NOP_S_ITER++;
    }
    
    return l;
}

void quickSortIterative(veti arr, int l, int h)
{
    int pilha[h - l + 1];

    int t = -1;
    pilha[++t] = l;
    pilha[++t] = h;

    while (t >= 0)
    {
        h = pilha[t--];
        l = pilha[t--];

        int p = particiona(arr, l, h);

        //Parâmetros para o possível próximo particionamento
        if (p - 1 > l)
        {
            pilha[++t] = l;
            pilha[++t] = p - 1;
        }
        
        if (p < h)
        {
            pilha[++t] = p;
            pilha[++t] = h;
        }
    }
}

void smartQuickSortIterative(veti arr, int l, int h)
{
    int pilha[h - l + 1];

    int t = 0;
    pilha[t] = l;
    t++;
    pilha[t] = h;

    bool first_time = 1;

    while (t >= 0)
    {
        h = pilha[t--];
        l = pilha[t--];

        int p = particiona(arr, l, h);

        //Parâmetros para o possível próximo particionamento

        if (p - l < h - p)
        {
            if (p < h)
            {
                pilha[++t] = p;
                pilha[++t] = h;
            }

            if (p - 1 > l)
            {
                pilha[++t] = l;
                pilha[++t] = p - 1;
            }
        }
        else
        {
            if (p - 1 > l)
            {
                pilha[++t] = l;
                pilha[++t] = p - 1;
            }

            if (p < h)
            {
                pilha[++t] = p;
                pilha[++t] = h;
            }
        }
    }
}
// Aloca um vetor de inteiros de tamanho n.
// Devolve o ponteiro para esse vetor.
veti criaveti(int n)
{
    return (int *)malloc(n * sizeof(int));
}

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
