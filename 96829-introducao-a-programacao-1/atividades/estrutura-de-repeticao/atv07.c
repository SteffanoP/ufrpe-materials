#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero;
    
    printf("Diga o numero que eu te mando a tabuada\n");
    scanf("%i",&numero);

    for (int i = 1; i <= 10; i++) 
        printf("A tabuada de %ix%i=%i\n",numero,i,numero*i);
    
    return 0;
}
