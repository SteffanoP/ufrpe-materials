#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_MAX_ALUNOS 5
#define QTD_MAX_PERGUNTAS 10

int main() {
    char resposta[QTD_MAX_ALUNOS][QTD_MAX_PERGUNTAS];
    char gabarito[QTD_MAX_PERGUNTAS] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b'};
    int resultado[QTD_MAX_ALUNOS];

    srand(time(NULL));

    //Zera os resultados
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        resultado[i] = 0;
    }


    //Aleatoriza a matriz de respostas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        for (int j = 0; j < QTD_MAX_PERGUNTAS; j++) {
            int aleatorio;
            aleatorio = rand() % 4;
            switch (aleatorio) {
            case 0:
                resposta[i][j] = 'a';
                break;
            case 1:
                resposta[i][j] = 'b';
                break;
            case 2:
                resposta[i][j] = 'c';
                break;
            case 3:
                resposta[i][j] = 'd';
                break;   
            default:
                break;
            }
        }
    }

    //Verifica as repostas
    for (int i = 0; i < QTD_MAX_ALUNOS; i++) {
        for (int j = 0; j < QTD_MAX_PERGUNTAS; j++) {
            if (resposta[i][j] == gabarito[j]) 
                resultado[i] += 1;
        }
    }
    
    //Mostra o resultado
    for (int i = 0; i < QTD_MAX_ALUNOS; i++)
        printf("O aluno %i tirou %i\n",i+1,resultado[i]);

    return 0;
}