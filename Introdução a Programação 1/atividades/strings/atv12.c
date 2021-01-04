#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR 51

int main() {
    char str[TAM_MAX_STR];
    char str_hw[TAM_MAX_STR] = "Ola mundo";
    int i,j;
    
    printf("Diga sua String\n");
    gets(str);
    printf("Agora diga as posicoes que voce deseja concatenar: i j\n");
    scanf("%i %i",&i,&j);

    for (int a = 0; a <= (j-i); a++) 
        str[a] = str[a+i];
    
    strncat(str_hw,str,(j-i));

    printf("A String concatenada eh: %s",str_hw);
    
    return 0;
}