# Atividade 8 - Algoritmos e Linguagem de Programação

## Aluno: Steffano Xavier Pereira

### 1) Baseado no programa Java anterior, faça um novo programa, chamado TesteEco2, que possua as seguintes características

- Utilize no início do programa 2 palavras ao invés de uma: um nome e um sobrenome
- Fala um eco das duas palavras:
  - Para a 1ª palavra deve repetir a última letra 3 vezes
  - Para a segunda palavra (sobrenome) deve repetir a última letra 5 vezes

O seu relatório deve conter o texto da classe Java que produz o resultado acima.

```java
import java.util.ArrayList;
import java.util.List;

public class TesteEco2 {
  public static void main(String[] args) {
    String nome = args[0];
    char ultimaLetraNome = nome.charAt(nome.length() - 1);
    String sobrenome = args[1];
    char ultimaLetraSobrenome = sobrenome.charAt(sobrenome.length() - 1);
    
    List<Object> roteiro = new ArrayList<>();
    roteiro.add(nome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(ultimaLetraNome);
    roteiro.add(" ");
    roteiro.add(sobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.add(ultimaLetraSobrenome);
    roteiro.forEach(System.out::print);
  }
}
```

---

### 2) Execute o programa de números primos para números cada vez maiores

- Informe a partir de qual número a resposta deixou de ser instantânea.

A partir do número **104729**.

- Qual o tempo necessário no seu computador para determinar se “n = 2147483647” é primo?

Cerca de 21 segundos.

- Pesquise sobre o número M82589933, como foi descoberto e a importância.

O Número M82589933 possuí 24.862.048 digitos e é um milhão e meio maior do que seu antecessor. Esse primo foi encontrado no dia 7 de Dezembro de 2018. O pesquisador Mike James, dá uma ideia do porquê tais números são tão importantes:

> Não existe um uso prático para os números primos de Mersenne ou primos de tamanhos tão grande. Eles são muito grandes para criptografia e a maior parte da teoria de números não requer exemplos de valores numéricos de tamanha magnitude.

O Voluntário responsável por encontrar o **M82589933** é Patrick Laroche de 35 anos que é profissional de TI que encontrou o número com o setup de Stress Test. Durante 4 meses caçando o novo número primo, ele foi capaz de encontrar o novo número primo na sua 4ª tentativa; para ter uma ideia da sorte do indivíduo, há participantes que procuram por tais números durante 20 anos e já realizaram cerca de dezenas de milhares tentativas sem sucesso.
