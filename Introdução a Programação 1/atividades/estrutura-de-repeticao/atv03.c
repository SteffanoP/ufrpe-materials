#include <stdio.h>
#include <limits.h> // Para variável INT_MAX usada para calcular o menor salário possível

int main(int argc, char const *argv[]) {
    int qtd_habitantes;
    float soma_salario, soma_filhos, maior_salario = 0, menor_salario = INT_MAX, percentual_2filhos;

    printf("Bem vindo a pesquisa de Dezembro/2020\n");
    printf("Diga o numero de habitantes que voce deseja cadastrar nessa pesquisa\n");
    scanf("%i",&qtd_habitantes);
    getchar();


    for (int i = 0; i < qtd_habitantes; i++) {
        int filhos;
        float salario;

        printf("Passe os dados do habitante n %i de %i\n",i+1,qtd_habitantes);
        printf("Primeiro a renda familiar\n");
        scanf("%f",&salario);
        printf("E agora quantidade de filhos\n");
        scanf("%i",&filhos);

        soma_salario += salario;
        soma_filhos += filhos;

        if (salario > maior_salario)
            maior_salario = salario;

        if (salario < menor_salario)
            menor_salario = salario;
        
        if (filhos > 2) 
            percentual_2filhos += 1;
        
    }
    
    percentual_2filhos = percentual_2filhos/((float)qtd_habitantes);

    printf("Em lista o que a prefeitura quer saber eh:\n");
    printf("1. A media salarial da populacao: %.2f\n",(soma_salario/qtd_habitantes));
    printf("2. A media do numero de filhos: %2.f\n",(soma_filhos/qtd_habitantes));
    printf("3. O maior salario: %.2f e o menor salario: %.2f\n", maior_salario, menor_salario);
    printf("4. Percentual de habitantes com mais de 2 filhos: %.2f%%",(percentual_2filhos*100));

    return 0;
}
