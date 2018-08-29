#include "raiz.h"
#include <stdio.h>
#include <math.h>

int main (void){
	int Inters,Iqi;
	double raiz,raiz2;
	Inters = bissecao(2.0,6.0,6, cos, &raiz);
	Iqi = IQI(1.0,5.0,6.0,6,sin,&raiz2);
	return 0;
}