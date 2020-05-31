#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 10000           //Tamaño del tablero potencias de 2 a partir de 16 
#define BLOCK_SIZE 16	
#define ITERACIONES 300	//numero de cambios totales del autómata


/*
 * Funcion para actualizar la matriz, intercambiandola entre la auxiliar
 * y la matriz principal.  
 */
__global__ void actualiza(int *malla, int *aux){
	int contador=0;
	int celActual;
	int i = blockDim.x * blockIdx.x +  threadIdx.x; //fila
    int j = blockDim.y * blockIdx.y + threadIdx.y; //Columna
	if (i < N && j < N) {
	celActual = i*N+j;
	//printf("%d ",celActual);
	//Izquierda Arriba
	if(i>0 && j>0 && malla[celActual-N-1]==1){
		contador++;
	}
	//Arriba
	if(i>0 && malla[celActual-N]==1){
		contador++;
	}
	//Arriba derecha
	if(i>0 && j<N-1 && malla[celActual+1-N]==1){
		contador++;
	}
	//Izquierda
	if(j>0 && malla[celActual-1]==1){
		contador++;
	}
	//Derecha
	if(j<N-1 && malla[celActual+1]==1){
		contador++;
	}
	//Abajo izquierda
	if(i<N-1 && j>0 && malla[celActual+N-1]==1){
		contador++;
	}
	//Abajo
	if(i<N-1 && malla[celActual+N]==1){
		contador++;
	}
	//Abajo derecha
	if(i<N-1 && j<N-1 && malla[celActual+1+N]==1){
		contador++;
	}

	if(malla[celActual]==1){		//Actuamos sobre las celulas en la copia de la matriz
		if(contador==2 || contador==3){//La celulas vivas con 2 o 3 celulas vivas pegadas, se mantiene vivas.
			aux[celActual]=1;
		}
		else{					//Si no se cumple la condicion, mueren.
			aux[celActual]=0;
			}
		}
	else{
		if(contador==3){		//Las celulas muertas con 3 celulas vivas pegadas, resucitan.
			aux[celActual]=1;
			}
		}
	contador=0;
	}


}

__global__ void copiaMatriz(int *malla, int *aux){
	int celActual;
	int i = blockDim.x * blockIdx.x +  threadIdx.x; //fila
    int j = blockDim.y * blockIdx.y + threadIdx.y; //Columna
	if (i < N && j < N) {
		celActual = i*N+j;
		aux[celActual] = malla[celActual];
	}
}


/*
 * Funcion para imprimir la matriz 
 * Como entradas son la malla y el tamaño
 */
__global__ void imprimeM(int *m){
//void imprimeM(int *m){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (m[i*N+j]==1)
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


int main() {
    //Cambiar tipos de datos
    //int float double long
    int *tablero, *tablero_aux;
	int *d_tablero, *d_tablero_aux;
	clock_t  inicio, final;
    size_t size = N*N * sizeof(int);

    //Asignacion de memoria del lado del host
    tablero = (int*)malloc(size);
    tablero_aux = (int*)malloc(size);
    

    //Asignacion de memoria del lado de device
    cudaMalloc(&d_tablero, size);
    cudaMalloc(&d_tablero_aux, size);
	
	FILE * archivo = fopen("../mat5000.txt", "r");
	if (archivo==NULL) {fputs ("File error",stderr); exit (1);}

	char caracterAuxiliar;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			caracterAuxiliar = fgetc(archivo);
			if (caracterAuxiliar == '1'){
				tablero_aux[i*N+j]=tablero[i*N+j]=1;
			}
			else {
				tablero_aux[i*N+j]=tablero[i*N+j]=0;
			}
		}
	}

	fclose(archivo);
    
	printf("\n");


    cudaMemcpy(d_tablero,tablero,size,cudaMemcpyHostToDevice);
    cudaMemcpy(d_tablero_aux,tablero_aux,size,cudaMemcpyHostToDevice);


    //VOLVER CONSTANTE
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
    dim3 dimGrid((N + dimBlock.x-1)/dimBlock.x, (N+dimBlock.y-1)/dimBlock.y);
    
    /*
    * Repite el proceso el mismo número de veces.
    *  
    */
	//tiempo inicial
	inicio = clock();
	//imprimeM<<<1,1>>>(d_tablero);
	cudaThreadSynchronize();
	for (int i = 0; i < ITERACIONES; ++i)
	{
	 	//printf("Iteracion %d\n",i+1);
		actualiza<<<dimGrid,dimBlock>>>(d_tablero,d_tablero_aux);
		cudaThreadSynchronize();//espera a que todos los hilos terminen su ejecución
		copiaMatriz<<<dimGrid,dimBlock>>>(d_tablero_aux,d_tablero);
		cudaThreadSynchronize();
		//imprimeM<<<1,1>>>(d_tablero);
		//cudaThreadSynchronize();
	}
	final = clock();
	double tiempo = ((double)final - inicio) / CLOCKS_PER_SEC;
	printf("el tiempo final es %f", tiempo);
	//timepo final

    free(tablero);
    free(tablero_aux);

    cudaFree(d_tablero);
    cudaFree(d_tablero_aux);

    return 0;
}