#include <stdio.h>
#include <math.h>

//Se colocan los prototipos de las funciones

//Se definen las funciones

void main(void)
{
	//Se definen las variables
	float x[5]={4.694,1.264,0.578,0.284,0.196};
	float y[5]={3,1.5,1,0.75,0.6};
	float error=0.001;
	int n=5;
	float sumx=0, sumy=0, sumx2=0, sumxy=0;
        float m, b, deltam, deltab;
        int i;
        //Realizacion de las sumatorias
        for(i=0;i<=5;i++){
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
        deltam=(sqrt(n)*error)/sqrt((n*sumx2)-(sumx*sumx));
        deltab=error/sqrt(n);
        //Se presenta el resultado de la aproximacion
        printf("La aproximacion por minimos cuadrados es:\n y=(%f+-%f)x+(%f+-%f)\n",m,b,deltam,deltab);
}
