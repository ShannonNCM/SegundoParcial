#include <stdio.h>
#include <math.h>

//Se colocan los prototipos de las funciones
//sumatoriaxy
float sumxy(float x[6],float y[6]);
//sumatoriax
float sumx(float x[6]);
//sumatoriay
float sumy(float y[6]);
//sumatoriax2
float sumx2(float x[6])
//pendiente m
float m(float sumxy, float sumx, float sumy, float sumx2, int n);
//intercepto b
float b(float sumax, float sumay, float m, int n);
//error pendiente deltam
float deltam(float sumx2, float sumx, float error, int n);
//error del intercepto deltab
float deltab(float error, int n);

//Se definen las funciones
//sumatoriaxy
float sumxy(float x[6],float y[6])
{
	for(i=0;i<=n;i++){
		sumaxy=sumxy+x[i]*y[i];
	}
}
//sumatoriax
float sumx(float x[6])
{
	for(i=0;i<=n;i++){
		sumx=sumx+x[i];
	}
}
//sumatoriay
float sumy(float y[6])
{
	for(i=0;i<=n;i++){
		sumy=sumy+y[i];
	}
}
//sumatoriax2
float sumx2(float x[6])
{
	for(i=0;i<=n;i++){
		sumx2=sumx2+x[i]*x[i];
	}
}
//pendiente m
float m(float sumxy, float sumx, float sumy, float sumx2, int n)
{
	m=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
}
//intercepto b
float b(float sumax, float sumay, float m, int n)
{
	b=(sumy-(m*sumx)/n;
}
//error pendiente deltam
float deltam(float sumx2, float sumx, float error, int n)
{
	deltam=(sqrt(n)*error)/sqrt((n*sumx2)-(sumx*sumx));
}
//error del intercepto deltab
float deltab(float error, int n)
{
	deltab=error/sqrt(n);
}


void main(void)
{
	//Se definen las variables
	float X,Y,e,M,B,dM,dB;
	int N,i;
	//Se ingresan los datos
	printf("Ingresar numero de terminos n:");
	scanf("%d",&N)
	printf("Ingresar valores de tension");
	for(i=0;i<=N-1;i++){
		scanf("%f",&X[i]);
	}
	printf("Ingresar valores de longitud de onda");
	or(i=0;i<=N-1;i++){
                scanf("%f",&Y[i]);
        }
	//Se llama a las funciones
	M=m(sumatoriaxy, sumatoriax, sumatoriay, sumatoriax2, n);
	printf("pendiente %f\n",M);
	B=b(sumatoriax, sumatoriay, pendiente, N);
	printf("intercepto %f\n",B);	
	dM=deltam(sumatoriax2, sumatoriax, e, N);
	printf("error pendiente %f\n",dM);
	dB=deltab(e,N);
	printf("error intercepto %f\n",dB);
	printf("La aproximacion por minimos cuadrados es: y=(%f+-%f)x+(%f+-%f)\n",M,dM,B,dB);
}
