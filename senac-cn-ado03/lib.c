#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void eulerFloat(FILE *fp){	
	for(float n = 1; n <= 10e20; n *= 10){
		float e = powf(1 + (1/n), n);
		fprintf(fp, "%f %f\n", n, e); 
	}

}
void eulerDouble(FILE *fp){
	for(double n = 1; n <= 10e20; n *= 10){
		double e = powf(1 + (1/n), n);
		fprintf(fp, "%lf %lf\n", n, e); 
	}
}
void eulerLongDouble(FILE *fp){
	for(long double n = 1; n <= 10e20; n *= 10){
		long double e = powl(1 + (1/n), n);
		fprintf(fp, "%LF %LF\n", n, e); 
	}
} 
