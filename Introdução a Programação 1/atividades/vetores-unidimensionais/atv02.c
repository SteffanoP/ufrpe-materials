#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long ler_apenas_se_for_inteiro();

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    
    int tam;
    
    do {
        printf("Por favor digite um nu'mero inteiro positivo!\n");
        tam = ler_apenas_se_for_inteiro();
    } while (tam <= 0);

    int numeros[tam];
    int numeros_quadrado[tam];
    for (int i = 0; i < tam; i++) {
        numeros[i] = rand() % 100;
        numeros_quadrado[i] = numeros[i]*numeros[i];
        printf("%i\n",numeros_quadrado[i]);
    }
    
    return 0;
}

long ler_apenas_se_for_inteiro() { //Solução para aceitar apenas números inteiros e NEGAR caracteres não númericos
    char buffer_de_entrada[64];
    char *onde_a_funcao_de_conversao_parou;

    while (1) {
        fgets(buffer_de_entrada, 64, stdin);
        long numero_lido = strtol(buffer_de_entrada, &onde_a_funcao_de_conversao_parou, 0); //Dica: Veja a referência da função strtol();

        /* Se o número resultante é zero e o ponteiro que aponta para o caractere da string
         * no final da conversão não andou é porque não ocorreu conversão, ou seja, falhou. Além disso, o caractere onde a conversão parou
         * tem que ser uma quebra de linha, caso contrário há caracteres não numéricos
         * que foram ignorados pelo strtol, o que significa que a entrada 
         * não possui somente números.
         * Créditos: Pablo Almeida
         */
        if ((numero_lido == 0 && onde_a_funcao_de_conversao_parou == buffer_de_entrada) || *onde_a_funcao_de_conversao_parou != '\n') {
            printf("Nu'mero inva'lido. Digite novamente.\n");
            continue;
        } else {
            return numero_lido;
        }
    }
}