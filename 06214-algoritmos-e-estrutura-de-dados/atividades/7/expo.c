/**
 * Usando a estratégia de divisão e conquista, podemos calcular a 
 * exponenciação k^n (dados inteiros k e n) de forma mais eficiente 
 * do que fazer n - 1 multiplicações (ou seja, através de um laço que 
 * calcula `k*k*k ...`). A idea geral é: para calcular k^n, calculamos 
 * primeiro k^{n / 2} e usamos esse valor. Implemente um algoritmo 
 * recursivo que usa essa ideia.
 **/
#include <stdio.h>

int expo_recursivo(int k, int n) 
{
    if (n == 1)
        return k;
    
    int resultado;
    if (n % 2 == 0)
    {
        resultado = expo_recursivo(k, n/2) * expo_recursivo(k, n/2);
    }
    else
    {
        resultado = expo_recursivo(k, n/2) * expo_recursivo(k, (n/2) + 1);
    }
    return resultado;
}

int expo(int k, int n) {
    int result = 1;
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
            result *= k;
    }
    
    return result;
}

int main()
{
    printf("%d\n", expo_recursivo(5, 3));
    return 0;
}
