# Atividade Semana 6 - Mergesort

1. (SW ex.2.2.8) Um estudante propôs uma modificação na versão top-down do mergesort para que a intercalação dos elementos fosse evitada caso os elementos já estivessem ordenados. Ocorre alguma melhoria no número de comparações? Justifique.

2. (Cormen et al, Teoria e Prática, Problemas 2.1 modificado) Ordenação por inserção sobre arranjos pequenos na ordenação por intercalação (mergesort). Embora a ordenação por intercalação funcione no tempo de pior caso O(n lg n) e a ordenação por inserção funcione no tempo de pior caso 0(n2), os fatores constantes na ordenação por inserção a tornam mais rápida para n pequeno. Assim, faz sentido usar a ordenação por inserção dentro da ordenação por intercalação quando os subproblemas se tornam suficientemente pequenos. Considere uma modificação na ordenação por intercalação, na qual n/k sublistas de comprimento k são ordenadas usando-se a ordenação por inserção, e depois intercaladas com o uso do mecanismo padrão de intercalação, onde k é um valor a ser determinado. Utilize o código base da semana 3:
    1. Implemente o mergesort padrão
    2. Implemente o mergesort associado ao insertionsort conforme descrito na questão.
    3. Como k deve ser escolhido na prática? Explique.
    4. Adicione NOP para contar as operações tanto no mergesort padrão quanto no modificado e faça uma análise comparativa.
