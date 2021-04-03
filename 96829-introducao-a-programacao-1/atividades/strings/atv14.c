#include <stdio.h>

#define TAM_MAX_STR 101

int main() {
    char str[TAM_MAX_STR];
    
    printf("Diga sua string\n");
    gets(str);

    for (int i = 0; i < TAM_MAX_STR; i++) { //Consultar tabela ASCII para compreender o algoritmo
        if ((str[i] >= 97) && (str[i] <= 119)) { //Condição para as letras de a à w
            str[i] -= 32; //Transforma quaisquer minúsculos em maiúsculos
            str[i] += 3; //Condição de codificação
        } else if ((str[i] >= 65) && (str[i] <= 87)) { //Condição para as letras de A à W
            str[i] += 3;
        } else if ((str[i] >= 120) && (str[i] <= 122)) { //Condição para as letras x, y e z
            str[i] -= 32; //Transforma quaisquer minúsculos em maiúsculos
            str[i] -= 23; //Condição de codificação especial das letras x, y e z
        } else if ((str[i] >= 88) && (str[i] <= 90)) { ////Condição para as letras X, Y e Z
            str[i] -= 23; //Condição de codificação especial das letras X, Y e Z
        }
    }

    printf("A sua string fica assim:\n %s",str);
    
    return 0;
}