
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>

int main (int argc, char *argv[]){
   /* createSymbols();
    char* number = argv[1];
    int lenght = sizeof(number)/sizeof(number[0]);
    //CONVERTE PARA DECIMAL
    int n = fromDigits(number, 2, lenght);
    printf("%d", n);
    //CONVERTE PARA A BASE FINAL
    toDigitis(n, 8);
    */
    int base_inicial = atoi(argv[2]);
    int base_destino = atoi(argv[3]);
    if(argc > 4 || atoi(argv[1]) < 0 || 
        !(base_inicial >= 2 && base_inicial <= 36) || 
        !(base_destino >= 2 && base_destino <= 36))
        exit(0);

    createSymbols();
    int size = strlen(argv[1]);
    //CONVERTE PARA DECIMAL
    long int n = fromDigits(argv[1], base_inicial, size);
    toDigitis(n, base_destino);
    exit(1);
}

