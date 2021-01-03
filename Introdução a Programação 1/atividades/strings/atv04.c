#include <stdio.h>

int main() {
    char string[51], c;

    printf("Diga a String\n");
    gets(string);
    printf("Agora me diga o caractere que voce pretende substituir o espaco\n");
    scanf("%c",&c);

    for (int i = 0; i < 51; i++) {
        if (string[i] == ' ') 
            string[i] = c;       
    }

    printf("Sua String e' %s",string);

    return 0;
}