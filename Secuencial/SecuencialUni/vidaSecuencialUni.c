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
	int tamanio;
	double  res;
	FILE *resultados = fopen("resultados.txt", "w");
	if(resultados == NULL ) {
    	printf("No fue posible abrir el archivo\n");
    	return -1;
	}

	fprintf (resultados, "Ejecución nueva \n");
		fprintf (resultados, "Número de iteraciones %d\n",ITERACIONES);
	fprintf(resultados, "TAM\tINT\tLONG\tFLOAT\tDOUBLE\n");


	for (tamanio = 100; tamanio < 110; tamanio = tamanio + 10)
	{
		fprintf(resultados, "%d\t",tamanio);

		printf("Inicia el programa con el tipo INT\n");
		res = GOL_int(tamanio);
		fprintf ( resultados, "%f\t",res);

		printf("Inicia el programa con el tipo LONG\n");
		res = GOL_long(tamanio);
		fprintf ( resultados, "%f\t",res);

		printf("Inicia el programa con el tipo FLOAT\n");
		res = GOL_float(tamanio);
		fprintf ( resultados, "%f\t",res);

		printf("Inicia el programa con el tipo DUBLE\n");
		res = GOL_double(tamanio);
		fprintf ( resultados, "%f\t",res);
		fprintf ( resultados, "\n");
	}


	printf("Finaliza\n");
	fclose(resultados);
	return 0;
}

