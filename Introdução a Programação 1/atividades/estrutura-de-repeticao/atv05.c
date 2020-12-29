#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i;
    int primo;

    printf("Manda um inteiro ai e vamo ver se ele eh primo ou nao\n");
    scanf("%i",&i);

    if ((i % 1) == 0) {
        if ((i % i) == 0)
            primo = 1;
        
        int x;
        for (x = 2; x < i; x++) {
            if ((i % x) == 0)
                primo = 0;
        }
    }

    if (primo == 1)
        printf("O numero eh primo");
    else
        printf("Nem eh primo");
    return 0;
}
