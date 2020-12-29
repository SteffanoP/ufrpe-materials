#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 0;
    int soma_idade_excelente, qtd_pessoas_regular,qtd_pessoas_bom, qtd_pessoas_excelente;
    float media_idade_excelente, porcentagem_pessoas_bom;
    
    while (i < 10) {
        int idade, avaliacao;

        printf("Ola caro espectador, responda o seguinte questionario sobre o filme 'O Senhor dos Aneis' para ganhar um presente\n");
        printf("Primeiro, Qual a sua idade?\n");
        scanf("%i",&idade);
        printf("E agora me diga uma coisa: Qual a sua avaliacao para esse filme\n");
        printf("1. Excelente\n");
        printf("2. Bom\n");
        printf("3. Regular\n");
        scanf("%i",&avaliacao);
        
        
        switch (avaliacao) {
        case 1:
            soma_idade_excelente += idade;
            qtd_pessoas_excelente += 1;
            break;
        case 2:
            qtd_pessoas_bom += 1;        
            break;
        case 3:
            qtd_pessoas_regular += 1;
            break;
        
        default:
            break;
        }
        
        i += 1;
    }
    
    media_idade_excelente = (float)soma_idade_excelente/(float)qtd_pessoas_excelente;

    porcentagem_pessoas_bom = (float)qtd_pessoas_bom/10;

    printf("Relatorio do questionario\n");
    printf("A media das pessoas que responderam excelente: %2.f\n", media_idade_excelente);
    printf("A quantidade de pessoas que responderam regular: %i\n", qtd_pessoas_regular);
    printf("A porcentagem das pessoas que responderam bom: %2.f\n",(porcentagem_pessoas_bom*100));

    
    return 0;
}
