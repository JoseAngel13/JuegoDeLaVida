#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif
//CONSTANTES
#define ITERACIONES 1 //Número de veces que se hara el proceso
#define TAMANIO 10     //Este número se eleva al cuadrado ya que son mallas cuadras
