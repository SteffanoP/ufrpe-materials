/*Entrar com sexo (caractere ‘m’ para masculino e ‘f’ para feminino) e idade de uma 
pessoa. Se a pessoa for do sexo feminino e tiver menos de 25 anos, imprimir a 
mensagem: ACEITA. Caso contrário, imprimir a mensagem: NÃO ACEITA.*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char sexo;
    int idade;

    printf("Digite seu sexo(caractere 'm' para masculino e 'f' para feminino) e sua idade\n");
    scanf("%c %i",&sexo,&idade);
    
    if ((sexo == 'f') && (idade < 25)) {
        printf("ACEITA");
    } else {
        printf("NAO ACEITA");
    }
    
    
    return 0;
}
