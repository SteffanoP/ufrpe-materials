# Atividade semana 3 - experiências com complexidade de algoritmos

Essa atividade é baseada no código em anexo. Para executar o código, você precisa baixar os arquivos .c e .h (arquivos de cabeçalho) da biblioteca de Eric Roberts, disponíveis em <https://www.ime.usp.br/~pf/Roberts/C-library/standard/> Você pode colocar todos os arquivos na mesma pasta. Sugiro que você use o Code::Blocks ou o Repl.it (online) para compilar.

A primeira coisa a se fazer é se ambientar com o código. Leia a função main, e note que ela tem um laço controlado por três parâmetros: TAM_INI, TAM_MAX e INC. Esse laço serve para executar testes com uma das funções implementadas no final do código, a cada iteração, um teste (uma chamada) da função é feita, para um novo vetor. Mais precisamente, cada iteração desse laço consiste em criar um vetor de tamanho (= número de posições) n, preencher esse vetor com números (pseudo) aleatórios, e chamar uma função sobre esse vetor. A chamada da função resulta na modificação da variável global NOP ("número de operações"), que é salva no arquivo "dados.dat", juntamente do valor de n. Tente executar esse código. Modifique os valores dos parâmetros, para entender melhor o que acontece.

As questões que você deverá responder seguem abaixo e podem ser feitas todas em um mesmo arquivo texto.

1. Esse código tem três funções que realizam alguma tarefa com vetores: busca, maximo e twosum. Sua primeira tarefa é escrever um comentário para cada uma dessas funções, dizendo o quê ela faz, ou seja: o que recebe (parâmetros), e o que devolve. Você não precisa mandar um novo código; basta responder com os comentários.

2. A variável global NOP serve para contar o número de operações executadas em determinadas linhas do código. Vamos entender esse conceito como "número de vezes que essa linha é executada" quando a função que contém essa linha é chamada. Neste exercício, você vai tentar estimar esse número somente lendo o código, sem precisar executar. Um exemplo para ficar mais claro: quantas vezes a linha 68 é executada? Resposta: n vezes. O número de vezes depende assim de n, que é o tamanho do vetor, ou o tamanho do problema resolvido pela função. Em poucas situações elementares, o número de operações é um número explícito: por exemplo, quantas vezes a linha 67 é executada? Resposta, somente uma vez. Responda os itens a seguir; na maioria das vezes, será necessário apresentar uma expressão em função de n.

    1. Quantas vezes a linha 70 é executada?
    2. Quantas vezes a linha 83 é executada?
    3. Quantas vezes a linha 85 é executada?
    4. Quantas vezes a linha 71 é executada, no mínimo?
    5. Quantas vezes a linha 71 é executada, no máximo?

3. Execute o código chamando dentro do laço principal (função main) a função maximo. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. Esse arquivo sugere que n e NOP estão relacionados de que forma?

4. Execute o código chamando dentro do laço principal (função main) a função twosum. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. Esse arquivo sugere que n e NOP estão relacionados de que forma?

5. Execute o código chamando dentro do laço principal (função main) a função busca. Abra em seguida o arquivo dados.dat gerado, e observe os números: a coluna da esquerda é o tamanho n do vetor, a da direita é o valor de NOP após a execução da função. É possível dizer que n e NOP estão relacionados de alguma forma? Justifique sua resposta.
