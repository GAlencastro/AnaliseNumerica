#include <stdio.h>
#include "Matriz.c"

int main (void){
	int i,j;
	double *vet = vetcria(3);
	double *vetRes = vetcria(3);
	double **mat1 = matcria(3,3);
	double **mat2 = matcria(3,3);
	double ind = 1.0;
	for(i=0; i<3; i++){
		vet[i] = 3;
	} 
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			mat1[i][j] = ind;
			printf("Linha %d e Coluna %d = %.1lf\n", i,j, mat1[i][j]);
			ind++;
		}
	}

	transposta(3,3,mat1,mat2);
	printf("\n\n\n");

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Linha %d e Coluna %d = %.1lf\n", i,j, mat2[i][j]);
		}
	}
	printf("\n\n\n");
	multmv(3,3,mat1,vet,vetRes);
	for(i=0; i<3; i++){
		printf("Termo %d = %.1lf\n",i,vetRes[i]);
	}
	vetlibera(vet);
	vetlibera(vetRes);
	matlibera(3,mat1);
	matlibera(3,mat2);
	return 0;
}
