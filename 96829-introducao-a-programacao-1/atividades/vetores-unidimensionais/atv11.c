#include <stdio.h>

#define QTD_ELEMENTOS 10

int main() {
    int a[QTD_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9};
    int b[QTD_ELEMENTOS] = {5,6,7,8,9,10,11,12,13,14};
    int uniao[QTD_ELEMENTOS*2];
    int uniao_comum[QTD_ELEMENTOS*2];

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        uniao_comum[i] = NULL;
    }

    //Função Soma (uniao += a + b)
    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        if (i < 10) {
            uniao[i] = a[i];
        } else if (i < 20) {
            uniao[i] = b[i-10];
        }
    }

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        for (int j = 0; j < QTD_ELEMENTOS*2; j++) {
            if (uniao[i] == uniao[j]) {
                uniao_comum[i] = uniao[i];
                j = QTD_ELEMENTOS*2;
            }
        }        
    }

    for (int i = 0; i < QTD_ELEMENTOS*2; i++) {
        if (uniao_comum != NULL)
            printf("%i\n", uniao_comum[i]);        
    }  

    return 0;
}