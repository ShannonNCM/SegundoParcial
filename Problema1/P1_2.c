#include <stdio.h>
#include <math.h>

//Se colocan los prototipos de las funciones

//Se definen las funciones
//Minimos cuadrados
void Minimoscuadrados(float x[5], float y[5], int n, float err)
{
	float sumx=0, sumy=0, sumx2=0, sumxy=0;
	float m, b, deltam, deltab;
	int i=0;
	//Realizacion de las sumatorias
	for(i=0;i<=n;i++){
		sumx=sumx+x[i];
		sumy=sumy+y[i];
		sumx2=sumx2+(x[i]*x[i]);
		sumxy=sumxy+(x[i]*y[i]);
	}
	//Se calcula el valor de la pendiente y el intercepto con sus errores
	//pendiente m
	m=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
	printf("pendiente %f\n",m);
	b=(sumy-(m*sumx))/n;
	deltam=(sqrt(n)*err)/sqrt((n*sumx2)-(sumx*sumx));
	deltab=err/sqrt(n);
	//Se presenta el resultado de la aproximacion
	printf("La aproximacion por minimos cuadrados es:\n y=(%f+-%f)x+(%f+-%f)\n",m,b,deltam,deltab);
}

void main(void)
{
	//Se definen las variables
	float X[5]={4.694,1.264,0.578,0.284,0.196};
	float Y[5]={3,1.5,1,0.75,0.6};
	float error=0.001;
	int N=5;
	//Se llama a la funcion
	Minimoscuadrados(&X[5],&Y[5],N,error);
}
