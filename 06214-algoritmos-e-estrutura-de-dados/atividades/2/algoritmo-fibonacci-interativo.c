#include <stdio.h>

/**
 * A função fib calcula o número da ordem de fibonacci do qual você deseja
 * descobrir. O algoritmo funciona num formato iterativo, do qual a função
 * é iterada por um loop, nesse caso um for, que se inicia desde o primeiro
 * valor da sequência e vai somando seu anterior com o próximo número até
 * chegar na ordem requisitado.
 * 
 * @param n A ordem do número na sequência de fibonacci, a primeira ordem é n = 0
 * @return O valor da sequência de fibonacci
 **/
unsigned long fib(int n) 
{
    unsigned long numero_anterior = -1, numero_atual = 1, numero_fibonacci;

    for (int i = 0; i < n; i++)
    {
        numero_fibonacci = numero_anterior + numero_atual;
        numero_anterior = numero_atual;
        numero_atual = numero_fibonacci;
    }

    return numero_fibonacci;
}

unsigned long fib_nop(int n, unsigned long *nop)
{
    int numero_anterior = -1, numero_atual = 1, numero_fibonacci;

    for (int i = 0; i < n; i++)
    {
        *nop += 1;
        numero_fibonacci = numero_anterior + numero_atual;
        numero_anterior = numero_atual;
        numero_atual = numero_fibonacci;
    }

    return numero_fibonacci;
}

int main(int argc, char const *argv[])
{
    unsigned int ordem_fibonacci;
    unsigned long nop = 0;
    printf("Por favor me diga a ordem do numero da sequencia de fibonacci que voce deseja descobrir\n");
    scanf("%d", &ordem_fibonacci);

    printf("O numero de sequencia %d na ordem em fibonacci eh %ld\n", ordem_fibonacci, fib_nop(ordem_fibonacci, &nop));
    printf("e o numero de operacoes foram %ld", nop);

    return 0;
}
