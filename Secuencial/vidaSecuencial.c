#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>


/*
 *Funcion para imprimir la matriz 
 */
void imprimeM(int **m, int fil, int col){
	for (int i = 0; i < fil; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (m[i][j]==1)
			{
				printf("* ");
			}
			else{
				printf("- ");
			}
		}
		printf("\n");
	}
}

/*
 *Funcion para actualizar la matriz, intercambiandola entre la auxiliar
 *y la matriz principal.  
 */
void actualiza(int **malla,int **aux, int fil, int col){
	int contador=0;
	for (int i = 0; i < fil; ++i)
	{	
		for (int j = 0; j < col; ++j)
		{
			//Izquierda Arriba
			if(i>0 && j>0 && malla[i-1][j-1]==1){
				contador++;
			}
			//Arriba
			if(i>0 && malla[i-1][j]==1){
				contador++;
			}
			//Arriba derecha
			if(i>0 && j<col && malla[i-1][j+1]==1){
				contador++;
			}
			//Izquieda
			if(j>0 && malla[i][j-1]==1){
				contador++;
			}
			//Derecha
			if(j<col && malla[i][j+1]==1){
				contador++;
			}
			//Abajo izquieda
			if(i<fil-1 && j>0 && malla[i+1][j-1]==1){
				contador++;
			}
			//Abajo
			if(i<fil-1 && malla[i+1][j]==1){
				contador++;
			}
			//Abajo derecha
			if(i<fil-1 && j<col && malla[i+1][j+1]==1){
				contador++;
			}

			if(malla[i][j]==1){//Actuamos sobre las celulas en la copia de la matriz
				if(contador==2 || contador==3){//La celulas vivas con 2 o 3 celulas vivas pegadas, se mantiene vivas.
					aux[i][j]=1;
				}
                else{//Si no se cumple la condicion, mueren.
					aux[i][j]=0;
                    }
                }
            else{
                if(contador==3){//Las celulas muertas con 3 celulas vivas pegadas, resucitan.
					aux[i][j]=1;
					}
				}
			contador=0;
		}
	}
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			malla[i][j]=aux[i][j];//Copiamos la matriz origen en destino
		}
	}
}

/*
 *Funcion principal que rige el flujo del programa 
 */

int main(int argc, char const *argv[])
{
	int **malla, **aux, i, j, fil, col, iteaciones = 20;
	FILE * archivo = fopen("../mat100.txt", "r");
	if (archivo==NULL) {fputs ("File error",stderr); exit (1);}
	char caracterAuxiliar;

/*	printf("Fila \n");
	scanf("%d",&fil);
	fflush(stdin);
	printf("Columna\n");
	scanf("%d",&col);
	fflush(stdin);
	system("clear");*/
	fil = 20;
	col = 20;
	malla = (int **) malloc(fil*sizeof(int *));
	aux = (int **) malloc(fil*sizeof(int *));
	
	for (i = 0; i < fil; ++i){
		*(malla+i) = (int *)malloc(col*sizeof(int));
		*(aux+i) = (int*)malloc(col*sizeof(int));
		}

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			caracterAuxiliar = fgetc(archivo);
			if (caracterAuxiliar == '1'){
				aux[i][j]=malla[i][j]=1;
			}
			else if(caracterAuxiliar == '0'){
				aux[i][j]=malla[i][j]=0;
			}
			printf("%c",caracterAuxiliar );
		}
	}

	do
	{
		printf("Malla\n");
		imprimeM(malla,fil,col);
		actualiza(malla,aux,fil,col);
		iteaciones-=1;
	} while (iteaciones!=0);

	free(malla);
	free(aux);
	fclose(archivo);
	return 0;
}

