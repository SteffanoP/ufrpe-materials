# Atividade semana 4 - Busca e ordenação

## Respostas por Steffano Xavier Pereira

### 2) Implemente a função insertionSort que ordena um vetor

```c
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
```

### 3) Implemente a função buscaBinaria que realiza a busca binária considerando um vetor ordenado

```c
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
```

### 4) Adicione um contador de operações NOP nas funções que você implementou

Para analisar o funcionamento das operações requisitadas foram implantados diversos NOP's para analisar cada função específica. Foram organizadas no arquivo da seguinte forma:

1. NOP_BLINEAR: Corresponde ao Número de Operações apenas para a Busca Linear.
2. NOP_SORT: Corresponde ao Número de Operações apenas para a Ordenação do vetor de inteiros.
3. NOP_BBINÁRIA: Corresponde ao Número de Operações apenas para a Busca Binária.
4. NOP: Corresponde ao Número de Operação da Ordenação do vetor de inteiros e da Busca Binária.

### 5) Execute diversas buscas aleatórias num vetor (tam>1000) e compare sua eficiência usando dados.dat (discuta o que ocorreu e os porquês)

1. Utilizando sempre a busca linear (já implementada semana passada na função busca);

2. Primeiro ordenando e sempre utilizando buscaBinaria para buscar.
