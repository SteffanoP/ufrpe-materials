#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR1 1001
#define TAM_MAX_STR2 51

int main() {
    char str1[TAM_MAX_STR1], str2[TAM_MAX_STR2];
    int qtd_cat;

    printf("Por favor diga a String 1\n");
    gets(str1);
    printf("Por favor diga a String 2\n");
    gets(str2);

    printf("Agora me diga quantas vezes voce pretende concatenar a str2 com a str1?\n");
    scanf("%i",&qtd_cat);

    for (int i = 0; i < qtd_cat; i++) {
        strcat(str1,str2);
    }

    printf("A String 1 fica assim:\n%s",str1);
    
    return 0;
}