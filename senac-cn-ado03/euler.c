#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void configurate (FILE *gnu, char *output_name, char * type){

	 	fprintf(gnu, "set terminal png\n");
        	fprintf(gnu, "set output '%s'\n", output_name);
        	fprintf(gnu, "set logscale x\n");			
		fprintf(gnu, "set yrange [0:4]\n");
		fprintf(gnu, "set title 'Euler Aproximation with %s'\n", type);
		fprintf(gnu, "set ylabel 'euler'\n"); 
		fprintf(gnu, "set xlabel 'n'\n");
		fprintf(gnu, "set nokey\n");
		fprintf(gnu, "plot '-' w l\n");
}

int main(void){
	
	 FILE * gnuFiles[3] = {
		popen("gnuplot -persistent", "w"),
        	popen("gnuplot -persistent", "w"),
        	popen("gnuplot -persistent", "w")
	}; 

	configurate(gnuFiles[0], "euler_flt.png", "float");
	configurate(gnuFiles[1], "euler_dbl.png", "double");
	configurate(gnuFiles[2], "euler_ldbl.png", "long double");

	eulerFloat(gnuFiles[0]);
	eulerDouble(gnuFiles[1]);
	eulerLongDouble(gnuFiles[2]);

	for (int i = 0; i < 3; i++){
	     pclose(gnuFiles[i]);	
	}
	
	return 0;	
 }
