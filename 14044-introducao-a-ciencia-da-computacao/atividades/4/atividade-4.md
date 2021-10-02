# Atividade 4 - Arquitetura e Organização de Computadores

## Aluno: Steffano Xavier Pereira

### 1) Considere algum equipamento que você possui na sua casa como smartphone ou tablet

A escolha foi o meu Smartphone, que é um Samsung A32.

1. Informe se a arquitetura geral de computadores exibida na aula contendo os 4 elementos básicos continua válida para o seu equipamento, justificando.

    Sim, continua sendo válido: Há apenas um processador central (Helio G80 MediaTek), há dois tipos de memórias (RAM: 4gb e ROM: 128gb), quanto a entradas e saídas, há diversas, visto que, o foco de um smartphone é ter o máximo de entradas e saídas (alguma delas são, tela touch de 6.4 polegadas com leitor de digital, Alto-falante, botões laterais de bloqueio e volume, câmera, módulos de comunicação, sensores e etc.). As interconexões por sua vez ficam inseridas internamente no celular, podem ser constituídas de cabos internos e de barramentos internos e externos, os tais barramentos externos se referem às portas de comunicação.

2. escolha pelo menos 2 elementos do seu equipamento e forneça informações técnicas sobre eles (como características do processador e memória, por exemplo)

    Podemos observar nesse celular 2 componentes interessantes, como seu processador que é um **Helio G80 MediaTek** que é o dispositivo de processamento central e também nós temos a câmera do celular que é um dispositivo de entrada de informação.

    1. Processador Helio G80 MediaTek

        O processador G80 da Mediatek implementa uma arquitetura **ARM** de processadores que podem operar com até 2 GHz de velocidade, que é um par de processadores da linha **Cortex-A75**. Há também mais 6 processadores da linha **Cortex-A55** (com até 1.8 GHz de velocidade) operando separadamente. Dessa forma a linha G80 implementa um cluster de 8 núcleos de processamento. Além disso, possuí algumas particularidades como, Multiprocessamento Heterogêneo e operação com 64-bit. O fabricante não informou a quantidade de cache, porém informa que a arquitetura de cache é uma arquitetura do tipo L3.

    2. Câmera

        A câmera nesse smartphone, na realidade, as câmeras desse smartphone possuem diversas finalidades, a câmera é um dispositivo de entrada de informação, que são caracterizadas por uma câmera principal e outras câmeras que a complementam, sua resolução pode chegar até 9000x7000 pixels, óbvio que não é o caso, pois o celular só é capaz de processar até a resolução Full HD (1920x1080).

### 2) Sobre a hierarquia de memória, escolha um equipamento para analisar (pode ser qualquer equipamento que você possui acesso como um computador, smartphone, etc). Selecione pelo menos dois tipos de armazenamento que constam na pirâmide de hierarquia de memória apresentada na aula e que também estão presentes no seu equipamento. Compare estes dois tipos de memória, informando detalhes técnicos como capacidade de armazenamento, velocidade, custo (pesquise na internet em lojas se necessário), etc. Exemplos de comparação: HD vs RAM; RAM vs cartão SD; etc

O equipamento escolhido foi o meu computador pessoal que possuí memórias dinâmicas RAM e memórias de armazenamento de estado sólido (aka Solid State Drive, SSD).

|     Características     |   SSD    | Memória RAM |
|:-----------------------:|:--------:|:-----------:|
|    **Armazenamento**    |  240 gb  |    8 gb     |
|**Velocidade de Leitura**| 530 MB/s |             |
|**Velocidade de Escrita**| 440 MB/s |             |
|     **Frequência**      |          |  1600 MHz   |
|        **Custo**        | R$250,00 |  R$220,00   |

Vale lembrar que a arquiteturas de memória RAM e memória ROM são arquiteturas totalmente diferentes, tal qual, a ideia dessas memórias são totalmente diferentes. A memória RAM é a primeira forma de armazenamento **dinâmico** de acesso rápido, que independe do processador, porém que, trabalha junto com o processador para processar as operações. Já a memória ROM funciona com o objetivo de ser o armazenamento de informações que não são voláteis, visto que, a memória RAM é uma memória volátil, ou seja, caso perca sua fonte de alimentação iremos perder nossos dados. Logo a memória ROM visa armazenar dados não voláteis, que precisam ser armazenados.
