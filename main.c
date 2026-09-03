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
ano = idade /365;
idade %= 365;
mes = idade / 30;
dia = idade % 30;
printf ("\n %d \n %d \n %d", ano, mes, dia);







//exercicio 7





//#include <math.h>

int raio;
printf ("digite um valor: ");
scanf ("%d", &raio);
raio = 3.14*4/3*pow(raio, 3);
printf ("o volume de uma esfera é: %d", raio);







// exercicio 8








int x1,x2,y1,y2;
double distancia;
printf ("digite 4 valores:");
scanf ("%d %d %d %d", &x1, &x2, &y1,&y2);
distancia = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
printf ("a distancia entre os pontos é: %f", distancia);






//lista 2
//exercicio 1





	int idade1;
	printf ("digite sua idade: ");
	scanf ("%d", &idade1);
	idade1 = 2026 - idade1;
	printf ("vc nasceu em %d", idade1);







//exercicio 2




	float velocidade;
	printf ("digite sua velocidade em Km por hora: ");
	scanf("%f", &velocidade);
	velocidade = velocidade / 36;
	printf("sua velocidade em metros por segundo e %f", velocidade);



//exercicio 3



	float dinheiro, cota;
	printf("digite a cotacao e o valor: ");
	scanf("%f %f", &dinheiro, &cota);
	printf("os %d reais sao %d em dolares", dinheiro, (dinheiro/cota));


//exercicio 4





	float celcius;
	printf("digite a temperatura: ");
	scanf("%f", &celcius);
	celcius = celcius * 9 / 5 + 32;
	printf("temperatura e fahrenheit: %f", celcius);






//exercicio 5




	float graus;
	printf("digite o angulo em graus: ");
	scanf("%f", &graus);
	graus = graus * 3.14 / 180;
	printf("o angulo em radianos e: %f", graus);






//exercicio 6

	int numero5;
	printf("digite um numero: ");
	scanf("%d", &numero5);
	printf("o sucesor e %d e o antecesor e %d", (numero5+1), (numero5-1));

//exercicio 7

	int umvalorae = 780000;
	printf("o premio de 780.000 reais sera dividido por 3 vencedores: \n\n o vencedor 1 ganhou: %f \n\n o vencedor 2 ganhou: %f \n\n e o vencedor 3 ganhou: %f", (umvalorae* 0.46), (umvalorae* 0.32), (umvalorae* 0.22));

//exercicio 8

	int sec, min, horas;
	printf("digite um valor em segundos");
	scanf("%d", &sec);
	horas = sec/3600;
	min = (sec - (horas*3600)) /60;
	sec = sec - ((horas*3600) + (min*60));
	printf("\t %d %d %d", horas, min, sec);



return 0;
