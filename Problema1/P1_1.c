#include <stdio.h>
#include <math.h>

//Se colocan los prototipos de las funciones

//Se definen las funciones
//Minimos cuadrados
void Minimoscuadrados(float x[10], float y[10], int n, float err)
{
	float sumx=0, sumy=0, sumx2=0, sumxy=0;
	float m, b, deltam, deltab;
	int i;
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
	printf("La aproximacion por minimos cuadrados es: y=(%f+-%f)x+(%f+-%f)\n",m,b,deltam,deltab);
}

void main(void)
{
	//Se definen las variables
	float X[10],Y[10],error;
	int N,i;
	//Se ingresan los datos
	printf("Ingresar numero de terminos n:\n");
	scanf("%d",&N);
	printf("Ingresar el error:\n");
	scanf("%f",&error);
	printf("\nIngresar valores de tension\n");
	for(i=0;i<=N-1;i++){
		scanf("%f",&X[i]);
	}
	printf("\nIngresar valores de longitud de onda\n");
	for(i=0;i<=N-1;i++){
                scanf("%f",&Y[i]);
        }
	//Se llama a la funcion
	Minimoscuadrados(&X[10],&Y[10],N,error);
}
