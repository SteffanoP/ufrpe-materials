# Estrutura de decisão condicional

## #1

Elaborar um programa em linguagem C para somar dois números inteiros e mostrar o valor da soma na tela. Você só deve imprimir a mensagem se a soma dos números for maior que 10.

## #2

Escreva um programa em que uma variável recebe um valor lido entre 20 e 100. Imprima na tela o valor gerado, caso seja divisível por 3 e por 5.

## #3

Faça um programa que lê 2 valores A e B (inteiros) e informa se A é divisível por B ou não.

## #4

Entrar com sexo (caractere ‘m’ para masculino e ‘f’ para feminino) e idade de uma pessoa. Se a pessoa for do sexo feminino e tiver menos de 25 anos, imprimir a mensagem: ACEITA. Caso contrário, imprimir a mensagem: NÃO ACEITA.

## #5

Escreva um programa que peça 3 notas (reais) para o usuários. Imprima “voce passou”, caso a média das notas seja maior ou igual a 7; caso contrário, imprima “voce nao passou”.

## #6

Uma empresa deseja dar 20% de aumento para aqueles funcionários que possuem salário menor ou igual a R$1000,00 e um aumento de 10% para aqueles que possuem salários maiores que R$1000,00. Escreva um programa que pede para o usuário digitar o seu salário. Imprima seu novo salário na tela.

## #7

Escreva um programa que peça ao usuário 3 valores reais: r, c1 e c2. O primeiro representa o raio de uma circunferência, e os outros dois valores representam o centro. Peça para o usuário digitar mais dois valores reais: p1 e p2, que representam as coordenadas de um ponto. Imprima “Estah dentro”, se o ponto (p1,p2) está dentro da circunferência, caso contrário, imprima “Estah fora”.

## #8

Um hotel cobra R$50,00 reais a diária e mais uma taxa de serviços. Faça um programa que lê a quantidade de dias que o hóspede ficou no hotel e imprime o valor total a pagar. A taxa de serviços é de:

- 15,30 por dia, se número de diárias <15
- 10,00 por dia, se número de diárias =15
- 8,50 por dia, se número de diárias >15

## #9

Depois da liberação do governo para as mensalidades dos planos de saúde, as pessoas começaram a fazer pesquisas para descobrir um bom plano, não muito caro. Um vendedor de plano de saúde apresentou a tabela a seguir.

- Até 10 anos – R$30,00
- Acima de 10 até 29 anos – R$60,00
- Acima de 29 até 45 anos – R$120,00
- Acima de 45 até 59 anos – R$150,00
- Acima de 59 até 65 anos – R$250,00
- Maior que 65 anos – R$400,00

Criar um algoritmo que entre com a idade de uma pessoa e imprimir o valor que ela deverá pagar.

## #10

A nota final de um estudante é calculada a partir da média de três notas atribuídas entre o intervalo de 0 até 10, respectivamente, a um trabalho de laboratório, a uma avaliação semestral e a um exame final. De acordo com o resultado, mostre na tela se o aluno está reprovado (média <= 4), de recuperação (4 <= media < 7) ou se foi aprovado (media >= 7). Se o aluno for para a recuperação, leia a sua nota na recuperação, e verifique se a média desta nota com a nota final é maior ou igual a 5. Se for, imprima que o mesmo está aprovado na recuperação, caso contrário imprima que o mesmo está reprovado.

## #11

Faça um programa que mostre ao usuário um menu com 4 opções de operações matemáticas (+, -, /, *). O usuário escolhe uma das opções e o seu programa então pede dois valores reais, realiza a operação e imprime o resultado na tela.

## #12

Peça três valores ao usuários, A, B, C, e verifique se eles podem ser valores dos lados de um triângulo. Para ser triângulo, (A+B) > C e (A+C) > B e (B+C) > A.
Se não puder ser triângulo, imprima na tela que “nao pode ser triangulo”; caso contrário, imprima na tela qual é o triângulo formado: escaleno (todos os lados diferentes), isósceles (2 lados iguais e 1 diferente) ou equilátero (3 lados iguais).

## #13

Você está desenvolvendo um sistema de controle de acesso a cinema. Este sistema deve pedir a idade do usuário, e em seguida imprimir as opções de filmes:

- Titanic (16 anos)
- Pica Pau (Livre)
- A volta de Jason (18 anos)
- Desistir

Se o usuário escolher o filme e não tiver idade suficiente, o sistema deve imprimir "Voce nao tem idade para assistir ao filme". Caso o usuário tenha idade para o filme, o sistema imprime "Voce comprou o filme tal. Bom filme!".

## #14

O cardápio de uma lanchonete é o seguinte:

|  Especificação  | Código | Preço |
|:---------------:|:------:|:-----:|
| Cachorro Quente |   100  |  1.20 |
|  Bauru Simples  |   101  |  1.30 |
|  Bauru com ovo  |   102  |  1.50 |
|    Hamburguer   |   103  |  1.20 |
|  Cheeseburguer  |   104  |  1.30 |
|   Refrigerante  |   105  |  1.00 |

Implemente um programa que leia o código do item pedido, a quantidade que deseja comprar e, calcule e imprima o valor a ser pago por aquele lanche.

## #15

Desenvolva um sistema de compra de bebidas. Este sistema, inicialmente, deve pedir para que o usuário informe a sua idade. Se a idade for menor que 18 anos, deve-se imprimir a seguinte mensagem: "você eh de menor e nao pode comprar bebidas". Caso o usuário tenha idade suficiente, o sistema de apresentar o seguinte menu:

- Whisky
- Vodka
- Cerveja
- Cachaça

Se o usuário escolher outra opção, o sistema deve imprimir “opção inválida”.

Se o usuário escolher a opção 1 (whisky), o seguinte menu deve ser impresso:

| Código |   Nome   | Preço |
|:------:|:--------:|:-----:|
|   100  | Whisky 1 |  200  |
|   101  | Whisky 2 |  150  |
|   102  | Whisky 3 |  140  |

Se o usuário escolher a opção 2 (Vodka), o seguinte menu deve ser impresso:

| Código |   Nome  |Preço |
|:------:|:-------:|:----:|
|   200  | Vodka 1 |  60  |
|   201  | Vodka 2 |  40  |
|   202  | Vodka 3 |  30  |

Se o usuário escolher a opção 3 (Cerveja), o seguinte menu deve ser impresso:

| Código |    Nome   |  Preço |
|:------:|:---------:|:------:|
|   300  | Cerveja 1 |  1.50  |
|   301  | Cerveja 2 |   2.0  |
|   302  | Cerveja 3 |   3.0  |

Se o usuário escolher a opção 4 (Cachaça), o seguinte menu deve ser impresso:

| Código |    Nome   |  Preço  |
|:------:|:---------:|:-------:|
|   400  | Cachaça 1 |    8.0  |
|   401  | Cachaça 2 |   20.0  |
|   402  | Cachaça 3 |   22.0  |

Uma vez direcionado ao menu escolhido, o usuário pode escolher a bebida que deseja e a quantidade. Se a quantidade for menor que 1, o sistema deve imprimir “quantidade inválida”. Se a quantidade for válida, ou seja, maior ou igual a 1, caso o usuário compre mais de 5 bebidas, receber desconto de 10%. Se comprar mais de 50 bebidas, o desconto é de 30%. Acima de 100 bebidas o desconto é de 35%.

O sistema deve imprimir na tela a bebida comprada, a quantidade e o valor final a ser pago.
