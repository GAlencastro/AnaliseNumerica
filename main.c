#include <stdio.h>
#include "sistlinear.h"

int main(){
	int i,j, indice = 9;
	double **M;
	int *p;
	for(i=0; i < 3; i++){
		for(j=0; j < 3; j++){
			M[i][j] = indice;
			indice--;
		}
	}
	fatoracao(3,M,p);
	imprimeMat(M,3);
	return 0;
}