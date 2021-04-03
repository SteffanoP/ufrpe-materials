#include <stdio.h>

#define QTD_MAXIMA_POSICOES 1000

int main() {
    int vetor[QTD_MAXIMA_POSICOES], posicao = 0;

    printf("Ola' usua'rio, digite nu'meros indefinidamente\n");
    printf("No intervalo de 5 'a 200 e eu te darei me'dia, mediana, quantidade de pares e i'mpares\n");
    printf("Logo digite de 1 em 1 os valores\n");
    printf("Para finalizar digite o valor '-1' e eu irei te dar as estati'sticas\n");

    do {
        int numero_lido;
        printf("Diga seu %i nu'mero\n",posicao+1);
        scanf("%i",&numero_lido);
        getchar();

        if ((numero_lido >= 5) && (numero_lido <= 200)) {
            vetor[posicao] = numero_lido;
            posicao += 1;
            printf("Nu'mero registrado!\n");
        } else if (numero_lido == -1) {
            printf("Cadastro de nu'meros finalizado!\n");
            posicao -= 1; /*Pois, como não há um novo número, 
                           *não há necessidade de reservar uma nova posição*/
            break;
        } else {
            printf("Nu'mero inva'lido!\n");
        }
        
    } while (1);
    
    int tamanho = posicao + 1;

    for (int i = 0; i < tamanho; i++) { //Para ver os valores cadastrados
        printf("%i \n", vetor[i]);
    }

    int soma_numeros = 0;
    float media;
    
    for (int i = 0; i < tamanho; i++) { //Calculo Média
        soma_numeros += vetor[i];
    }
    media = (float)soma_numeros/(float)tamanho;
    printf("A Me'dia dos nu'meros e' %.2f\n",media);
    
    //Para calcular a mediana é necessário por os números em ordem crescente, logo:
    int vetor_ordem_crescente[tamanho];
    float mediana;

    for (int i = 0; i < tamanho; i++) //Faz a cópia dos valores em vetor e põe em vetor_ordem_crescente
        vetor_ordem_crescente[i] = vetor[i];
    
    //Ordena os valores de vetor_ordem_crescente
    for (int i = 0; i < tamanho; i++) { 
        for (int j = 0; j < tamanho; j++) {
            if (vetor_ordem_crescente[i] < vetor_ordem_crescente[j]) {
                int buffer;
                buffer = vetor_ordem_crescente[i];
                vetor_ordem_crescente[i] = vetor_ordem_crescente[j];
                vetor_ordem_crescente[j] = buffer;
            }   
        }
    }

    if ((tamanho % 2) == 0) { //Função que obtém o valor central da ordem crescente, que neste caso, se trata da mediana
        mediana = (float)(vetor_ordem_crescente[(tamanho/2)-1]+vetor_ordem_crescente[tamanho/2])/2;
    } else {
        mediana = (vetor_ordem_crescente[tamanho/2]);
    }
    printf("A mediana e' %.2f\n",mediana);
    
    //Cálculo da quantidade de ímpares e pares
    int qtd_pares = 0, qtd_impares = 0;
    for (int i = 0; i < tamanho; i++) {
        if ((vetor[i] % 2) == 0) {
            qtd_pares +=1;
        } else {
            qtd_impares +=1;
        }
    }

    printf("O nu'mero de i'mpares e' %i e pares e' %i\n",qtd_impares,qtd_pares);    

    return 0;
}