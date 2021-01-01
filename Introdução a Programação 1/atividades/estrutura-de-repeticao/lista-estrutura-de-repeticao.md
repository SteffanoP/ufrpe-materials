# Lista de Estruturas de Repetição

## 1

Faça um programa que leia 10 números inteiros (positivos ou negativos). Imprima a média dos valores, ignorando os não positivos.

## 2

Escreva um programa que leia um número inteiro e calcule a soma de todos os divisores desse número, com exceção dele próprio. Ex: a soma dos divisores do número 66 é 1 + 2 + 3 + 6 + 11 + 22 + 33 = 78.

## 3

A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o salário e número de filhos. A prefeitura deseja saber:

1. média do salário da população;
2. média do número de filhos;
3. maior e menor salário;
4. percentual de habitantes com mais de 2 filhos.

A quantidade de habitantes que serão cadastrados é fornecida pelo usuário.

## 4

No dia da estreia do filme “Senhor dos Anéis”, uma grande emissora de TV realizou uma pesquisa logo após o encerramento do filme. Cada espectador respondeu a um questionário no qual constava sua idade e sua opinião em relação ao filme:

1. Excelente;
2. Bom;
3. Regular.

Crie um algoritmo que receba a idade e a opinião de 10 espectadores, calcule e imprima:

- A média das idades das pessoas que responderam excelente;
- a quantidade de pessoas que responderam regular;
- a percentagem de pessoas que responderam bom entre todos os expectadores analisados.

## 5

Dado um número inteiro positivo, verificar se o número é primo ou não. OBS: Número primo é aquele que possui apenas dois divisores, o número 1 e o próprio número.

## 6

Faça um programa que leia de forma indefinida vários números, calcule e mostre:

1. A soma dos números digitados
2. A quantidade de números digitados
3. A média de números digitados
4. O maior número digitado
5. O menor número digitado
6. A média dos números pares

Finalize a entrada de dados caso o usuário informe o valor 0.

## 7

Escreva um programa que pergunta um número ao usuário, e mostra sua tabuada completa (de 1 até 10).

Ex: Se o número lido foi 4, imprimir:
4x1 = 4
4x2 = 8
4x3 = 12
…
4x10 = 10

## 8

Desenvolva um sistema de verificação do usuário. Para isso, crie uma variável inteira chamada de senha e atribua a ela um número inteiro de 4 dígitos.
O programa deve pedir ao usuário uma senha, e verificar se a senha condiz com o valor armazenado na variável senha. Se a senha digitada não estiver correta, imprima “Senha Incorreta” e solicite novamente a senha. Se a senha digitada for a correta, deverá ser apresentada a mensagem “Senha Correta”. Vale salientar que o usuário só possui 3 tentativas para acertar a senha. Caso não acerte, deve ser impresso “acesso bloqueado”.

## 9

Criar um programa que apresenta o seguinte menu:

1. Imprimir “Olá!”;
2. Imprimir "Bem vindo";
3. Sair do algoritmo.

Se o usuário digitar a opção 1 ou 2, a respectiva mensagem é impressa. Em seguida, o menu é impresso novamente para que o usuário faça uma nova escolha. O programa só é encerrado quando o usuário digitar 3 para sair.

## 10

A sequência de Fibonacci é uma sequência infinita composta por números que obedecem o seguinte padrão: 0 1 1 2 3 5 8 13…
Como pode se ver, os dois primeiros números (0 1) quando somados dão origem ao terceiro (1). De modo que o n-ésimo número é fruto da soma dos dois anteriores.
Crie um programa que pede ao usuário um número X, e imprima o X-ésimo valor da sequência.
Ex: Se o usuário digitar 6, o valor a ser impresso é 8, que é o sexto valor da sequência.

## 11

Faça um programa que simule a urna eletrônica. A tela a ser apresentada deverá ser da seguinte forma:
As opções são:

1. Candidato Jair Rodrigues
2. Candidato Carlos Luz
3. Candidato Neves Rocha
4. Nulo
5. Branco

Entre com o seu voto:
O programa deverá ler os votos dos eleitores e, quando o número 6 for lido, apresentar as seguintes informações: a) O número de votos de cada candidato; b) A porcentagem de votos nulos; c) A porcentagem de votos brancos; d) O candidato vencedor.

## 12

Crie um jogo de adivinhação que deve ser jogado entre dois usuários. O primeiro usuário deve digitar três caracteres distintos.O segundo usuário deve digitar uma tecla na tentativa de acertar um dos três caracteres. Caso a tecla digitada esteja correta, imprima uma mensagem informando que ele acertou e quantos caracteres restam para ele acertar. Caso ele erre, imprima na tela e informe quantos caracteres restam e o número de tentativas restantes (o usuário só pode digitar no máximo 15 caracteres). O jogo termina quando o usuário acerta todos os caracteres ou quando não possui mais tentativas.

## 13

Usando apenas os comandos `printf("0")`, `printf("X")` e `printf("\n")` e usando laços aninhados, faça o seguinte aparecer na tela.

- xxxxx
- 0xxxx
- 00xxx
- 000xx
- 0000x
- 00000

## 14

Dados um número inteiro N, N>0, e uma sequência com N números inteiros maiores do que zero, determinar o fatorial de cada número da sequência.

## 15

Crie um programa que desenhe a diagonal principal e a diagonal secundária do quadrado (o tamanho do quadrado deve ser fornecido pelo usuário), como a seguir:

Exemplo do quadrado com tamanho 5 (5 linhas e 5 colunas).

```md
X   X
 X X
  X
 X X
X   X
```

## 16

Crie um algoritmo que simule o funcionamento de um caixa de supermercado. O caixa fica aberto até o fim do expediente e pode processar a compra de vários clientes.  Cada cliente pode comprar vários itens (1.Feijão - R$ 2.0, 2.Arroz - R$ 1.5, 3.Carne - R$ 10.0, 4. Tomate - R$ 3.0, 5. Cebola - R$ 2.5). Ao ler cada item deve ser exibida uma mensagem para o operador do caixa perguntando se há mais itens a serem processados. Ao final, exiba quanto a compra custou ao cliente. E então solicite do operador do caixa a informação se deseja fechar o caixa.  Quando o caixa for fechado, imprima quanto de dinheiro aquele caixa apurou no dia.
