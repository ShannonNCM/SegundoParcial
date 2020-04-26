/*
Autor: shannon-pc
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc Problema2.c -o Problema2.c
Fecha: mar abr 21 14:17:31 CST 2020
Librerias: stdio, etc.
Resumen: El programa obtiene la raiz aproximada de la funcion cos(x)/sin(x) en un intervalo indicado por el usuario si existe.
Entradas: Limites de los intervalos enteros o decimales, numero de iteraciones entero y tolerancia en decimales.
Salidas: Raiz aproximada de la funcion decimales, numero de iteraciones enteros.
*/
  
//Librerias
#include <stdio.h>
#include <math.h>


//Se colocan los  prototipos de las funciones
//La funcion a evaluar
float f(float x);
//La funcion del metodo de biseccion
void Biseccion(float xa, float xb, float tol, int itmax, int iter, float xp);

//Se definen las funciones
//Funcion a evaluar
float f(float x)
{
	return cos(x)/sin(x);
}

//Metodo de Biseccion
void Biseccion(float xa, float xb, float tol, int itmax, int iter, float xp)
{
	//
	float xpant, error, prod;
	iter=0;
	xa=0;
	//Se verifica si hay cambio de signo en el intervalo, esto nos indica si existe raiz dentro del intervalo ingresado
	if(f(xa)*f(xb)>0){
		printf("\nNo existe raiz en el intervalo\n");
	}else{
		printf("\nIter Raiz Error\n");
		//Si la raiz existe en el intervalo, se realizan las iteraciones
		do
		{
			iter++;
			xpant=xp;
			//Se realiza el calculo la raiz aproximada
			xp=(xa+xb)/2;
			//Se cacula el error
			error=fabs((xp-xpant)/xp);
			//Se calcula el producto de la funcion valuada en el limite inferior y la raiz aproximada
			prod=f(xa)*f(xp);
			//Se evalua el producto para realizar cambio en el limite del intervalo
			if(prod<0){
				xb=xp;
			}else if(prod>0){
				xa=xp;
			}else{
				printf("Se ha encontrado la raiz, la raiz es %f",xp);
			}
			//Se presentan los datos obtenidos en las iteraciones
			printf("\n%d %f %f",iter,xp,error);
		}while(error>tol && iter<itmax);
		printf("\nLa raiz se encontro en la %d iteracion, la raiz es %f\n",iter,xp);
	}
}

void main(void)
{
	//Se definen las variables
	//a y b son los puntos en el intervalo donde se encuentra la raiz, raiz es el la raiz de la funcion que se busca, miteraciones es el maximo de iteraciones, iteracioes son las iteraciones realizadas
	float a, b, tolerancia, raiz;
	int miteraciones, iteraciones;
	//Se pide al usuario que ingrese los datos
	//Ingreso del valor del intervalo donde se encuentra la raiz
	printf("Ingrese el valor inicial del intervalo 'a' ");
	scanf("%f",&a);
	//Ingreso del valor b del intervalo donde se encuentra la raiz
	printf("Ingrese el valor final del intervalo 'b' ");
	scanf("%f",&b);
	//Ingreso del numero de iteraciones maximo
	printf("Ingrese el numero maximo de iteraciones ");
	scanf("%d",&miteraciones);
	//Ingreso del la tolerancia
	printf("Ingrese el valor de tolerancia en decimales ");
	scanf("%f",&tolerancia);
	//Aplicacion del metodo de Biseccion
	//Se llama a la funcion del metodo de Biseccion
	Biseccion(a, b, tolerancia, miteraciones, iteraciones, raiz);
}	
