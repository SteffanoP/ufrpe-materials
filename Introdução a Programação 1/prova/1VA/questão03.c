#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vez;                                                                                                  // Controlar de quem é a proxima jogada
    int posicao_j1, posicao_j2;                                                                               // Armazena a posicao dos jogadores
    int vida_j1, vida_j2;                                                                                     // Armazena a vida dos jogadores
    int dado_j1, dado_j2;                                                                                     // Armazena o dado da jogada atual dos jogadores
    int tabuleiro[28] = {6, 0, 1, 2, 0, 4, 0, 3, 0, 1, 2, 5, 4, 0, 0, 1, 2, 0, 3, 0, 1, 2, 0, 4, 1, 3, 2, 7}; // Casas do tabuleiro
    char j1[21], j2[21];                                                                                      // Nome dos jogadores
    vida_j1 = 10;                                                                                             // Vida inicial dos jogadores
    vida_j2 = 10;
    posicao_j1 = 1; // Posicao inicial dos jogadores
    posicao_j2 = 1;

    printf("\t\t----- THE MAZE RUNNER - GAME VERSION -----"); // Regras
    printf("\n\n\n\tREGRAS:");
    printf("\n\n\tBRANCO - CASA NORMAL");
    printf("\n\tVERMELHO - JOGADOR PERDE 3 VIDAS");
    printf("\n\tVERDE - JOGADOR GANHA UMA VIDA SE TIVER MENOS QUE 10 VIDAS");
    printf("\n\tAMARELO - APRISIONA O JOGADOR POR UM TUNO SEM JOGAR");
    printf("\n\tAZUL - PERMITE QUE O JOGADOR JOGUE NOVAMENTE");
    printf("\n\tPRETO - JOGADOR VOLTA PARA O INCIO");

    printf("\n\n\n\t*** TABULEIRO ***"); // Impressao do tabuleiro
    printf("\n\n\t[INICIO] ");
    for (int i = 0; i < 28; i++)
    {
        if (tabuleiro[i] == 0)
        {
            printf("[BRANCO] ");
        }
        if (tabuleiro[i] == 1)
        {
            printf("[VERMELHO] ");
        }
        if (tabuleiro[i] == 2)
        {
            printf("[VERDE] ");
        }
        if (tabuleiro[i] == 3)
        {
            printf("[AMARELO] ");
        }
        if (tabuleiro[i] == 4)
        {
            printf("[AZUL] ");
        }
        if (tabuleiro[i] == 5)
        {
            printf("[PRETO] ");
        }
    }
    printf("[FIM]");
    printf("\n\n\tJOGADOR 1: "); // Pede o nome do jogador 1
    scanf("%s", j1);
    printf("\n\n\tJOGADOR 2: "); // Pede o nome do jogador 2
    scanf("%s", j2);

    printf("\n\n\t*** TABULEIRO ***\n\n\t"); // Tabuleiro no comeco do jogo
    for (int i = 0; i < 28; i++)
    {
        if (i == posicao_j1 - 1 && i == posicao_j2 - 1)
        {
            printf("[%s / %s] ", j1, j2);
        }
        else if (i == posicao_j1 - 1)
        {
            printf("[%s] ", j1);
        }
        else if (i == posicao_j2 - 1)
        {
            printf("[%s] ", j2);
        }
        else if (tabuleiro[i] == 6)
        {
            printf("[INICIO] ");
        }
        else if (tabuleiro[i] == 0)
        {
            printf("[BRANCO] ");
        }
        else if (tabuleiro[i] == 1)
        {
            printf("[VERMELHO] ");
        }
        else if (tabuleiro[i] == 2)
        {
            printf("[VERDE] ");
        }
        else if (tabuleiro[i] == 3)
        {
            printf("[AMARELO] ");
        }
        else if (tabuleiro[i] == 4)
        {
            printf("[AZUL] ");
        }
        else if (tabuleiro[i] == 5)
        {
            printf("[PRETO] ");
        }
        else if (tabuleiro[i] == 7)
        {
            printf("[FIM]");
        }
    }

    srand(time(NULL));

    do // Randomizacao dos dados iniciais
    {
        dado_j1 = 1 + rand() % 6;
        dado_j2 = 1 + rand() % 6;
    } while (dado_j1 == dado_j2);

    printf("\n\nO DADO DE %s EH: %i\nO DADO DE %s EH: %i", j1, dado_j1, j2, dado_j2);

    if (dado_j1 > dado_j2) // Jogador com o maior dado inicia o jogo
    {
        printf("\nQUEM COMECA EH: %s!", j1);
        vez = 1;
    }
    else
    {
        printf("\nQUEM COMECA EH: %s!", j2);
        vez = 2;
    }

    do
    {
        if (vez == 1)
        {
            printf("\n\n\nA VIDA DE %s EH: %i", j1, vida_j1); // Vida restante do jogador 1
            dado_j1 = 1 + rand() % 6;
            printf("\nO DADO DE %s EH: %i", j1, dado_j1); // Dado atual do jogador 1

            switch (dado_j1) // Atualizacao da posicao do jogador 1
            {
            case 1:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            case 2:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            case 3:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            case 4:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            case 5:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            case 6:
                posicao_j1 = posicao_j1 + dado_j1;
                break;
            default:
                break;
            }

            if (posicao_j1 > 28) // Para nao ultrapassar o limite de casas do tabuleiro
            {
                posicao_j1 = 28;
            }

            printf("\n\n%s ESTA NA POSICAO %i DO TABULEIRO.", j1, posicao_j1);
            // Acoes de cada casa do tabuleiro para o jogador 1
            if (posicao_j1 == 3 || posicao_j1 == 10 || posicao_j1 == 16 || posicao_j1 == 21 || posicao_j1 == 25)
            {
                vida_j1 = vida_j1 - 3;
                printf("\n\n%s PERDEU 3 VIDAS.", j1);
            }
            else if (posicao_j1 == 4 || posicao_j1 == 11 || posicao_j1 == 17 || posicao_j1 == 22 || posicao_j1 == 27)
            {
                if (vida_j1 < 10)
                {
                    vida_j1 = vida_j1 + 1;
                    printf("\n\n%s GANHOU 1 VIDA!", j1);
                }
            }
            else if (posicao_j1 == 8 || posicao_j1 == 19 || posicao_j1 == 26)
            {
                printf("\n\n%s ESTA APRISIONADO POR UMA RODADA.", j1);
            }
            else if (posicao_j1 == 6 || posicao_j1 == 13 || posicao_j1 == 24)
            {
                printf("\n\n%s JOGA OUTRA VEZ.", j1);
            }
            else if (posicao_j1 == 12)
            {
                posicao_j1 = 1;
                printf("\n\n%s VOLTOU PRO INICIO.", j1);
            }
        }

        else if (vez == 2)
        {
            printf("\n\n\nA VIDA DE %s EH: %i", j2, vida_j2); // Vida restante do jogador 2
            dado_j2 = 1 + rand() % 6;
            printf("\nO DADO DE %s EH: %i", j2, dado_j2); // Dado atual do jogador 2

            switch (dado_j2) // Atualizacao da posicao do jogador 2
            {
            case 1:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            case 2:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            case 3:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            case 4:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            case 5:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            case 6:
                posicao_j2 = posicao_j2 + dado_j2;
                break;
            default:
                break;
            }

            if (posicao_j2 > 28) // Para nao ultrapassar o limite de casas do tabuleiro
            {
                posicao_j2 = 28;
            }

            printf("\n\n%s ESTA NA POSICAO %i DO TABULEIRO.", j2, posicao_j2);
            // Acoes de cada casa do tabuleiro para o jogador 1
            if (posicao_j2 == 3 || posicao_j2 == 10 || posicao_j2 == 16 || posicao_j2 == 21 || posicao_j2 == 25)
            {
                vida_j2 = vida_j2 - 3;
                printf("\n\n%s PERDEU 3 VIDAS.", j2);
            }
            else if (posicao_j2 == 4 || posicao_j2 == 11 || posicao_j2 == 17 || posicao_j2 == 22 || posicao_j2 == 27)
            {
                if (vida_j2 < 10)
                {
                    vida_j2 = vida_j2 + 1;
                    printf("\n\n%s GANHOU UMA VIDA!", j2);
                }
            }
            else if (posicao_j2 == 8 || posicao_j2 == 19 || posicao_j2 == 26)
            {
                printf("\n\n%s ESTA APRISIONADO POR UMA RODADA.", j2);
            }
            else if (posicao_j2 == 6 || posicao_j2 == 13 || posicao_j2 == 24)
            {
                printf("\n\n%s JOGA OUTRA VEZ.", j2);
            }
            else if (posicao_j2 == 12)
            {
                posicao_j2 = 1;
                printf("\n\n%s VOLTOU PRO INICIO.", j2);
            }
        }
        else // Caso seja digitado um numero diferente de 1 ou 2 para a jogada
        {
            printf("\n\nPOR FAVOR DIGITE UM VALOR VALIDO!");
        }

        if (posicao_j1 >= 28)
        {
            posicao_j1 = 28;
        }
        if (posicao_j2 >= 28)
        {
            posicao_j2 = 28;
        }

        printf("\n\n\t*** TABULEIRO ***\n\n\t"); // Tabuleiro atualizado
        for (int i = 0; i < 28; i++)
        {
            if (i == posicao_j1 - 1 && i == posicao_j2 - 1)
            {
                printf("[%s / %s] ", j1, j2);
            }
            else if (i == posicao_j1 - 1)
            {
                printf("[%s] ", j1);
            }
            else if (i == posicao_j2 - 1)
            {
                printf("[%s] ", j2);
            }
            else if (tabuleiro[i] == 6)
            {
                printf("[INICIO] ");
            }
            else if (tabuleiro[i] == 0)
            {
                printf("[BRANCO] ");
            }
            else if (tabuleiro[i] == 1)
            {
                printf("[VERMELHO] ");
            }
            else if (tabuleiro[i] == 2)
            {
                printf("[VERDE] ");
            }
            else if (tabuleiro[i] == 3)
            {
                printf("[AMARELO] ");
            }
            else if (tabuleiro[i] == 4)
            {
                printf("[AZUL] ");
            }
            else if (tabuleiro[i] == 5)
            {
                printf("[PRETO] ");
            }
            else if (tabuleiro[i] == 7)
            {
                printf("[FIM]");
            }
        }

        if (posicao_j1 >= 28 || posicao_j2 >= 28 || vida_j1 <= 0 || vida_j2 <= 0) // Para nao pedir a vez
        {
            break;
        }

        printf("\n\nDE QUEM EH A VEZ? (1/2)\n"); // Pergunta de quem eh a proxima rodada
        scanf("%i", &vez);

    } while (posicao_j1 < 28 && posicao_j2 < 28 && vida_j1 > 0 && vida_j2 > 0);

    if (posicao_j1 >= 28 || vida_j2 == 0) // Imprime quem venceu
    {
        printf("\n\n\t\t%s EH O VENCEDOR!", j1);
    }
    else
    {
        printf("\n\n\t\t%s EH O VENCEDOR!", j2);
    }
    return 0;
}