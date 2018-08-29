#include "raiz.h"
#include <stdio.h>
#include <math.h>

int bissecao (double a, double b, int p, double (*f) (double x), double* r){
	double fa = f(a);
	double fb = f(b);
	double fc, c;
	double ErroAvaliado = (b - a)/2.0;
	double Tol = 0.5*pow(10.0,-p);
	int numInt = 0;

	if(fa*fb < 0){	// Se tiver sinal invertido
		while(ErroAvaliado > Tol){
		c = (a+b)/2;
		fc = f(c);

		if(fc == 0){
			printf("%d é a raiz da funcao.\n", c);
			break;
		}
		else if(fa*fc < 0){
			b = c;
		}
		else if(fc*fb < 0){
			a = c;
		}
		ErroAvaliado *= 0.5;
		numInt++;
		printf("%d interacao:\nc = %.5lf\nb = %.5lf\na = %.5lf\nErroAvaliado = %.5lf\n\n", numInt, c, b, a, ErroAvaliado);

		}
		*r = c;
	}
	else{
		printf("Sinais nao invertidos nesse intervalo.\n");
		return 0;
	}
	return numInt;
}
int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r){
	double coefPar = det(f,x0,x1,x2);
	double Tol = 0.5*pow(10.0,-p);
	double fx0 = f(x0), fx1 = f(x1), fx2 = f(x2);
	int tentativas = 0,maxTent = 40;
	
	while(abs(fx2) > Tol){
		x0 = x1;
		x1 = x2;
		x2 = coefPar;
		coefPar = det(f,x0,x1,x2);
		printf("Coeficiente do parametro = %.5lf\nx0 = %.5lf\nx1 = %.5lf\nx2 = %.5lf\n\n",coefPar,x0,x1,x2);
		tentativas++;
		if(tentativas > maxTent){
			return maxTent;
	}
	*r = coefPar;
	return tentativas;
}

double det(double (*f) (double x), double x0, double x1, double x2){
	double fx0 = f(x0), fx1 = f(x1), fx2 = f(x2);
	double diagPA, diagSA, diagPAc, diagSAc;		//Diagonal Principal de A, Diagonal Secundária de A, Diagonal Principal de Ac, Diagonal Secundária de Ac
	diagPA = (fx0*fx0*fx1*1) + fx0*1*fx2*fx2 + fx1*fx1*fx2;
	diagSA = fx2*fx2*fx1 + fx2*fx0*fx0 *fx1*fx1*fx0;
	diagPAc = fx0*fx0*fx1*x2 + fx0*x1*fx2*fx2 + fx1*fx1*fx2*x0;
	diagSAc  = fx2*fx2*fx1*x0 + fx2*fx0*fx0*x1 *fx1*fx1*fx0*x2;
	return (diagPAc - diagSAc)/(diagPA - diagSA);
}

