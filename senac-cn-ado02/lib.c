#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

double seno(double a)
{
    double result = 0;
    int n = 0;
    for(n = 0; n <= 20; n++)
    {
        result += (power(-1,n)* power(a,2*n + 1)) / factorial(2*n + 1);
    }

    return result;
}

double cosseno(double a)
{
    double result = 0;
    int n = 0;
    for(n = 0; n <= 20; n++)
    {
        result += (power(-1,n) * power(a,2*n)) / factorial(2*n);
    }

    return result;
}

double power(double a, double b)
{

    double newValue = 1;
    int count = 0;

    for (count = 0; count < b; count++){
	newValue *= a;
    }
    return newValue;
}

double factorial(int n)
{

    double fat = 1;
    int current;
    for(current = n; current > 0; current--){
        fat *= current;
    }
    return fat;
}
