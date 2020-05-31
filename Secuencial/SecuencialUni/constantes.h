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
#define ITERACIONES 30 //Número de veces que se hara el proceso
//1000 y 10000
#define DIR_FILE "../../mat5000.txt"
