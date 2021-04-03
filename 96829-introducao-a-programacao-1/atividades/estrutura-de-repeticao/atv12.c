#include <stdio.h>

int main() {
    char c1,c2,c3;
    int contador_acertos;
    
    do {
        printf("Jogador 1, por favor, digite seus caracteres na seguinte ordem: A B C\n");
        scanf("%c %c %c",&c1,&c2,&c3);
        getchar();
        if ((c1 == c2) || (c1 == c3) || (c2 == c3)) {
            printf("Jogador 1, eh necessario que os caracteres sejam distintos\n");
        }
    } while ((c1 == c2) || (c1 == c3) || (c2 == c3));

    for (int i = 0; i < 15; i++) {
        char c;

        printf("Jogador 2, tente advinhar algum caractere\n");
        scanf("%c",&c);
        getchar();

        if (c == c1) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c1,3-contador_acertos,14-i);
            c1 = NULL;


        } else if (c == c2) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c2,3-contador_acertos,14-i);
            c2 = NULL;

        } else if (c == c3) {
            contador_acertos += 1;
            printf("Parabe'ns voce acertou o caractere %c e ainda restam %i caracteres e %i de chances\n",c3,3-contador_acertos,14-i);
            c3 = NULL;
            
        } else {
            printf("Voce nao acertou nenhum caractere e ainda tem %i chances\n",14-i);
        }

        if (contador_acertos == 3)
            i = 15;
    }

    if (contador_acertos == 3) {
        printf("Parabe'ns voce ganhou o jogo\n");
    } else {
        printf("Infelizmente voce nao ganhou o jogo\n");
    }
    
    printf("fim");

    return 0;
}
