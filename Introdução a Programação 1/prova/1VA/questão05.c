#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAM_MAX_TABULEIRO_ESCOLA 5 //5x5

#define TAM_MAX_TABULEIRO_PARKING_COLUNA 10
#define TAM_MAX_TABULEIRO_PARKING_LINHA 3

#define TAM_MAX_TABULEIRO_BAIRRO_COLUNA 10
#define TAM_MAX_TABULEIRO_BAIRRO_LINHA 8

#define TAM_MAX_ITEMS 4

int main() {
    int cenario = 0;
    /* cenario = 0, não há cenário
     * cenario = 1, WW está na escola
     * cenario = 2, WW está no estacionamento da escola
     * cenario = 3, WW está passeando no seu bairro
     * cenario = 4,FINAL: WW foi pego pelo diretor da escola
     * cenario = 5,FINAL: jogo acaba por desistência
     * cenario = 6,FINAL: WW foi pego pela polícia
     * cenario = 7,FINAL: WW faz o contrabando com sucesso
     * */
    //Setup do tabuleiro da escola
    char tabuleiro_escola[TAM_MAX_TABULEIRO_ESCOLA][TAM_MAX_TABULEIRO_ESCOLA] = {
        {'P',' ',' ','1','1'},
        {' ',' ',' ','2','1'},
        {' ',' ',' ','2','2'},
        {' ',' ',' ','3','4'},
        {' ',' ',' ','3','4'},
    };
    
    //Setup do tabuleiro do Estacionamento
    char tabuleiro_estacionamento[TAM_MAX_TABULEIRO_PARKING_LINHA][TAM_MAX_TABULEIRO_PARKING_COLUNA] = {
        {'P',' ',' ','1','2','3','4','5','6','7'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ','S'},
    };

    //Setup do tabuleiro do Bairro
    char tabuleiro_bairro[TAM_MAX_TABULEIRO_BAIRRO_LINHA][TAM_MAX_TABULEIRO_BAIRRO_COLUNA] = {
        {'E',' ',' ',' ',' ',' ','x','x','x','x'},
        {' ','x','x','x','x','4',' ',' ',' ','P'},
        {'3','x','x','x','x','x','x','x','x','1'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ','x','x','x','x','P','x','x',' ','x'},
        {' ',' ','x','x','x','2','x','x',' ','x'},
        {'x',' ','x','J','x',' ','x','x',' ','x'},
        {'x',' ',' ',' ',' ',' ',' ',' ',' ','S'},
    };
    unsigned char uchTecla;
    char chanterior = ' ';
    unsigned int pos_walter[2];
    /* posição 0 para linha
     * posição 1 para coluna
     */
    int qtd_item[4] = {0,0,0,0};

    srand(time(NULL));

    //Seta a posição do WW no cenário 1
    cenario = 1;
    pos_walter[0] = 0;
    pos_walter[1] = 1;
    tabuleiro_escola[pos_walter[0]][pos_walter[1]] = 'W';
    //Inicia cenário 1
    while (cenario == 1) {

        //Construção do tabuleiro
        printf("     ");
        for (int i = 0; i < TAM_MAX_TABULEIRO_ESCOLA; i++)
            printf("%i   ", i + 1); //Número da coluna + Espaçamento dos números das coluna
        printf("\n");
        for (int linha = 0; linha < TAM_MAX_TABULEIRO_ESCOLA; linha++) {
            printf("%2i ", linha + 1); //Enumera as linhas
            printf("|");               //Constrói primeiro traço(|) do tabuleiro
            for (int coluna = 0; coluna < TAM_MAX_TABULEIRO_ESCOLA; coluna++)
                printf(" %c |", tabuleiro_escola[linha][coluna]); //Realiza o print do dado
            printf("\n");
        }
        
        //Lê o movimento do jogador
        int buff_movimento[2];
        do {
            uchTecla = getch();

            //Movimento Anterior de Walter
            buff_movimento[0] = pos_walter[0];
            buff_movimento[1] = pos_walter[1];

            switch (uchTecla) {
                case 72: pos_walter[0] -= 1; break;
                case 75: pos_walter[1] -= 1; break;
                case 77: pos_walter[1] += 1; break;
                case 80: pos_walter[0] += 1; break;
                default: break;
            }
        } while (!((uchTecla == 72) || (uchTecla == 75) || (uchTecla == 77) || (uchTecla == 80) || (uchTecla == 0x1b)));
        
        if (uchTecla == 0x1b) {
            cenario = 5;
            break;
        }
        
        //Condição de movimentação de WW no tabuleiro da escola
        if ((pos_walter[0] < 5) && (pos_walter[1] < 5)) {
            //Testa se WW quer sair
            if (tabuleiro_escola[pos_walter[0]][pos_walter[1]] == 'P') {
                int qtd_total_item = 0;
                for (int i = 0; i < TAM_MAX_ITEMS; i++) 
                    qtd_total_item += qtd_item[i];
                
                if (qtd_total_item == 4) {
                    printf("Walter White saiu de Mansinho com o material da escola\n");
                    cenario = 2;
                    break;
                } else {
                    printf("Ainda e possivel coletar items na escola, procure pelo item que voce nao pegou\n");
                    pos_walter[0] = buff_movimento[0];
                    pos_walter[1] = buff_movimento[1];
                }
            } else {
                tabuleiro_escola[buff_movimento[0]][buff_movimento[1]] = chanterior;
                chanterior = tabuleiro_escola[pos_walter[0]][pos_walter[1]];
                tabuleiro_escola[pos_walter[0]][pos_walter[1]] = 'W';
            }
        } else {
            pos_walter[0] = buff_movimento[0];
            pos_walter[1] = buff_movimento[1];
        }

        switch (chanterior) {
        case '1':
            if (qtd_item[0] > 0) {
                cenario = 4;
            } else if (qtd_item[0] == 0){
                qtd_item[0] += 1;
                chanterior = 32;
                printf("Voce pegou o item 1\n");
            }
            break;
        case '2':
            if (qtd_item[1] > 0) {
                cenario = 4;
            } else if (qtd_item[1] == 0){
                qtd_item[1] += 1;
                chanterior = 32;
                printf("Voce pegou o item 2\n");
            }
            break;
        case '3':
            if (qtd_item[2] > 0) {
                cenario = 4;
            } else if (qtd_item[2] == 0){
                qtd_item[2] += 1;
                chanterior = 32;
                printf("Voce pegou o item 3\n");
            }
            break;
        case '4':
            if (qtd_item[3] > 0) {
                cenario = 4;
            } else if (qtd_item[3] == 0){
                qtd_item[3] += 1;
                chanterior = 32;
                printf("Voce pegou o item 4\n");
            }
            break;
        default:
            break;
        }
    }

    
    //Seta a posição do WW no cenário 2
    pos_walter[0] = 0;
    pos_walter[1] = 0;
    chanterior = 'P';
    tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = 'W';
    int wwdecarro = 0;
    //Inicia o cenário 2
    while (cenario == 2) {

        //Construção do tabuleiro
        printf("     ");
        for (int i = 0; i < TAM_MAX_TABULEIRO_PARKING_COLUNA; i++)
            printf("%i   ", i + 1); //Número da coluna + Espaçamento dos números das coluna
        printf("\n");
        for (int linha = 0; linha < TAM_MAX_TABULEIRO_PARKING_LINHA; linha++) {
            printf("%2i ", linha + 1); //Enumera as linhas
            printf("|");               //Constrói primeiro traço(|) do tabuleiro
            for (int coluna = 0; coluna < TAM_MAX_TABULEIRO_PARKING_COLUNA; coluna++)
                printf(" %c |", tabuleiro_estacionamento[linha][coluna]); //Realiza o print do dado
            printf("\n");
        }

        //Lê o movimento do jogador
        int buff_movimento[2];
        do {
            uchTecla = getch();

            //Movimento Anterior de Walter
            buff_movimento[0] = pos_walter[0];
            buff_movimento[1] = pos_walter[1];

            switch (uchTecla) {
                case 72: pos_walter[0] -= 1; break;
                case 75: pos_walter[1] -= 1; break;
                case 77: pos_walter[1] += 1; break;
                case 80: pos_walter[0] += 1; break;
                default: break;
            }
        } while (!((uchTecla == 72) || (uchTecla == 75) || (uchTecla == 77) || (uchTecla == 80) || (uchTecla == 0x1b)));
        
        //Desistencia do jogador
        if (uchTecla == 0x1b) {
            cenario = 5;
            break;
        }

        //Condição de Movimentação do WW no tabuleiro do Estacionamento
        if ((pos_walter[0] < TAM_MAX_TABULEIRO_PARKING_LINHA) && (pos_walter[1] < TAM_MAX_TABULEIRO_PARKING_COLUNA)) {
            tabuleiro_estacionamento[buff_movimento[0]][buff_movimento[1]] = chanterior;
            chanterior = tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]];
            if (wwdecarro == 0)
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = 'W';
            else if (wwdecarro == 1)
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = '5';
        } else {
            pos_walter[0] = buff_movimento[0];
            pos_walter[1] = buff_movimento[1];
        }

        //Interações do WW com o cenário
        switch (chanterior) {
        case ' ':
            break;
        case '5':
            printf("Walter White entrou em seu Prius Hibrido Amarelo\n");
            tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = '5';
            wwdecarro = 1;
            chanterior = ' ';
            break;
        case 'S':
            if (wwdecarro == 1) {
                cenario = 3;
            } else {
                printf("Walter White voce nao pode sair sem seu carro\n");
                printf("procure por seu carro e saia da escola com ele\n");
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = chanterior;
                pos_walter[0] = buff_movimento[0];
                pos_walter[1] = buff_movimento[1];
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = 'W';
                chanterior = ' ';
            }
            break;
        
        default:
            printf("Walter White se esqueceu qual eh o seu carro\n");
            printf("E o carro %c nao eh seu carro\n",chanterior);
            tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = chanterior;
            pos_walter[0] = buff_movimento[0];
            pos_walter[1] = buff_movimento[1];
            if (wwdecarro == 0)
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = 'W';
            else if (wwdecarro == 1)
                tabuleiro_estacionamento[pos_walter[0]][pos_walter[1]] = '5';
            chanterior = ' ';
            chanterior = ' ';
            break;
        }

    }

    pos_walter[0] = 0;
    pos_walter[1] = 0;
    chanterior = 'E';
    tabuleiro_bairro[pos_walter[0]][pos_walter[1]] = 'W';
    int wwcomJesse = 0;
    while (cenario == 3) {
        //Construção do tabuleiro
        printf("     ");
        for (int i = 0; i < TAM_MAX_TABULEIRO_BAIRRO_COLUNA; i++)
            printf("%i   ", i + 1); //Número da coluna + Espaçamento dos números das coluna
        printf("\n");
        for (int linha = 0; linha < TAM_MAX_TABULEIRO_BAIRRO_LINHA; linha++) {
            printf("%2i ", linha + 1); //Enumera as linhas
            printf("|");               //Constrói primeiro traço(|) do tabuleiro
            for (int coluna = 0; coluna < TAM_MAX_TABULEIRO_BAIRRO_COLUNA; coluna++)
                printf(" %c |", tabuleiro_bairro[linha][coluna]); //Realiza o print do dado
            printf("\n");
        }

        //Lê o movimento do jogador
        int buff_movimento[2];
        do {
            uchTecla = getch();

            //Movimento Anterior de Walter
            buff_movimento[0] = pos_walter[0];
            buff_movimento[1] = pos_walter[1];

            switch (uchTecla) {
                case 72: pos_walter[0] -= 1; break;
                case 75: pos_walter[1] -= 1; break;
                case 77: pos_walter[1] += 1; break;
                case 80: pos_walter[0] += 1; break;
                default: break;
            }
        } while (!((uchTecla == 72) || (uchTecla == 75) || (uchTecla == 77) || (uchTecla == 80) || (uchTecla == 0x1b)));
        
        //Desistencia do jogador
        if (uchTecla == 0x1b) {
            cenario = 5;
            break;
        }

        //Condição de movimentação do WW
        if ((pos_walter[0] < TAM_MAX_TABULEIRO_BAIRRO_LINHA) && (pos_walter[1] < TAM_MAX_TABULEIRO_BAIRRO_COLUNA)) {
            if ((tabuleiro_bairro[pos_walter[0]][pos_walter[1]] == 'x') || (tabuleiro_bairro[pos_walter[0]][pos_walter[1]] == 'E')) {
                pos_walter[0] = buff_movimento[0];
                pos_walter[1] = buff_movimento[1];
            } else {
                tabuleiro_bairro[buff_movimento[0]][buff_movimento[1]] = chanterior;
                chanterior = tabuleiro_bairro[pos_walter[0]][pos_walter[1]];
                tabuleiro_bairro[pos_walter[0]][pos_walter[1]] = 'W';
            }
        } else {
            pos_walter[0] = buff_movimento[0];
            pos_walter[1] = buff_movimento[1];
        }

        //Interações do WW com o cenário
        switch (chanterior) {
        case '1':
            chanterior = ' ';
            qtd_item[0] += 1;
            break;
        case '2':
            chanterior = ' ';
            qtd_item[1] += 1;
            break;
        case '3':
            chanterior = ' ';
            qtd_item[2] += 1;
            break;
        case '4':
            chanterior = ' ';
            qtd_item[3] += 1;
            break;
        case 'J':
            chanterior = ' ';
            wwcomJesse = 1;
            break;
        case 'P':
            chanterior = ' ';
            if ((rand() & 2)) {
                cenario = 6;
            } else {
                for (int i = 0; i < 4; i++) 
                    qtd_item[i] = 0;
                printf("A policia confiscou o Walter White, agora WW esta sem produtos para producao\n");
            }
            break;
        case 'S':
            if (wwcomJesse)
                cenario = 7;
            else {
                printf("Voce precisa pegar o Jesse para sair do seu bairro\n");
                tabuleiro_bairro[pos_walter[0]][pos_walter[1]] = chanterior;
                pos_walter[0] = buff_movimento[0];
                pos_walter[1] = buff_movimento[1];
                tabuleiro_bairro[pos_walter[0]][pos_walter[1]] = 'W';
            }
        
        default:
            break;
        }
    }
    
    //Esvaziando os tabuleiros
    if (cenario == 4) {
        printf("\n\n\n\nO DIRETOR DA ESCOLA PEGOU WALTER WHITE!\nWalter White foi denunciado pelo diretor\ne agora ira responder no tribunal\n\n\n\n");
    } else if (cenario == 5) {
        printf("\n\n\n\nO jogador desistiu de salvar o Walter White\nWalter Branco que se vire agora\n\n\n\n");
    } else if (cenario == 6) {
        printf("\n\n\n\n- PARADO AI SEU BRANCO - disse o policial quando avistou o Walter\n");
        printf("- O que houve? - disse Walter assustado\n");
        printf("- VOCE ESTA PRESO EM NOME DA LEI POR CONTRABANDO, BORA DESCE DO CARRO E COMECA A PAGAR PROMESSA AI - retruncou o policial\n");
        printf("Walter White sem muita vontade de viver, pegou um revolver no banco de tras do carro e se matou a mao armada\n");
        printf("Fim do Jogo!\n\n\n\n");
    } else if (cenario == 7) {
        int qtd_total_itens;
        for (int i = 0; i < TAM_MAX_ITEMS; i++)
            qtd_total_itens += qtd_item[i];
        
        if (qtd_total_itens == 8) {
            printf("\n\n\n\nWalter White conseguiu fugir do Bairro com Jesse\n");
            printf("Ele conseguiu contrabandear dois conjunto de itens e agora sua producao sera dobrada\n\n\n\n");
        } else {
            printf("\n\n\n\nWalter White conseguiu fugir do Bairro com Jesse\n");
            printf("Ele conseguiu apenas contrabandear um conjunto de itens e agora sua producao sera normal\n\n\n\n");
        }
    }

    return 0;
}