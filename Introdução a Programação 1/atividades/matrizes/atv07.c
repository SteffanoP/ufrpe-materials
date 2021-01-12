#include <stdio.h>

#define TAM_MATRIZ_LINHAS 3
#define TAM_MATRIZ_COLUNAS 3

int main() {
    float matriz1[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS], matriz2[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
    int opcao_usuario;

    printf("Voce ira preencher a matriz 1 da seguinte forma\n");
    printf("Ira digitar uma linha por vez e ira inserir as 3 colunas\n");
    printf("Ex:\n1 2 3\n4 5 6\n7 8 9\n");

    //Leitura de dados da matriz 1
    printf("Leitura da matriz 1\n");
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        printf("Digite a linha %i\n",i+1);
        scanf("%f %f %f",&matriz1[i][0],&matriz1[i][1],&matriz1[i][2]);
        getchar();
    }
    
    //Leitura de dados da matriz 2
    printf("Leitura da matriz 2\n");
    for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
        printf("Digite a linha %i\n",i+1);
        scanf("%f %f %f",&matriz2[i][0],&matriz2[i][1],&matriz2[i][2]);
        getchar();
    }

    printf("Por favor me diga a operacao que deseja realizar\n");
    printf("1.Somar as duas matrizes\n");
    printf("2.Subtrair a primeira matriz da segunda\n");
    printf("3.Adicionar uma constante as duas matrizes\n");
    scanf("%i",&opcao_usuario);

    switch (opcao_usuario) {
        float matriz3[TAM_MATRIZ_LINHAS][TAM_MATRIZ_COLUNAS];
        float constante;

    case 1:
        
        printf("A matriz resultante sera:\n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                printf("%.2f ", matriz3[i][j]);
            }
            printf("\n");
        }
        
        break;

    case 2:
        
        printf("A matriz resultante sera:\n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
                printf("%.2f ", matriz3[i][j]);
            }
            printf("\n");
        }

        break;
    
    case 3:
        
        printf("A qual constante voce deseja adicionar nas duas matrizes?\n");
        scanf("%f",&constante);

        //Adição e print da matriz 1
        printf("A matriz 1 ficara da seguinte forma: \n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz1[i][j] += constante;
                printf("%.2f ", matriz1[i][j]);
            }
            printf("\n");
        }

        //Adição e print da matriz 2
        printf("\nA matriz 2 ficara da seguinte forma: \n");
        for (int i = 0; i < TAM_MATRIZ_LINHAS; i++) {
            for (int j = 0; j < TAM_MATRIZ_COLUNAS; j++) {
                matriz2[i][j] += constante;
                printf("%.2f ", matriz2[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Opcao inva'lida");
        break;
    }

    return 0;
}