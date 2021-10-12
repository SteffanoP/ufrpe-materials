# Atividade Semana 7

Este exercício envolve o código fornecido nas semanas anteriores em C e que vocês já têm utilizado para criar vetores aleatórios, salvar arquivo dat., entre outros. Se você fez um equivalente em Python ou outra linguagem, também pode utilizar.

Nesse exercícios, você só vai fazer alterações no arquivo main.c, utilizando os arquivos de suporte que já vinham utilizando para responder cada item a seguir. A solução deve ser enviada no Classroom, identificando bem, nos arquivos entregues, qual é o item sendo respondido. Copie seu código da main para um arquivo do google docs.

1. Usando a estratégia de divisão e conquista, podemos calcular a exponenciação k^n (dados inteiros k e n) de forma mais eficiente do que fazer n - 1 multiplicações (ou seja, através de um laço que calcula `k*k*k ...`). A idea geral é: para calcular k^n, calculamos primeiro k^{n / 2} e usamos esse valor. Implemente um algoritmo recursivo que usa essa ideia.

    ```c
    long expo_recursivo(int k, int n) 
    {
        if (n <= 1)
            return n == 0 ? 1 : k;
        
        long resultado;
        if (n % 2 == 0)
        {
            resultado = expo_recursivo(k, n/2) * expo_recursivo(k, n/2);
        }
        else
        {
            resultado = expo_recursivo(k, n/2) * expo_recursivo(k, (n/2) + 1);
        }
        return resultado;
    }
    ```

    ---

2. Implemente um Quicksort recursivo (você provavelmente já fez isso na semana 5). Utilize-o para comparar com as variações do quicksort das próximas questões (essa implementação não vale nota).

    ---

3. Implemente um Quicksort Iterativo: esta variação escolhe o pivô como o elemento do meio, mas não é recursiva. Em outras palavras, esta é uma versão iterativa do Quicksort apresentado em aulas anteriores.

    ```c
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
    ```

    ---

4. Quicksort Empilha Inteligente(): esta variação otimizada do Quicksort processa primeiro o lado menor da partição. Voce deve aplicar esta otimização à versão iterativa do Quicksort.

    ```c
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
    ```

5. Usando novamente o contador NOP, construa arquivos de pontos para os algoritmos que você implementou (como você fez nas últimas semanas), contendo uma estimativa do número de operações executadas para diversos valores de n. Com base nesses arquivos, tente argumentar qual é a complexidade dos algoritmos. No caso da exponenciação, compare-o com o algoritmo que faz todas as multiplicações (é mais eficiente? menos eficiente? a complexidade é semelhante?). No caso dos quicksorts, compare as 3 versões. Cada variação do algoritmo Quicksort deverá ser aplicado a entradas aleatórias com diferentes tamanhos (parâmetro n). Experimente, no mínimo, com valores de n = 1000, 5000, 10000, 50000, 10 0000, 500.000 e 1.000.000. Para cada valor de n, você deverá gerar 5 (cinco) conjuntos de elementos diferentes, e calcular a média de operações (nop) dessas execuções.

    1. Algoritmo Exponencial

       Tomando como ponto de vista a análise do tipo NOP. O algoritmo de cálculo exponencial possui desempenhos parecidos, ambos o iterativo quanto ao recursivo são linearmente parecidos (Figura 1), porém o algoritmo iterativo padrão é mais vantajoso por ter menos operações como podemos visualizar na Tabela 1.

       ```dat
        n     NOP_EXPO    NOP_EXPO_REC
        0       0           1
        1000    1000        1999
        5000    5000        9999
        10000   10000       19999
        50000   50000       99999
        100000  100000      199999
        500000  500000      999999
        1000000 1000000     1999999
       ```

       Todavia, para esse tipo de algoritmo a análise por número de operações entre eles pode não indicar exatamente quem é mais eficiente, sendo mais interessante observar, por exemplo, o tempo de execução para cada.

    2. Quicksort Iterativo e Smart quicksort

        Foram implementados: um algoritmo quicksort iterativo e um algoritmo quicksort iterativo inteligente, que prioriza o empilhamento do menor lado da partição. Observando as 5 baterias de testes realizadas por esse algoritmo chegamos a conclusão prevista na figura 2.

        Seguindo o gráfico demonstrado, por mais que pareça que linear, o gráfico está em escala logarítmica para uma melhor visualização dos valores de NOP, todos os 3 algoritmos desempenharam de acordo com o caso médio que é O(n log n). Todavia houveram pequenas diferenças perceptíveis acerca de cada algoritmo.

        O algoritmo implementado de forma iterativa (em vermelho) foi o menos eficiente, porém manteve um desempenho estável para todos os valores de n.

        Já o algoritmo recursivo e o iterativo inteligente tiveram uma pequena briga, inicialmente o iterativo foi mais eficiente, porém ao longo do aumento dos valores de n, o algoritmo passou a ser mais eficiente.

        Vale lembrar que, os seguintes testes são apenas um recorte do desempenho de tais algoritmos, e que outros testes de desempenho (como o tempo de execução, diferentes datasets para ordenação e etc) devem ser realizados para atestar o desempenho verídico de tais algoritmos.

    ---
