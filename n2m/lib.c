#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

#define SYMBOLS 26
typedef struct
{
    char letter;
    int number;
}Representation;
Representation symbols [SYMBOLS];

void createSymbols(){

    // preenche com os numeros
    for (int i = 0; i < 10; i++){
        symbols[i].letter = i+'0';
        symbols[i].number = i;
    }
    char c;
    int n = 10;
    //preenche com as letras
    for(c = 'A'; c <= 'Z'; ++c){
        symbols[n].letter = c;
        symbols[n].number = n;
        n++;
    }
}

char findSymbol(int n){

    for(int i = 0; i < SYMBOLS; i++){
        if (symbols[i].number == n){
            return symbols[i].letter;
        }
    }
    //printf("Letra nao encontrada!");
    exit(0);
}

char findNumber(char n){

    for(int i = 0; i < SYMBOLS; i++){
        if (symbols[i].letter == n){
            return symbols[i].number;
        }
    }
    //printf("Numero nao encontrado!");
    exit(0);
}

void printDigits(char *p, int qtd_elementos)
{
    printf("\n");
    for(int i = 0; i < qtd_elementos; i++){
        printf("%c", p[i]);
    }
}

// Function to swap two memory contents
void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseDigits(char * digitos, int qtd_elementos)
{
    // pointer2 aponta para o final do array
    char *pointer2 = digitos + qtd_elementos -1;
    // Verifica se o digito esta apontando para um lugar
    // de memoria indice menor do que o pointer2
    while (digitos < pointer2) {
        swap(digitos, pointer2);
        digitos++;
        pointer2--;
    }
}

//Dobra o tamanho de memoria disponivel
void increase(char * array)
{
    array = realloc(array, sizeof(array)*2);

    if (array == NULL){
    	//printf("Error: Memory Exception");
		exit(1);
    }
}

//Convert a positive number n to its digit representation in base b.
void toDigitis(int n, int b)
{
	char * digits = NULL;
	digits = malloc (100*sizeof(char));

	if(digits == NULL){
		//printf("Error: Memory Exception");
		exit(1);
	}
	int count = 0;
	int i = 0;
	for (i = 0; n > 0; i++)
	{
		if (count >= 100){
			count = 0;
			//printf("realocando mais espaco");
			increase(digits);
		}
		int resto = n % b;
		digits[i] = findSymbol(resto);
		n = n / b;
		count++;
	}
    reverseDigits(digits, i);
    printDigits(digits, i);
}

int fromDigits(char * digits, int b, int size){
    int n = 0;
    for (int i = 0; i < size; i++){
        //printf("Procurando numero: %c", digits[i]);
        int d = findNumber(digits[i]);
        n = b * n + d;
    }
    return n;
}





