#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMARCHIVOS 4

int main(int argc, char const *argv[])
{

	int tam[NUMARCHIVOS] = {20, 500, 1000, 5000};
	FILE * archivo[NUMARCHIVOS]; 

	archivo[0] = fopen("mat100.txt", "w");
	archivo[1] = fopen("mat500.txt", "w");
	archivo[2] = fopen("mat1000.txt", "w");
	archivo[3] = fopen("mat5000.txt", "w");
	srand (time(NULL));

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < tam[i]; ++j)
		{
			for (int k = 0; k < tam[i]; ++k)
			{
				fprintf(archivo[i], "%d", rand()%2);
			}
			fprintf(archivo[i], "\n");
		}
		fclose(archivo[i]);
	}


//fclose(archivo);
	return 0;
}