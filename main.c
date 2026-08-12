#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float area, BASE, base, altura;
	printf ("insira o valor da base maior, base menor e altura do trapesio: ");
	scanf ("%f", &BASE);
	scanf ("%f", &base);
	scanf ("%f", &altura);	
	area = ((BASE+base)*altura)/2;
	
	printf ("a area do trapesio e %f", area);

	return 0;
}
