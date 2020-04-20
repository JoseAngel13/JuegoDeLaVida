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

#include "funcionesSecuencial.h"

/*
 *Función principal que rige el flujo del programa 
 */

int main(int argc, char const *argv[])
{
	short int *malla, *aux;
	short int N = TAMANIO;

	FILE * archivo = fopen("../../mat1000.txt", "r");
	if (archivo==NULL) {fputs ("File error",stderr); exit (1);}

	char caracterAuxiliar;
	malla = (short int *) malloc(N*N*sizeof(short int *));
	aux = (short int *) malloc(N*N*sizeof(short int *));
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			caracterAuxiliar = fgetc(archivo);
			if (caracterAuxiliar == '1'){
				aux[i*N+j]=malla[i*N+j]=1;
			}
			else if(caracterAuxiliar == '0'){
				aux[i*N+j]=malla[i*N+j]=0;
			}
		}
	}

/*
 * Repite el proceso el mismo número de veces.
 *  
 */
	for (int i = 0; i < ITERACIONES; ++i)
	{
		printf("Iteracion %d\n",i+1);
		actualiza(malla,aux,N);
		imprimeM(malla,N);

	}
/*
 * Libera la memoria y cierra el canal con el archivo. 
 */	
	free(malla);
	free(aux);
	fclose(archivo);
	return 0;
}

