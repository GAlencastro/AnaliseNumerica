#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include <math.h>


double* vetcria (int n){
	double *vet;
	vet = (double *)malloc(n*sizeof(double));
	return vet;
}


void vetlibera (double* v){
	free(v);
}

double escalar(int n, double *vet1, double *vet2){
	double *vetProd = (double *)malloc(n*sizeof(double));
	double soma = 0;
	int i;	
	for(i = 0; i < n; i++){
		vetProd[i] = vet1[i] * vet2[i];
		soma += vetProd[i];
	}
	
	return soma;		 
}

double norma2 (int n, double* v){
	int i;
	double soma = 0;
	for (i=0; i<n; i++){
		v[i] = pow(v[i],2);
		soma += v[i];
	}
	soma = sqrt(soma);
	return soma;
}
double** matcria (int m, int n){
	int i;
	double **Mat;
	Mat = (double **)malloc(m*sizeof(double));
	for(i=0; i<m; i++){
		Mat[i] = vetcria(n);
	}
	return Mat;

}
void matlibera (int m, double** A){

	int i;
	for(i=0; i<m;i++){
		vetlibera(A[i]);
	}

	free(A);
}

void transposta (int m, int n, double** A, double** T){ //m = linha;;;n = coluna
	int i, aux, aux2,j;
	for(i=0; i<m; i++){
		aux = i;
		for(j=0; j<n ; j++){
			aux2 = j;
			T[aux2][aux] = A[aux][aux2];
		}
	}
}

void multmv (int m, int n, double** A, double* v, double* w){
	int i,j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			w[j] = A[i][j] * v[j];
		}
	}
}



