#include <stdio.h>

/**
 * A função fib calcula o número da ordem de fibonacci do qual você deseja
 * descobrir. O algoritmo funciona num formato recursivo, do qual a função
 * pergunta a si mesma de forma recursiva até o momento que a devida condição
 * é aceita e a função responde a si mesma até chegar na ordem apresentada
 * inicialmente.
 * 
 * @param n A ordem do número na sequência de fibonacci, a primeira ordem é n = 0
 * @return O valor da sequência de fibonacci
 **/
unsigned long fib(int n) 
{
    if ((n == 0) || (n == 1))
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

/**
 * A função fib calcula o número da ordem de fibonacci do qual você deseja
 * descobrir. O algoritmo funciona num formato recursivo, do qual a função
 * pergunta a si mesma de forma recursiva até o momento que a devida condição
 * é aceita e a função responde a si mesma até chegar na ordem apresentada
 * inicialmente.
 * 
 * Para essa aplicação específica estamos calculando o Número de Operações
 * (aka Number of Operations,NoP); logo a função coleta o endereço de um vetor
 * para que a mesma não fique dependente de uma variável global apenas para
 * essa operação.
 * 
 * @param n corresponde a ordem do número na sequência de fibonacci, a primeira
 * ordem é n = 0.
 * @param *nop corresponde ao ponteiro da variável NOP que irá armazenar o
 * número de operações.
 * @return O valor da sequência de fibonacci.
 **/
unsigned long fib_nop(int n, long *nop) 
{
    *nop = *nop + 1;
    if ((n == 0) || (n == 1))
    {
        return n;
    }
    return fib_nop(n - 1, &*nop) + fib_nop(n - 2, &*nop);
}

int main(int argc, char const *argv[])
{
    //Cálculo do valor de fibonacci
    unsigned int ordem;
    unsigned long nop = 0;
    printf("Por favor me diga a ordem do numero da sequencia de fibonacci que voce deseja descobrir\n");
    scanf("%d",&ordem);
    scanf("%c");
    printf("O numero de fibonacci eh %d\n",fib(ordem - 1));

    //Cálculo de eficiência NoP
    char selecao;
    printf("Deseja saber o numero de operacoes realizada pela funcao fib?(Y/N)");
    scanf("%c",&selecao);
    if (selecao == 'Y')
    {
        fib_nop(ordem - 1, &nop);
        printf("\nO numero de operacoes foi %d", nop);
    }

    return 0;
}
