#include <stdio.h>
#include <float.h>

int main(int argc, char const *argv[]) {
    int contador_numero = 0, qtd_numeros;
    float i;
    float numero[100];
    float soma_numeros, media_numeros, maior_numero = 0, menor_numero = FLT_MAX, media_pares, soma_pares, qtd_pares;

    do  {
        printf("Manda teus numeros\n");
        scanf("%f",&i);
        getchar();
        
        if (i == 0)
            break;

        numero[contador_numero] = i;

        soma_numeros += numero[contador_numero];
        qtd_numeros = contador_numero + 1;

        if (numero[contador_numero] > maior_numero)
            maior_numero = numero[contador_numero];
        
        if (numero[contador_numero] < menor_numero)
            menor_numero = numero[contador_numero];

        if (((int)numero[contador_numero] % 2) == 0) {
            soma_pares += numero[contador_numero];
            qtd_pares += 1;
        }

        contador_numero += 1;
    } while (i > 0);

    media_numeros = soma_numeros/(float)qtd_numeros;
    media_pares = soma_pares/qtd_pares;

    printf("1. A soma dos numeros digitados: %.2f\n",soma_numeros);
    printf("2. A quantidade de numeros digitados: %i\n",qtd_numeros);
    printf("3. A media de numeros digitados: %.2f\n",media_numeros);
    printf("4. O maior numero digitado: %.2f\n",maior_numero);
    printf("5. O menor numero digitado: %.2f\n",menor_numero);
    printf("6. A media de numeros pares digitados: %.2f\n",media_pares);
    

    return 0;
}
