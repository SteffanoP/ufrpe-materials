# Atividade Semana 6 - Mergesort

## Respostas por Steffano Xavier Pereira

1. (SW ex.2.2.8) Um estudante propôs uma modificação na versão top-down do mergesort para que a intercalação dos elementos fosse evitada caso os elementos já estivessem ordenados. Ocorre alguma melhoria no número de comparações? Justifique

Podemos observar da seguinte forma, caso a modificação do estudante consiga identificar um subgrupo já ordenado, não há mais a necessidade de realizar o mergesort nesse subgrupo, logo ocorre uma melhoria no desempenho do mergesort. O mergesort é um algoritmo que demanda mais computacionalmente no processo de intercalação dos elementos, visto que essa é a característica intrínseca desse algoritmo, se você consegue dizer se um vetor de números já está ordenado, consequentemente o Mergesort só irá se preocupar em realizar o merge desse vetor com um outro vetor, baseando-se que o outro vetor foi ordenado previamente pela recursividade do algoritmo.

Porém, se tratando das comparações que esse subgrupo irá realizar com um outro subgrupo para formar um grupo, não haverá diferença, por a intercalação irá ocorrer entre todos os elementos.

Em resumo, se a modificação identifica o ordenamento de um subgrupo pai, não haverá a necessidade de subgrupos filhos, e logo não haverá intercalação entre os subgrupos filhos, porém se o ponto de vista for a intercalação de comparações do subgrupo com outro subgrupo, não haverá diferenças nas comparações de intercalação.

2. (Cormen et al, Teoria e Prática, Problemas 2.1 modificado) Ordenação por inserção sobre arranjos pequenos na ordenação por intercalação (mergesort). Embora a ordenação por intercalação funcione no tempo de pior caso O(n lg n) e a ordenação por inserção funcione no tempo de pior caso 0(n2), os fatores constantes na ordenação por inserção a tornam mais rápida para n pequeno. Assim, faz sentido usar a ordenação por inserção dentro da ordenação por intercalação quando os subproblemas se tornam suficientemente pequenos. Considere uma modificação na ordenação por intercalação, na qual n/k sublistas de comprimento k são ordenadas usando-se a ordenação por inserção, e depois intercaladas com o uso do mecanismo padrão de intercalação, onde k é um valor a ser determinado. Utilize o código base da semana 3:
    1. Implemente o mergesort padrão
    2. Implemente o mergesort associado ao insertionsort conforme descrito na questão.
    3. Como k deve ser escolhido na prática? Explique.
    4. Adicione NOP para contar as operações tanto no mergesort padrão quanto no modificado e faça uma análise comparativa.

As perguntas 1 e 2 são respondidas com o código em anexo.

Já para o k, devemos observar o desempenho do algoritmo de insertionSort, visto que o algoritmo de Mergesort sempre terá o mesmo desempenho independente do cenário.

Observando mais a fundo o insertionSort é um algoritmo que possuí um melhor cenário e o seu pior cenário. Observemos

- Melhor cenário do InsertionSort seu desempenho é O{n} que é quando o vetor está pouco desordenado;
- Pior cenário do InsertionSort seu desempenho é O{n²} que é quando o vetor está muito desordenado (teremos um número maior de operações/comparações até chegar num vetor ordenado).

Uma característica interessante do insertionSort é que seu desempenho é mais rápido quando seu tamanho de vetores inteiros é pequeno até um valor, matematicamente esse valor é dado como `log2(n) = k`, tendo em vista que a partir de `k + 1` o uso do mergesort é mais vantajoso.

