#!/bin/bash

#se crea el archivo c
#pedimos el nombre del archivo que se va a crear
echo "Nombre del archivo"
read nombre
#establecemos la variable de nombre del archivo
filename=$nombre
#usando if determinamos la existencia del nombre del archivo creado
#si el archivo ya existe entonces nos lo indicara
#si no existe entonces creara el archivo
if [ -f "$nombre" ]; then
	echo "El archivo ya existe"
else
	#creamos el archivo de extension c
	`touch $nombre.c`
	#colocamos lo que lleva el header en el archivo
	echo "Ingreso de resumen, entradas y salidas"
	#ingreso del resumen
	echo "resumen"
	read resumen
	fileresume=$resumen
	#ingreso de las entradas
	echo "entradas"
	read entradas
	fileentrada=$entradas
	#ingreso de las salidas
	echo "salidas"
	read salidas
	filesalidas=$salidas
	echo "/*">> $nombre.c
	echo "Autor: `uname -n`">> $nombre.c
	echo "Compilador: `gcc --version | head -n 1`">> $nombre.c
	echo "Compilado: gcc $nombre.c -o $nombre.c">> $nombre.c
	echo "Fecha: `date`">> $nombre.c
	echo "Librerias: stdio, etc.">> $nombre.c
	echo "Resumen: $resumen">> $nombre.c
	echo "Entradas: $entradas">> $nombre.c
	echo "Salidas: $salidas">> $nombre.c
	echo "*/">> $nombre.c
	echo "  ">> $nombre.c
	echo "//Librerias">> $nombre.c
	echo "#include <stdio.h>">> $nombre.c
	echo "//Enumerar los pasos del pseudocodigo">> $nombre.c
	#abrimos el contenido del archivo creado
	vim $nombre.c
fi
