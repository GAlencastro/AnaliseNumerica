#include "sistlinear.h"
#include <stdlib.h>
#include <stdio.h>

double** matcria (int n){
	double **Mat;
	Mat = (double **)malloc((n*n)*sizeof(double));
	return Mat;

}

void linhaTroca(double **A, int *p, int n){
	int i,j;
	for(i=0; i<n; i++){
		p[i] = i;
	}
	for(j=0, j < n-1; j++){
		for(i = j+1; i < n-1; i++)
			if(
}

void fatoracao (int n, double** A, int* p){
	// DEscobrir a matriz U
	double **MatrizL, **MatrizU, fator;
	int i, j, k;
	for(j=0; j < (n-2); j++){	
		for(i=0; i < (n-1); i++){
				fator = A[i][j]/A[j][j];
				MatrizL[i][j] = fator;
				for(k = j; k < (n-1); k++){
					A[i][k] -= A[j][k]*fator;
				}
		}
	}
}

void imprimeMat(double **A, int n){
	int i,j;
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			printf("%.1lf	",A[i][j]);
		}
		printf("\n");
	}
}

void inicML(double **A, int n){
	int i,j;
		for(i=0; i < n; i++){
			for(j=0; j < n; j++){
				if(i == j){
					A[i][j] = 1;
				}
				else{
					A[i][j] = 0;
				}
			}
		}
}