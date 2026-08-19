#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

/*
// exercicio 1
	
	int a,b;
	printf("escreva dois numeros: \n");
	scanf ("%d", &a);
	scanf ("%d", &b);
	printf ("numeros invertidos: %d  %d\n", b, a);

		
	
	//exercicio 2 
	
	
	
	
	
	int expoente;
	double c;
	printf ("\ninsira um numero: ");
	scanf ("%lf", &c);
	if (c >= 10) {
		while (c >= 10) {
			c = c/10;
			expoente++;
		}
	};
	if (c < 1) {
		while (c <= 1) {
			c = c*10;
			expoente--;
		}
	};
	printf("notação cientifica do numero: %lf * 10^%d", c, expoente);
	
	
	
	
	
	
	
	
	
	
	//exercicio 3
	
	
	*/
	
	int d, resultado;
	printf("insira um numero: ");
	scanf ("%d", d);
	if (d>1) {
		while (d<=1) {
			resultado = d %2;
			d = d/2;
			printf ("%d", resultado);
		}
	};
	
	// nao funcionando  ^	
	
	
	return 0;
}
