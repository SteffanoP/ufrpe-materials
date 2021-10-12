# Atividade Semana 7

Este exercício envolve o código fornecido nas semanas anteriores em C e que vocês já têm utilizado para criar vetores aleatórios, salvar arquivo dat., entre outros. Se você fez um equivalente em Python ou outra linguagem, também pode utilizar.

Nesse exercícios, você só vai fazer alterações no arquivo main.c, utilizando os arquivos de suporte que já vinham utilizando para responder cada item a seguir. A solução deve ser enviada no Classroom, identificando bem, nos arquivos entregues, qual é o item sendo respondido. Copie seu código da main para um arquivo do google docs.

1. Usando a estratégia de divisão e conquista, podemos calcular a exponenciação k^n (dados inteiros k e n) de forma mais eficiente do que fazer n - 1 multiplicações (ou seja, através de um laço que calcula `k*k*k ...`). A idea geral é: para calcular k^n, calculamos primeiro k^{n / 2} e usamos esse valor. Implemente um algoritmo recursivo que usa essa ideia.

2. Implemente um Quicksort recursivo (você provavelmente já fez isso na semana 5). Utilize-o para comparar com as variações do quicksort das próximas questões (essa implementação não vale nota).

3. Implemente um Quicksort Iterativo: esta variação escolhe o pivô como o elemento do meio, mas não é recursiva. Em outras palavras, esta é uma versão iterativa do Quicksort apresentado em aulas anteriores.

4. Quicksort Empilha Inteligente(): esta variação otimizada do Quicksort processa primeiro o lado menor da partição. Voce deve aplicar esta otimização à versão iterativa do Quicksort.

5. Usando novamente o contador NOP, construa arquivos de pontos para os algoritmos que você implementou (como você fez nas últimas semanas), contendo uma estimativa do número de operações executadas para diversos valores de n. Com base nesses arquivos, tente argumentar qual é a complexidade dos algoritmos. No caso da exponenciação, compare-o com o algoritmo que faz todas as multiplicações (é mais eficiente? menos eficiente? a complexidade é semelhante?). No caso dos quicksorts, compare as 3 versões. Cada variação do algoritmo Quicksort deverá ser aplicado a entradas aleatórias com diferentes tamanhos (parâmetro n). Experimente, no mínimo, com valores de n = 1000, 5000, 10000, 50000, 10 0000, 500.000 e 1.000.000. Para cada valor de n, você deverá gerar 5 (cinco) conjuntos de elementos diferentes, e calcular a média de operações (nop) dessas execuções.

## Requisitos

Você deve entregar um pequeno relatório, no final do próprio arquivo google docs, expondo suas análises das questões, e enviar seus arquivos de pontos junto de seu relatório. Lembre de plotar os conjunto de pontos para tornar as coisas mais claras nas análises, mas isso não é obrigatório.

Resumindo, você deve entregar:

Código das funções das questões e os arquivos .dat, executar sua análise e realizar uma discussão da análise realizada.
