/*4. Realice un programa que calcule el promedio 
de los valores de un arreglo de 100 posiciones. 
El programa debe generar el arreglo 
automáticamente y luego llamar una función que 
calcule el promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double promedio (int vec[],int n);
int main(void)
{
	int vec [100];
	int randon;
	double prom;
	srand(time(NULL)); 
	for (int i = 0; i < 100; ++i)
	{
		randon = rand() % 2000;
		vec[i] = randon;
	}

	prom = promedio(vec, 100);
	printf("%.4f \n", prom);
	return 0;

}

double promedio (int vec[], int n){
	double prom =0;
	int suma;
	for (int i = 0; i < n; ++i)
	{
		suma = suma + vec[i];
	}
	prom = suma/n;
	return prom;
}