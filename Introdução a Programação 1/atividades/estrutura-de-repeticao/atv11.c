#include <stdio.h>

int main(int argc, char const *argv[]) {
    int votos[5], total_votos, candidato_ganhador;

    for (int i = 0; i <= 5; i++) {
        votos[i] = 0;
    }
    
    
    unsigned int opcao;
    do {
        printf("Vote nos seguintes candidatos:\n");
        printf("1. Candidato Jair Rodrigues\n");
        printf("2. Candidato Carlos Luz\n");
        printf("3. Candidato Neves Rocha\n");
        printf("4. Nulo\n");
        printf("5. Branco\n");
        scanf("%i", &opcao);
        getchar();

        if (opcao <= 5) 
            votos[opcao] += 1;
        else 
            printf("Opcao invalida");

    } while (opcao != 6);

    printf("A) Total de votos:\n");
    printf("Candidato Jair Rodrigues: %i votos\n", votos[1]);
    printf("Candidato Carlos Luz: %i votos\n", votos[2]);
    printf("Candidato Neves Rocha: %i votos\n", votos[3]);

    for (int i = 1; i <= 5; i++)
        total_votos += votos[i];

    printf("B) Votos Nulos: %.2f votos\n%%",((float)votos[4]/(float)total_votos)*100);
    printf("C) Votos Brancos: %.2f votos\n%%",((float)votos[5]/(float)total_votos)*100);

    for (int i = 2; i <= 3; i++) {
        if (votos[i - 1] > votos[i])
            candidato_ganhador = i - 1;
        else if (votos[i - 1] < votos[i])
            candidato_ganhador = i;
    }

    printf("D) O candidato vencedor eh: O Candidato %i\n",candidato_ganhador);

    return 0;
}