
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
    if(argc > 4)
        exit(0);

    createSymbols();
    int size = strlen(argv[1]);
    //CONVERTE PARA DECIMAL
    int n = fromDigits(argv[1], atoi(argv[2]), size);
    toDigitis(n, atoi(argv[3]));
}

