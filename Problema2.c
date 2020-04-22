/*
Autor: shannon-pc
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc Problema2.c -o Problema2.c
Fecha: mar abr 21 14:17:31 CST 2020
Librerias: stdio, etc.
Resumen: El programa obtiene la raiz aproximada de la funcion cos(x)/sin(x) en un int
Entradas: Dos numeros reales
Salidas: Numero real
*/
  
//Librerias
#include <stdio.h>
#include <math.h>


//Se colocan los  prototipos de las funciones
//La funcion a evaluar
float f(float x);
//La funcion del metodo de biseccion
void Biseccion(float a, float b, float tol, int itermax, int iter, float sol);

//Se definen las funciones
//Funcion a evaluar
float f(float x)
{
	float res=0;
	res=cos(x)/sin(x);
	return res;
}

//Metodo de Biseccion
void Biseccion(float a, float b, float tol, int itermax, int iter, float sol)
{
	//Se definen las variables locales
	float x1, x2, c, d, p, fa, fb, prod, error;
	int i=1;
	x1=a;
	x2=b;
	//Se determina la aproximacion a la raiz
	p=(x1+x2)/2;
	//Se evalua los valores de a y b del intervalo [a,b] en la funcion
	fa=f(x1);
	fb=f(x2);
	//Se realiza el producto de fa con fb
	prod=fa*fb;
	//Primera iteracion
	//Se evalua el producto de fa y fb
	//Si el producto es igual a cero se ha encontrado la raiz
	//Si el producto es menor que cero se cambia el intervalo a [p,b]
	//Si el producto es mayor que cero se cambia el intervalo a [a,p]
	if(prod=0){
		printf("Se ha encontrado la raiz, la raiz es: %f",p);
	}else if(prod<0){
		a=p;
	}else{
		b=p;
	}
	//Realizar todas las iteraciones
	//Calcular el error (aca lo calculo como lo aprendi en inge)
	error=(b-a)/2;
	while(error>tol && i<itermax){
		x1=c;
		x2=d;
		p=(x1+x2)/2;
		fa=f(x1);
		fb=f(x2);
		i++;
	}
	//Respuesta
	sol=p;
	iter=i;
}

void main(void)
{
	//Se definen las variables
	//A y B son los puntos en el intervalo donde se encuentra la raiz, raiz es el la raiz de la funcion que se busca, miteraciones es el maximo de iteraciones, iteracioes son las iteraciones realizadas
	float A, B, tolerancia, raiz;
	int miteraciones, iteraciones;
	//Se pide al usuario que ingrese los datos
	//Ingreso del valor del intervalo donde se encuentra la raiz
	printf("Ingrese el valor inicial del intervalo 'a'");
	scanf("%f",&A);
	//Ingreso del valor b del intervalo donde se encuentra la raiz
	printf("Ingrese el valor final del intervalo 'b'");
	scanf("%f",&B);
	//Ingreso del numero de iteraciones maximo
	printf("Ingrese el numero maximo de iteraciones");
	scanf("%d",&miteraciones);
	//Aplicacion del metodo de Biseccion
	//Se llama a la funcion del metodo de Biseccion
	Biseccion(A, B, tolerancia, miteraciones, iteraciones, raiz);
	//Se evalua si el numero de iteraciones realizadas es el del maximo entonces no se ha encontrado la raiz con el metodo
	if(iteraciones=miteraciones){
		printf("No se encontro la raiz despues de %d iteraciones",iteraciones);
	}
	else{
		printf("Se encontro la raiz despues de %d iteraciones, la raiz es: %f",iteraciones,raiz);
	}
}	
