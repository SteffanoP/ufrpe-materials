//Faça um programa que lê 2 valores A e B (inteiros) e informa se A é divisível por B ou não.
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a,b;
    printf("Informe o valor de a e b\n");
    scanf("%i %i",&a,&b);

    if ((a % b) == 0) {
        printf("SIM, Teu numero %i eh divisivel por %i",a,b);
    } else {
        printf("NOPE, Teu numero %i n eh divisivel por %i",a,b);
    }

    return 0;
}
