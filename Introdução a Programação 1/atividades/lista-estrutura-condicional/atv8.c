/*Um hotel cobra R$50,00 reais a diária e mais uma taxa de serviços. Faça
um programa que lê a quantidade de dias que o hóspede ficou no hotel
e imprime o valor total a pagar. A taxa de serviços é de:

15,30 por dia, se número de diárias <15
10,00 por dia, se número de diárias =15
8,50 por dia, se número de diárias >15
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int dias;
    float totalpg;

    printf("Digite quantos dias o hospede ficou hospedado\n");
    scanf("%i",&dias);

    if (dias < 15) {
        totalpg = 50*dias + 15.30*dias;
    } else if (dias == 15) {
        totalpg = 50*dias + 10*dias;
    } else if (dias > 15) 
        totalpg = 50*dias + 8.50*dias;
    
    printf("O total a pagar eh: R$%.2f", totalpg);
    
    return 0;
}
