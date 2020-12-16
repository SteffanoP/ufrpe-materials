/*A nota final de um estudante é calculada a partir da média de três notas atribuídas entre o intervalo de 0 até 10, respectivamente, a um trabalho de laboratório, a uma avaliação semestral e a um exame final. De acordo com o resultado, mostre na tela se o aluno está reprovado (média <= 4), de recuperação (4 <= media < 7) ou se foi aprovado (media >= 7). Se o aluno for para a recuperação, leia a sua nota na recuperação, e verifique se a média desta nota com a nota final é maior ou igual a 5. Se for, imprima que o mesmo está aprovado na recuperação, caso contrário imprima que o mesmo está reprovado.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float trabalho, avaliacao, final;
    float media;

    printf("Diga suas notas de trabalho de laboratorio, avaliacao semestral e exame final na ordem: NN NN NN\n");
    scanf("%f %f %f",&trabalho, &avaliacao, &final);

    media = (trabalho + avaliacao + final)/3;

    if (media >= 7) {
        printf("Parabe'ns voce foi aprovado");
    } else if (media >= 4){
        float recuperacao, media_recuperacao;
        printf("Voce foi para a recuperacao, diga sua nota na mesma\n");
        scanf("%f",&recuperacao);

        media_recuperacao = (final+recuperacao)/2;

        if (media_recuperacao >= 5)
            printf("Voce foi aprovado na recuperacao");
        else 
            printf("Voce nao conseguiu passar na recuperacao");
    } else 
        printf("Voce foi reprovado");
    
    return 0;
}
