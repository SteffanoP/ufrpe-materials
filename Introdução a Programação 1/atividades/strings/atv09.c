#include <stdio.h>
#include <string.h>

#define TAM_MAX_STR 21

int main() {
    char str1[TAM_MAX_STR], str2[TAM_MAX_STR];

    printf("Diga a String 1\n");
    gets(str1);
    printf("Diga a String 2\n");
    gets(str2);

    if (strcmp(str1,str2) == 0) { //Ver strcmp()
        printf("As duas Strings sao iguais\n");
    } else {
        printf("As duas Strings sao diferentes\n");
    }
    
    return 0;
}