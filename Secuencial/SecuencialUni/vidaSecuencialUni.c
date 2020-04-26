/********************************************
 ********************************************
 *                                          *
 *    José Ángel de Jesús García Vázquez    *
 *                                          *
 *           El juego de la vida            *
 *                Secuencial                *
 *                                          *
 ********************************************
 ********************************************/

#include "funcionesSecuencial_int.h"
#include "funcionesSecuencial_float.h"
#include "funcionesSecuencial_long.h"
#include "funcionesSecuencial_double.h"

/*
 *Función principal que rige el flujo del programa 
 */

int main(int argc, char const *argv[])
{
	printf("Inicia el programa con el tipo INT\n");
	GOL_int();
	printf("Termina el tipo INT e inicia FLOAT\n");
	GOL_float();
	printf("Termina el tipo FLOAT e inicia LONG\n");
	GOL_long();
	printf("Termina el tipo LONG e inicia DOUBLE\n");
	GOL_double();
	return 0;
}

