#ifndef __FUNCIONESSECUENCIAL_H__
#define __FUNCIONESSECUENCIAL_H__

//CONSTANTES
#define ITERACIONES 	10	//Número de veces que se hara el proceso
#define TAMANIO 		10	//Este número se eleva al cuadrado ya que son mallas cuadras
	
#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif


void imprimeM(short int *m, short int N);
void actualiza(short int *malla, short int *aux, short int N);

#endif