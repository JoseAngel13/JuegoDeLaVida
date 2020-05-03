#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif
//CONSTANTES
#define ITERACIONES 100 //Número de veces que se hara el proceso
#define TAMANIO 5000     //Este número se eleva al cuadrado ya que son mallas cuadras
#define DIR_FILE "../../mat5000.txt"
