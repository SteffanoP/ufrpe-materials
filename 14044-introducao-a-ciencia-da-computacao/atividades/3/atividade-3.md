# Atividade 3 - Operação Binária e Representação Númerica

## Aluno: Steffano Xavier Pereira

### 1) Encontre a sequência binária que representa a sua Idade e chame de _**I**_. Por exemplo, se a sua idade for 80 anos, a sequência binária será `I = 10100000`. Importante: forneça o passo a passo para obter a sequência resultante

Minha idade atualmente é de 21 anos, podemos separar esse valor da seguinte forma:

```m
21 = 2^4 + 2^2 + 1
```

Logo podemos montar nossa representação binária de acordo com a tabela

| 2^4 | 2^3 | 2^2 | 2^1 | 2^0 |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  1  |  0  |  1  |

Dessa forma a minha idade é `10101`.

### 2) Com base na sequência I obtida, realize as seguintes operações em binário

1. I + 1101;

    ```m
     10101
     +1101
     -----
    100010
    ```

2. I - 1010;

    ```m
    10101
    -1010
    -----
     1011
    ```

3. I x 111;

    ```m
       10101
       x 111
       -----
       10101
    + 10101
     10101
    --------
    10010011
    ```

### 3) Faça a subtração da sua idade pelo número 97 e represente o valor inteiro obtido em notação de complemento de 2

Realizando a subtração temos o seguinte:

```m
21 - 97 = -76
```

Transformando o valor para binário temos:

```m
76 = 2^6 + 2^3 + 2^2
```

| 2^6 | 2^5 | 2^4 | 2^3 | 2^2 | 2^1 | 2^0 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|  1  |  0  |  0  |  1  |  1  |  0  |  0  |

Para transformar para o valor negativo iremos aplicar o método da notação de complemento de 2:

```m
 76 = 1001100;
      0110011
           +1
      -------
-76 = 0110100
```

Logo, nosso resultado será `0110100`

### 4) Divida a sua idade por 97 e represente o valor obtido usando o padrão IEEE 754

Inicialmente fazemos o cálculo do valor resultante:

```m
21 / 97 ≃ 0.22
```

Agora devemos passar para sua versão normalizada:

```m
0.22 = 0,001110001

0,001110001 = 1,110001 * 2^-3
```

Aplicando o Padrão IEEE 754

|  Sinal | Expoente | Mantissa  |
|:------:|:--------:|:---------:|
|Positivo|`-3 + 127`|11000100...|
|    0   | 1111100  |11000100...|

Logo, teremos o seguinte resultado no padrão IEEE 754:

```m
0.22 = 0 1111100 110001 00000000000000000

0.22 = 0111110011000100000000000000000
```
