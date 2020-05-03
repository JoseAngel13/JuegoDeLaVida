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

	printf("Inicia el programa con el tipo LONG\n");
	GOL_long();

	printf("Inicia el programa con el tipo FLOAT\n");
	GOL_float();

	//printf("Inicia el programa con el tipo DUBLE\n");
	//GOL_double();

	printf("Finaliza\n");


	

	

	
	return 0;
}

