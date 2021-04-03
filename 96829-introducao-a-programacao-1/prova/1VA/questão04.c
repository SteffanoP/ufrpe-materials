#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAM_MAX_TABULEIRO 10 //10x10

#define QTD_MAX_ARVORES 7 //7
#define QTD_MAX_BALAS 4 //4
#define QTD_MAX_CARROS 4 //4
#define QTD_MAX_PREDAS 8 //8
#define QTD_MAX_RICKS 1 //1
#define QTD_MAX_SAIDAS 1 //1
#define QTD_MAX_ZUMBIS 15 //15

#define DISTANCIA_PERSEGUICAO 3 //3 m²

int main() {
    char tabuleiro[TAM_MAX_TABULEIRO][TAM_MAX_TABULEIRO];
    unsigned int pos_rick[2];
    int jogo = 1;
    /* jogo = 0, nada
     * jogo = 1, representa que Rick ainda está no jogo,
     * jogo = 2, representa que Rick foi morto e o jogador perdeu 
     * jogo = 3, representa que Rick saiu vivo e o jogador ganhou
     * jogo = 4, representa que o jogador abandonou Rick e saiu do jogo 
    */
    int qtd_balas = 0;

    srand(time(NULL));

    //Esvaziando o tabuleiro
    for (int linha = 0; linha < TAM_MAX_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_MAX_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = ' ';
        }
    }
    
    //Randomização das Árvores
    for (int a = 0; a < QTD_MAX_ARVORES; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);

        } while (tabuleiro[pos_linha][pos_coluna] != ' ');  //32 = ' '
        tabuleiro[pos_linha][pos_coluna] = 'A'; 
    }

    //Randomização das Balas
    for (int a = 0; a < QTD_MAX_BALAS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra A, logo deve ser < 66
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 66));  //O numero 66 corresponde ao valos Decimal
        tabuleiro[pos_linha][pos_coluna] = 'B';                                                         //Ver tabela ASCII
    }
    
    //Randomização dos Carros
    for (int a = 0; a < QTD_MAX_CARROS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra A, logo deve ser <= 67
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 67));  
        tabuleiro[pos_linha][pos_coluna] = 'C';                                                         
    }
    
    //Randomização das Pedras
    for (int a = 0; a < QTD_MAX_PREDAS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra B, logo deve ser <= 80
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 80));  //O numero 66 corresponde ao valos Decimal
        tabuleiro[pos_linha][pos_coluna] = 'P';                                                         //Ver tabela ASCII
    }
    
    //Randomização do Nascimento de Rick
    for (int a = 0; a < QTD_MAX_RICKS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra P, logo deve ser <= 82
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 82)); 
        tabuleiro[pos_linha][pos_coluna] = 'R'; 
        pos_rick[0] = pos_linha;
        pos_rick[1] = pos_coluna;
    }

    //Randomização da Saída
    for (int a = 0; a < QTD_MAX_SAIDAS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra R, logo deve ser <= 83
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 83));  //O numero 66 corresponde ao valos Decimal
        tabuleiro[pos_linha][pos_coluna] = 'S';                                                         //Ver tabela ASCII
    }

    //Randomização de Zumbi
    for (int a = 0; a < QTD_MAX_ZUMBIS; a++) {
        int pos_linha, pos_coluna;
        do {
            pos_linha = rand() % (TAM_MAX_TABULEIRO - 1);
            pos_coluna = rand() % (TAM_MAX_TABULEIRO - 1);
            //Para não sobrepor, caso a randomização pegue a posição da letra S, logo deve ser < 90
        } while ((tabuleiro[pos_linha][pos_coluna] != 32) && (tabuleiro[pos_linha][pos_coluna] <= 90));  //O numero 66 corresponde ao valos Decimal
        tabuleiro[pos_linha][pos_coluna] = 'Z';                                                         //Ver tabela ASCII
    }

    //Inicia o jogo
    while (jogo == 1) {
        
        unsigned char uchTecla;

        //Constrói Tabuleiro Inicial
        printf("     ");
        for (int i = 0; i < TAM_MAX_TABULEIRO; i++) {
            printf("%i   ",i+1); //Número da coluna + Espaçamento dos números das colunas
        }
        printf("\n");
        for (int linha = 0; linha < TAM_MAX_TABULEIRO; linha++) {
            printf("%2i ", linha+1); //Enumera as linhas
            printf("|"); //Constrói primeiro traço(|) do tabuleiro
            for (int coluna = 0; coluna < TAM_MAX_TABULEIRO; coluna++) {
                printf(" %c |",tabuleiro[linha][coluna]); //Realiza o print do dado
            }
            printf("\n");
        }
        printf("Quantidade de balas: %i\n",qtd_balas);

        //Lê o movimento do jogador
        int buff_movimento[2];
        do {
            uchTecla = getch();

            //Movimentação do Rick
            buff_movimento[0] = pos_rick[0]; //Linha
            buff_movimento[1] = pos_rick[1]; //Coluna

            switch (uchTecla) {
            case 72: pos_rick[0] -= 1; break;
            case 75: pos_rick[1] -= 1; break;
            case 77: pos_rick[1] += 1; break;
            case 80: pos_rick[0] += 1; break;
            default: break;
            }

        } while (!((uchTecla == 72) || (uchTecla == 75) || (uchTecla == 77) || (uchTecla == 80) || (uchTecla == 0x1b)));

        //Caso o jogador dê ragequit
        if (uchTecla == 0x1b) {
            jogo = 4;
            break;
        }

        //Condição de movimentação de Rick
        if ((pos_rick[0] < TAM_MAX_TABULEIRO) && (pos_rick[1] < TAM_MAX_TABULEIRO)) {
            if (tabuleiro[pos_rick[0]][pos_rick[1]] == 32) { //Quando Movimenta para espaço vazio
                tabuleiro[buff_movimento[0]][buff_movimento[1]] = 32; //32 = ' ' //Excluí rastro do Rick
                tabuleiro[pos_rick[0]][pos_rick[1]] = 'R'; //Movimenta o Rick

            } else if (tabuleiro[pos_rick[0]][pos_rick[1]] == 'S') { //Quando Movimenta para a saída
                jogo = 3; //Rick deu o delta C:
                break;

            } else if (tabuleiro[pos_rick[0]][pos_rick[1]] == 'B') { //Quando Movimenta para uma bala
                tabuleiro[buff_movimento[0]][buff_movimento[1]] = 32; //32 = ' ' //Excluí rastro do Rick
                tabuleiro[pos_rick[0]][pos_rick[1]] = 'R';            //Movimenta o Rick
                qtd_balas += 1;

            } else if (tabuleiro[pos_rick[0]][pos_rick[1]] == 'Z') { //Quando Movimenta para um Zumbi
                if (qtd_balas > 0) {
                    tabuleiro[buff_movimento[0]][buff_movimento[1]] = 32; //32 = ' ' //Excluí rastro do Rick
                    tabuleiro[pos_rick[0]][pos_rick[1]] = 'R';            //Movimenta o Rick
                    qtd_balas -= 1;

                } else  if (qtd_balas == 0) {
                    jogo = 2; //Rick Morre ;-;
                    break;
                }
            } else {
                pos_rick[0] = buff_movimento[0];
                pos_rick[1] = buff_movimento[1];
            }
        } else {
            pos_rick[0] = buff_movimento[0];
            pos_rick[1] = buff_movimento[1];
        }

        //Movimentação dos Zumbis
        for (int i = 1; i < DISTANCIA_PERSEGUICAO+1; i++) {
            //Próximos a Esquerda de Rick
            if ((pos_rick[0]) < TAM_MAX_TABULEIRO && (pos_rick[1] - i) < TAM_MAX_TABULEIRO) {
                if (tabuleiro[buff_movimento[0]][buff_movimento[1]-i] == 'Z') {
                    if ((tabuleiro[pos_rick[0]][pos_rick[1] - i] == 32) || (tabuleiro[pos_rick[0]][pos_rick[1] - i] == 'R')) {
                        if (uchTecla != 75) {                                                           //32 = ' ' //80 = movimento para esquerda
                            tabuleiro[buff_movimento[0]][buff_movimento[1] - i] = 32; //32 = ' ' //Excluí rastro do Rick
                            tabuleiro[pos_rick[0]][pos_rick[1] - i] = 'Z';            //Movimenta o Zumbi
                        }
                    }
                }
            }
        
            //Próximos a Direita de Rick
            if ((pos_rick[0]) < TAM_MAX_TABULEIRO && (pos_rick[1] + i) < TAM_MAX_TABULEIRO) {
                if (tabuleiro[buff_movimento[0]][buff_movimento[1] + i] == 'Z') {
                    if ((tabuleiro[pos_rick[0]][pos_rick[1] + i] == 32) || (tabuleiro[pos_rick[0]][pos_rick[1] + i] == 'R')) {                                                                                              //77 = movimento para direita
                        if (uchTecla != 77) {
                            tabuleiro[buff_movimento[0]][buff_movimento[1] + i] = 32; //32 = ' ' //Excluí rastro do Rick
                            tabuleiro[pos_rick[0]][pos_rick[1] + i] = 'Z';            //Movimenta o Zumbi
                        }
                    }
                }
            }

            //Próximos acima de Rick
            if ((pos_rick[0] - i) < TAM_MAX_TABULEIRO && (pos_rick[1]) < TAM_MAX_TABULEIRO) {
                if (tabuleiro[buff_movimento[0] - i][buff_movimento[1]] == 'Z') {
                    if ((tabuleiro[pos_rick[0] - i][pos_rick[1]] == 32) || (tabuleiro[pos_rick[0] - i][pos_rick[1]] == 'R')) {                                                           //32 = ' '
                        if (uchTecla != 72) {
                            tabuleiro[buff_movimento[0] - i][buff_movimento[1]] = 32; //32 = ' ' //Excluí rastro do Rick
                            tabuleiro[pos_rick[0]-i][pos_rick[1]] = 'Z';            //Movimenta o Zumbi
                        }
                    }
                }
            }
        
            //Próximos embaixo de Rick
            if ((pos_rick[0] + i) < TAM_MAX_TABULEIRO && (pos_rick[1]) < TAM_MAX_TABULEIRO) {
                if (tabuleiro[buff_movimento[0]+i][buff_movimento[1]] == 'Z') {
                    if ((tabuleiro[pos_rick[0] + i][pos_rick[1]] == 32) || (tabuleiro[pos_rick[0] + i][pos_rick[1]] == 'R')) {                                                           
                        if (uchTecla != 80) {
                            tabuleiro[buff_movimento[0] + i][buff_movimento[1]] = 32; //32 = ' ' //Excluí rastro do Rick
                            tabuleiro[pos_rick[0] + i][pos_rick[1]] = 'Z';            //Movimenta o Zumbi
                        }
                    }
                }
            }
            
            /* Instável
            //Em Diagonal a Direita de Rick:
            for (int j = -(DISTANCIA_PERSEGUICAO - 2); j <= (DISTANCIA_PERSEGUICAO-2); j++) {
                if (j != 0) { //Condição que elimina a linha 0, visto que já foi tratada anteriormente como cima e baixo
                    if ((pos_rick[0] + j) < TAM_MAX_TABULEIRO && (pos_rick[1] + i) < TAM_MAX_TABULEIRO) { //Condição de Movimentação do Zumbi dentro do tabuleiro
                        if (tabuleiro[buff_movimento[0] + j][buff_movimento[1] + i] == 'Z') { //Condição de se tratar de um Zumbi
                            if ((tabuleiro[pos_rick[0] + j][pos_rick[1] + i] == 32) || (tabuleiro[pos_rick[0] + j][pos_rick[1] + i] == 'R')) { //Condição de Movimentação do zumbi para espaços vazios
                                if (uchTecla != 75) { //Condição de cercamento de Rick na direção em que ele se move
                                    tabuleiro[buff_movimento[0] + j][buff_movimento[1] + i] = 32; //32 = ' ' //Excluí rastro do Rick
                                    tabuleiro[pos_rick[0] + j][pos_rick[1] + i] = 'Z';            //Movimenta o Zumbi
                                }
                            }
                        }
                    }
                }
            }

            //Em Diagonal a Esquerda de Rick:
            for (int j = -(DISTANCIA_PERSEGUICAO - 2); j <= (DISTANCIA_PERSEGUICAO-2); j++) {
                if (j != 0) { //Condição que elimina a linha 0, visto que já foi tratada anteriormente como cima e baixo
                    if ((pos_rick[0] + j) < TAM_MAX_TABULEIRO && (pos_rick[1] - i) < TAM_MAX_TABULEIRO) { //Condição de Movimentação do Zumbi dentro do tabuleiro
                        if (tabuleiro[buff_movimento[0] + j][buff_movimento[1] - i] == 'Z') { //Condição de se tratar de um Zumbi
                            if ((tabuleiro[pos_rick[0] + j][pos_rick[1] - i] == 32) || (tabuleiro[pos_rick[0] + j][pos_rick[1] - i] == 'R')) { //Condição de Movimentação do zumbi para espaços vazios                                                                                         
                                if (uchTecla != 75) { //Condição de cercamento de Rick na direção em que ele se move
                                    tabuleiro[buff_movimento[0] + j][buff_movimento[1] - i] = 32; //32 = ' ' //Excluí rastro do Rick
                                    tabuleiro[pos_rick[0] + j][pos_rick[1] - i] = 'Z';            //Movimenta o Zumbi
                                }
                            }
                        }
                    }
                }
            }*/ 
        }

        //Diagonais em volta de Rick:
        for (int i = -1; i < 1; i += 2) {
            for (int j = -1; j < 1; j += 2) {
                if ((pos_rick[0] + i) < TAM_MAX_TABULEIRO && (pos_rick[1] + j) < TAM_MAX_TABULEIRO) { //Condição de Movimentação do Zumbi dentro do tabuleiro
                    if (tabuleiro[buff_movimento[0] + i][buff_movimento[1] + j] == 'Z') { //Condição de se tratar de um Zumbi
                        if ((tabuleiro[pos_rick[0] + i][pos_rick[1] + j] == 32) || (tabuleiro[pos_rick[0] + i][pos_rick[1] + j] == 'R')) { //Condição de Movimentação do zumbi para espaços vazios
                            if (uchTecla != 75) { //Condição de cercamento de Rick na direção em que ele se move
                                tabuleiro[buff_movimento[0] + i][buff_movimento[1] + j] = 32; //32 = ' ' //Excluí rastro do Rick
                                tabuleiro[pos_rick[0] + i][pos_rick[1] + j] = 'Z';            //Movimenta o Zumbi
                            }
                        }
                    }
                }
            }
        }

    }
    
    //Jogo é finalizado
    if (jogo == 2) {
        printf("\n\n\n\n\n");
        printf("RICK MORREU ;-;\nREST IN PEACE RICK\n");
        printf("\n\n\n\n\n");

    } else if (jogo == 3) {
        printf("\n\n\n\n\n");
        printf("RICK FUGIU \nUHUUULL AGORA RICK SO PRECISA RESTAURAR A HUMANIDADE\n");
        printf("\n\n\n\n\n");

    } else if (jogo == 4) {
        printf("\n\n\n\n\n");
        printf("VOCE ABANDONOU RICK COM OS ZUMBIS \nJOGADOR MAL! ESPERO QUE VOCE NAO VIVA UM APOCALIPSE ZUMBI\n");
        printf("\n\n\n\n\n");

    }
    
    return 0;
}