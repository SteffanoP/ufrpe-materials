#include <stdio.h>

#define SENHA 1234

int main(int argc, char const *argv[]) {
    int tentativa_senha;
    

    for (int i = 0; i < 3; i++) {
        printf("Digite sua senha: ");
        scanf("%i",&tentativa_senha);
        getchar();

        if (tentativa_senha == SENHA)  {
            printf("Senha Correta!\n");
            i = 3;
        } else if (i < 2){
            printf("Senha invalida, tente novamente\n");
        }  else {
            printf("Acesso Bloqueado\n");
            while (1);
        }
    }
    
    return 0;
}
