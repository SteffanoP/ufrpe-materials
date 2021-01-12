#include <stdio.h>

#define TAM_MAX_NOME_ALUNOS 21

#define QTD_MAX_ALUNOS 5
#define QTD_MAX_INFO 4

int main() {
    char nome[QTD_MAX_ALUNOS][TAM_MAX_NOME_ALUNOS];
    float informacoes[QTD_MAX_ALUNOS][QTD_MAX_INFO], soma_notas = 0;
    int posicao_aluno_maior_nota;

    //Realiza a leitura de notas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        printf("Diga o nome do aluno %i\n", i+1);
        gets(nome[i]);
        
        printf("Diga o numero de matricula do aluno\n");
        scanf("%f",&informacoes[i][0]);
        getchar();
        
        printf("Diga sua media das provas\n");
        scanf("%f",&informacoes[i][1]);
        getchar();

        printf("Diga sua media dos trabalhos\n");
        scanf("%f",&informacoes[i][2]);
        getchar();

        informacoes[i][3] = informacoes[i][1]+informacoes[i][2];
    }

    //Separa a posição do aluno de maior nota
    for (int i = 1; i < QTD_MAX_ALUNOS; i++) {
        if (informacoes[i][3] > informacoes[i-1][3])
            posicao_aluno_maior_nota = i;
        else if (informacoes[i][3] < informacoes[i-1][3])
            posicao_aluno_maior_nota = i-1;
    }

    printf("O aluno %s de matricula %.0f, ",nome[posicao_aluno_maior_nota],informacoes[posicao_aluno_maior_nota][0]);
    printf("tirou a nota %.2f e ficou com a maior nota da sala\n",informacoes[posicao_aluno_maior_nota][3]);

    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
        soma_notas += informacoes[i][3];
    
    printf("A media das notas finais ficou em %.2f",(soma_notas/QTD_MAX_ALUNOS));
    
    return 0;
}