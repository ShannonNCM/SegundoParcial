/*
Autor: shannon-pc
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc Problema1.c -o Problema1.c
Fecha: sáb abr 25 11:02:30 CST 2020
Librerias: stdio, etc.
Resumen: El siguiente programa realizar una grafica que compara los valores de tension y longitud de onda y la recta que mejor aproxima el comportaiento de los mismo, asi como calcula la densidad lineal de la cuerda y la longitud de onda cuando la tension es 6N.
Entradas: Vectores con decimales
Salidas: Decimales
*/
  
//Librerias
#include <stdio.h>
#include <math.h>

//Enumerar los pasos del pseudocodigo
void main(void)
{
        //Se definen las variables
        float x[5]={4.694,1.264,0.578,0.284,0.196};
        float y[5]={3,1.5,1,0.75,0.6};
        float error=0.001;
        int n=5;
        float sumx=0, sumy=0, sumx2=0, sumxy=0, sumy2=0;
        float m, b, deltam, deltab, r;
        int i;
        //Realizacion de las sumatorias
        for(i=0;i<=5;i++){
                sumx=sumx+x[i];
                sumy=sumy+y[i];
                sumx2=sumx2+(x[i]*x[i]);
                sumy2=sumy2+(y[i]*y[i]);
                sumxy=sumxy+(x[i]*y[i]);
        }
	//Se calcula el valor de la pendiente y el intercepto con sus errores
        //pendiente m
        m=((n*sumxy)-(sumx*sumy))/((n*sumx2)-(sumx*sumx));
        //printf("pendiente %f\n",m);//
        b=(sumy-(m*sumx))/n;
        deltam=(sqrt(n)*error)/sqrt((n*sumx2)-(sumx*sumx));
        deltab=error/sqrt(n);
        //Se calcula el valor de r
        r=((n*sumxy)-(sumx*sumy))/sqrt(((n*sumx2)-(sumx*sumx))*((n*sumy2)-(sumy*sumy)));
        //Se presenta el resultado de la aproximacion
        printf("La aproximacion por minimos cuadrados es:\n y=(%f+-%f)x+(%f+-%f)\n",m,b,deltam,deltab);
        //Se presenta el valor de correlacion
        printf("El coeficiente de correlacion es:\n %f",r);

        //Se calcula el valor de la longitud de onda en T=6N
        float lo;
        float errorlo;
        lo=(m*6)+b;
	//El error de la tension
        errorlo=(lo*deltam)+deltab;
        printf("\nLa longitud de onda en una tension de 6N es:\n %f+-%f\n",lo,errorlo);
}
