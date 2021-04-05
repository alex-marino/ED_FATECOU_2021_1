#include <stdio.h>
#include "MyRecFunctions.h"

int main() {
//    Exemplo de execuçao da funçao fatorial recursiva
//    int n;
//    scanf("%d", &n);
//    printf("Fatorial de n = %lld", fatorialRec(n));
//    printf("Fatorial de n = %lld", fatorial(n));

    //Exemplo de execuçao da funçao dee desenho da regua inglesa
//    int n, l;
//    scanf("%d %d", &n, &l);
//    drawRuller(n, l);

//    //Exemplode execuçao da funçao de busca binaria
    int n;
    scanf("%d", &n);
    int data[10] = {0, 1, 3, 4, 7, 9, 13, 21, 72, 102};
    if (binarySearch(data, n, 0, 9)){
        printf("O numero n = %d encontra-se no array!!\n");
    } else{
        printf("O numero n = %d nao encontra-se no array!!\n");
    }

//    int n;
//    scanf("%d", &n);
//    printf("O fatarial de %d = %ld", n, fatorialRec(n));


//    int n;
//    scanf("%d", &n);
//    drawRuller(n, 8);

    return 0;
}
