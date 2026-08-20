#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {


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
	
	
	
	
		int num, bit;
	printf("insira um numero: ");
	scanf ("%d", &num); // sim, eu fiquei meia hora tentando descobrir pq tava dando errado ate que eu lembrei do & eu o deio o C
	
		while (num>0) {
			bit = num%2;
			num = num/2;
			printf("%d", bit); //nao sei escrever de traz para frente. vai ficar assim mesmo gastei muito tempo tentando emtender o while
		};
		printf ("\n nota-se que o binario esta ao contrario");
	


	


	//exercicio 4








	float salario, vendas;
printf ("insira o valor do seu salario e total do valor de vendas: ");
scanf ("%f \n %f", &salario, &vendas);
salario = salario + vendas*0.15;
printf ("%f", salario);





//exercicio 5








int valor1, valor2, valor3, calculo;
printf("digite 3 valores: \n");
scanf ("%d %d %d", &valor1, &valor2, &valor3);
calculo = valor1+valor2+valor3;
printf ("soma: %d\n", calculo);
calculo = (valor1+valor2+valor3)/3;
printf ("media: %d\n", calculo);
calculo = valor1*valor2*valor3;
printf ("produto: %d\n", calculo);


//exercicio 6









int idade, ano, mes, dia;
printf ("digite sua idade em dias: ");
scanf ("%d", &idade);
ano = idade %365;
mes = ano%12;
dia = mes%30;
printf ("\n %d \n %d \n %d", ano, mes, dia);

return 0;
