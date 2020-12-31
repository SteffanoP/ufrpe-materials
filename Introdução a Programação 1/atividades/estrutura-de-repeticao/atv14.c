/* Considere para essa questão o seguinte: dado um número n, destrinche suas fatoriais, ex: para n = 4, faça:
4! = 4. 3 . 2 . 1 = 24
3! = 3 . 2 . 1 = 6
2! = 2 . 1 = 2 
*/
#include <stdio.h>

int main() {
    int n;
    
    printf("Bem vindo a funcao vetorial!\n");
    printf("Aparentemente os matematicos estavam com preguica de calcular as fatoriais dos numeros\n");
    printf("Ou simplesmente de usarem a calculadora cientifica mesmo...\n");
    printf("Por favor diga o numero que voce deseja descobrir a fatorial\n");
    scanf("%i",&n);

    for (int a = n; a > 0; a--) {
        int fatorial = 1;
        printf("%i! = ", a);
        for (int i = a; i > 0; i--) {
            if (i != 1)
                printf("%i . ",i);
            else
                printf("%i",i);
            fatorial *= i;
        }
    
        printf(" = %i \n", fatorial);
    }
    return 0;
}
