#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMPO_VISUALIZACAO 5
#define CARTA_ESCOLHIDA 2
#define PARES_ACERTADOS 8

int main()
{
    srand(time(NULL));

    int player = 1, timer = TEMPO_VISUALIZACAO;
    int pont1 = 0, pont2 = 0;
    int valor_acerto[PARES_ACERTADOS], numero[CARTA_ESCOLHIDA]; //Vetor para armazenar os 'valor_acerto' e o outro as 'cartas' escolhidas pelo jogador
    char carta;
    //Mostrar na telas os pares do jogo por 5seg e depois esconde-los para adivinhar
    do
    {
        system("cls"); //Essa funcao esta na biblioteca <stdli.h> e serve para limpar informaçoes na tela
        printf("\n** Memorize os numeros abaixo em %i **\n\n", timer);
        timer--;

        printf("(3)(1)(5)(2)\n");
        printf("(7)(4)(1)(3)\n");
        printf("(4)(6)(6)(7)\n");
        printf("(8)(2)(8)(5)");

        _sleep(1000); //Corresponde a esperar 1seg para voltar pro loop
    } while (timer > 0);

    system("cls");

    while (pont1 < 4 && pont2 < 4)
    {
        printf("(A)(B)(C)(D)\n");
        printf("(E)(F)(G)(H)\n");
        printf("(I)(J)(K)(L)\n");
        printf("(M)(N)(O)(P)\n");

        for (int b = 0; b < 2; b++)
        {
            printf("\nJogador %i, escolha a carta %i: ", player, b);
            scanf("%c", &carta);
            getchar();

            int carta_valida = 0; //Verificador de que a carta selecionada realmente faz parte do tabuleiro

            switch (carta)
            {
            case 'A':
                numero[b] = 3;
                break;
            case 'B':
                numero[b] = 1;
                break;
            case 'C':
                numero[b] = 5;
                break;
            case 'D':
                numero[b] = 2;
                break;
            case 'E':
                numero[b] = 7;
                break;
            case 'F':
                numero[b] = 4;
                break;
            case 'G':
                numero[b] = 1;
                break;
            case 'H':
                numero[b] = 3;
                break;
            case 'I':
                numero[b] = 4;
                break;
            case 'J':
                numero[b] = 6;
                break;
            case 'K':
                numero[b] = 6;
                break;
            case 'L':
                numero[b] = 7;
                break;
            case 'M':
                numero[b] = 8;
                break;
            case 'N':
                numero[b] = 2;
                break;
            case 'O':
                numero[b] = 8;
                break;
            case 'P':
                numero[b] = 5;
                break;
            default:
                printf("Esta carta nao faz parte do tabuleiro. Por favor, escolha outra.\n");
                carta_valida = 1;
                break;
            }
            if (carta_valida != 1)
            {
                printf("%i", numero[b]); //Mostra a carta escolhida pelo jogador
            }
            else
            {
                carta_valida = 0;
                b -= 1; //Isso faz 'b' voltar a ser 0, ou seja, reseta para a primeira posicao do 'for'
            }
        }

        int x = 0;
        if (numero[0] == numero[1])
        {
            for (int c = 0; c < 8; c++)
            {
                if (valor_acerto[c] == numero[1])
                {
                    x = 1;
                }
            }

            if (x != 1)
            {
                int i = 0;

                if (player == 1)
                {
                    pont1 += 1;
                    printf("\nVoce acertou! Pontuacao: %i\n\n", pont1);

                    if (i == 0)
                    {
                        valor_acerto[i] = numero[0];
                        i += 1;
                    }
                    if (i == 1)
                    {
                        valor_acerto[i] = numero[1];
                    }

                    if (pont1 >= 1 && pont1 < 4) //Garante que o jogador vencedor realmente apareça como o vencedor no final do jogo e nao o que estah na vez, caso o jogo tivesse continuado
                    {
                        player += 1;
                    }
                }

                else
                { //**PLAYER 2**//
                    pont2 += 1;
                    valor_acerto[1] = numero[1];
                    printf("\nVoce acertou! Pontuacao: %i\n\n", pont2);
                    i++;

                    if (pont1 >= 1 && pont1 < 4)
                    {
                        player -= 1;
                    }
                }
            }
            else
            {
                x = 0;
                printf("\nCarta ja foi acertada, tente novamente.\n");
            }
        }
        else
        {
            printf("\nErrou, vez do outro jogador\n");
            if (player == 1)
            {
                player += 1;
            }
            else
            {
                player -= 1;
            }
        }
    }

    if (pont1 == 4 || pont2 == 4)
    {
        printf("\nJogador %i venceu. Com %i pontos\n", player, pont1);
    }
    if (pont1 == 4 && pont2 == 4)
    {
        printf("\nEmpate.\n");
    }
    return 0;
}