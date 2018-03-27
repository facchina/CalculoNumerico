#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

int main() 
{
    int i = 0;
    FILE *arq;

    arq = fopen("sen.dat", "w");    
    if (arq == NULL){
        printf("Error opening file");
        exit(1);
    }
    //Calculates erros for sin calculated in the range of 0 to 4PI rad (0 to 720 graus)
    for(i = 0; i <= 720; i ++)
    {
        //converts the angle to radians because the Taylor series only works with radians
        double rad = i*(PI/180);
        double absolutError = fabs(sin(rad) - seno(rad));
        double relativeError = fabs(absolutError / seno(rad));
	    //storing the values in the file
        fprintf(arq, "%d\t%f\t%f\t%f\n", i, seno(rad), absolutError, relativeError);
    }
    fclose(arq);

    arq = fopen("cos.dat", "w");
    if (arq == NULL){
        printf("Error opening file");
        exit(1);
    }
    for(i = 0; i <= 720; i ++)
    {
        double rad = i*(PI/180);
	    //Converts the angle to radians because the Taylor series only works with radians
        double absolutError = fabs(cos(rad) - cosseno(rad));
        double relativeError = fabs(absolutError / cosseno(rad));
	    //Storing the values in the file
        fprintf(arq, "%d\t%f\t%f\t%f\n", i, cosseno(rad), absolutError, relativeError);
    }
    fclose(arq);

    free(arq);

    //Generate the graphics
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "%s\n%s", "set terminal png size 800,600\nset output 'seno_graphic.png'", "plot 'sen.dat'\n");
    fprintf(gnuplot, "%s\n%s", "set terminal png size 800,600\nset output 'cosseno_graphic.png'", "plot 'cos.dat'");

    exit(0);
}
