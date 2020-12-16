/*Escreva um programa que peça 3 notas (reais) para o usuários. Imprima 
“voce passou”, caso a média das notas seja maior ou igual a 7; caso 
contrário, imprima “voce nao passou”. */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float nota1, nota2, nota3, media;
    printf("digite a nota em ordem: nota1 nota2 nota3\n");
    scanf("%f %f %f",&nota1,&nota2,&nota3);

    media = (nota1 + nota2 + nota3)/3;

    if (media >= 7) {
        printf("voce passou com %.2f",media);
    } else {
        printf("voce nao passou e ficou com %.2f",media);
    }
    
    return 0;
}
