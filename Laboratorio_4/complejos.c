#include <stdio.h>

typedef struct{
	int parteReal;
	int parteImaginaria;
}numComplejo;

numComplejo sumarComplejos(numComplejo c1, numComplejo c2);
numComplejo restarComplejos(numComplejo c1, numComplejo c2);
numComplejo multiplicarComplejos(numComplejo c1, numComplejo c2);

int main()
{
	 numComplejo a, b, c;

    printf("Ingrese el primer numero complejo: \n");
    printf("Parte real: ");
   // setbuf(stdin, NULL);
    scanf("%d", &a.parteReal);
    printf("Parte imaginaria: ");
   // setbuf(stdin, NULL);
    scanf("%d", &a.parteImaginaria);

    printf("Ingrese el segundo numero complejo: \n");
    printf("Parte real: ");
   // setbuf(stdin, NULL);
    scanf("%d", &b.parteReal);
    printf("Parte imaginaria: ");
   // setbuf(stdin, NULL);
    scanf("%d", &b.parteImaginaria);

    c = sumarComplejos(a, b);
    printf("Suma: %d + (%di)\n", c.parteReal, c.parteImaginaria);

    c = restarComplejos(a, b);
    printf("Resta: %d + (%di)\n", c.parteReal, c.parteImaginaria);

    c = multiplicarComplejos(a, b);
    printf("Multiplicacion: %d + (%di)\n", c.parteReal, c.parteImaginaria);
	return 0;
}

numComplejo sumarComplejos(numComplejo c1, numComplejo c2){
	numComplejo solucion;
	solucion.parteReal= c1.parteReal + c2.parteReal;
	solucion.parteImaginaria= c1.parteImaginaria + c2.parteImaginaria;

	return solucion;
}

numComplejo restarComplejos(numComplejo c1, numComplejo c2) {
    numComplejo solucion;
    solucion.parteReal = c1.parteReal - c2.parteReal;
    solucion.parteImaginaria = c1.parteImaginaria - c2.parteImaginaria;
    return solucion;
}
numComplejo multiplicarComplejos(numComplejo c1, numComplejo c2) {
    numComplejo solucion;
    solucion.parteReal = (c1.parteReal * c2.parteReal) - (c1.parteImaginaria * c2.parteImaginaria);
    solucion.parteImaginaria = (c1.parteReal * c2.parteImaginaria) + (c1.parteImaginaria * c2.parteReal);
    return solucion;
}