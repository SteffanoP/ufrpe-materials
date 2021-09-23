# Atividade semana 3 - experiências com complexidade de algoritmos

## Respostas por Steffano Xavier Pereira

### 1) Esse código tem três funções que realizam alguma tarefa com vetores: busca, maximo e twosum. Sua primeira tarefa é escrever um comentário para cada uma dessas funções, dizendo o quê ela faz, ou seja: o que recebe (parâmetros), e o que devolve. Você não precisa mandar um novo código; basta responder com os comentários

```c
/**
 * A função de busca visa buscar um valor especificado dentro de um vetor
 * de inteiros. A função realiza uma iteração por meio de um método while
 * do qual irá iterar até encontrar o valor correspondente a busca.
 * 
 * @param x se refere ao número que a função de busca irá buscar.
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return a posição do número x no vetor de inteiros (v[]).
 **/
int busca(int x, int n, int v[])
```

```c
/**
 * A função de máximo visa buscar o valor máximo dentro do nosso vetor de 
 * inteiros, de tal forma que essa função deverá iterar por todo nosso ve
 * tor para poder concluir qual o maior número do vetor de inteiros.
 * 
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return o maior inteiro inserido no vetor de inteiros.
 **/
int maximo(int n, int v[])
```

```c
/**
 * A função twosum, visa saber se existe a soma de dois números do vetor
 * de inteiros que seja igual a um valor especificado.
 * 
 * @param k se refere ao valor especificado.
 * @param n se refere ao tamanho do vetor de inteiros.
 * @param v se refere ao vetor de números inteiros.
 * @return 0 caso não exista a soma dos dois números iguais ao valor
 * especificado
 *         1 caso exista a soma de dois números iguais ao valor 
 * especificado
 **/
int twosum(int k, int n, int v[])
```

---

### 2) A variável global NOP serve para contar o número de operações executadas em determinadas linhas do código. Vamos entender esse conceito como "número de vezes que essa linha é executada" quando a função que contém essa linha é chamada. Neste exercício, você vai tentar estimar esse número somente lendo o código, sem precisar executar. Um exemplo para ficar mais claro: quantas vezes a linha 68 é executada? Resposta: n vezes. O número de vezes depende assim de n, que é o tamanho do vetor, ou o tamanho do problema resolvido pela função. Em poucas situações elementares, o número de operações é um número explícito: por exemplo, quantas vezes a linha 67 é executada? Resposta, somente uma vez. Responda os itens a seguir; na maioria das vezes, será necessário apresentar uma expressão em função de n

1. Quantas vezes a linha 70 é executada?

    Será equivalente à `n-1` operações, tal que, `n` é o tamanho do vetor de inteiros.

2. Quantas vezes a linha 83 é executada?

    Será equivalente à `n` operações, tal que, `n` é o tamanho do vetor de inteiros.

3. Quantas vezes a linha 85 é executada?

    Será equivalente à `n^2` operações, tal que, `n` é o tamanho do vetor de inteiros.

4. Quantas vezes a linha 71 é executada, no mínimo?

    Para este exemplo, observando do mínimo, caso o valor `v[0]` assuma o maior valor possível então não seria executada em nenhum momento.

5. Quantas vezes a linha 71 é executada, no máximo?

    Para este exemplo, observando do máximo, caso valor de `v[k]` assuma os valores de acordo com a função `v[k] = m + 1` então o máximo seria `n-1`, tal que, `n` é o tamanho do vetor de inteiros.

---

### 3) Execute o código chamando dentro do laço principal (função main) a função maximo. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. Esse arquivo sugere que n e NOP estão relacionados de que forma?

Estão relacionados de tal forma que podem ser definidos por uma função linear: `f(n) = n - 1`, visto que `n` se refere ao tamanho do vetor de inteiros e `f(n)` se refere ao NOP. Logo o comportamento do Número de Operações deve ocorrer de forma linear.

---

### 4) Execute o código chamando dentro do laço principal (função main) a função twosum. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. Esse arquivo sugere que n e NOP estão relacionados de que forma?

Neste algoritmo a relação entre n e NOP ocorre de forma quadrática, de tal forma que pode ser definida pela função: `f(n) = n^2`, visto que `n` se refere ao tamanho do vetor de inteiros e `f(n)` se refere ao NOP. Logo o comportamento do Número de operações deve ocorrer de forma quadrática.

---

### 5) Execute o código chamando dentro do laço principal (função main) a função busca. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. É possível dizer que n e NOP estão relacionados de alguma forma? Justifique sua resposta

O comportamento do Número de Operações para o algoritmo de busca é um comportamento que ocorre de forma randomizada, pois tanto faz do algoritmo encontrar o valor especificado em poucas operações, mas também seja possível que ele não encontre o valor especificado no vetor de números inteiros; nesse caso em específico o Número de operações pode assumir seu maior valor possível que seria o tamanho `n` do vetor de números inteiros.

---
