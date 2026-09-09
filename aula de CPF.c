#include <stdio.h>
#include <stdlib.h>                      // não funcionando
	
int multDigito( int dig, int valor){
	return dig*valor;
}


int main(int argc, char *argv[]) {
int dg1, dg2, dg3, dg4, dg5, dg6, dg7, dg8, dg9, dg10, dg11, soma, resto, resto2;
printf (" digite seu cpf: ");
scanf ("%d %d %d . %d %d %d . %d %d %d - %d %d", &dg1, &dg2, &dg3, &dg4, &dg5, &dg6, &dg7, &dg8, &dg9, &dg10, &dg11);

soma = multDigito(dg1,10)+multDigito(dg2,9)+multDigito(dg3,8)+multDigito(dg4,7)+multDigito(dg5,6)+multDigito(dg6,5)+multDigito(dg7,4)+multDigito(dg8,3)+multDigito(dg9,2);
	
soma *= 10 ;
resto = soma%11;
if (resto == 10) resto = 0;
printf("\n%d", resto);

soma = multDigito(dg1,11)+multDigito(dg2,10)+multDigito(dg3,9)+multDigito(dg4,8)+multDigito(dg5,7)+multDigito(dg6,6)+multDigito(dg7,5)+multDigito(dg8,4)+multDigito(dg9,3)+multDigito(dg10,2);

soma *= 10 ;
resto2 = soma%11;
if (resto2 == 10) resto2 = 0;
printf("\n%d", resto2);
	return 0;
}
