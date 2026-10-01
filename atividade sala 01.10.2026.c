#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int op1,op2, op3, op4, n1, n2, n3, n4, resto, itens, bolsas, conta, unidade, a, b, c, r;
	char c;
	
	switch (op1){
		case 1:
		
			scanf ("%d", &op3);
			switch (op3)
			{
			
			
				case 1:
				
					printf("digite 4 numeros: ");
					scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
					resto = n1 % 2;
					if (resto == 0){
						printf("\no numero %d e par", n1);
					}
					else {
						printf("\no numero %d e impar", n1);
					}
					
					resto = n2 % 2;
					if (resto == 0){
						printf("\no numero %d e par", n2);
					}
					else {
						printf("\no numero %d e impar", n2);
					}
					
					resto = n3 % 2;
					if (resto == 0){
						printf("\no numero %d e par", n3);
					}
					else {
						printf("\no numero %d e impar", n3);
					}
					
					resto = n4 % 2;
					if (resto == 0){
						printf("\no numero %d e par", n4);
					}
					else {
						printf("\no numero %d e impar", n4);
					}
					
					
					resto = n1 % 5;
					if (resto == 0){
						printf("\no numero %d e multiplo de 5", n1);
					}
					else {
						printf("\no numero %d nao e multiplo de 5", n1);
					}
					
					resto = n2 % 5;
					if (resto == 0){
						printf("\no numero %d e multiplo de 5", n2);
					}
					else {
						printf("\no numero %d nao e multiplo de 5", n2);
					}
					
					resto = n3 % 5;
					if (resto == 0){
						printf("\no numero %d e multiplo de 5", n3);
					}
					else {
						printf("\no numero %d nao e multiplo de 5", n3);
					}
					
					resto = n4 % 5;
					if (resto == 0){
						printf("\no numero %d e multiplo de 5", n4);
					}
					else {
						printf("\no numero %d nao e multiplo de 5", n4);
					}
				break;
					
				case 2:
					printf("digite respectivamente a quantidade de itens e a capacidade de cada bolsa/mochila: ");
					scanf("%d %d", &itens, &bolsas);
					conta = itens / bolsas;
					resto = itens % bolsas;
					if (resto == 0){
						printf("a quantidade de bolsas minimas para guardar os itens e: %d", conta);
					}
					else {
						printf("a quantidade de bolsas minimas para guardar os itens e: %d", conta+1);
					}
				break;
				
				case 3:
					scanf("%d",&op2);
					switch (op2){
						case 1:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1.8+32;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 2:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = (unidade-32)/1.8;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 3:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade+273.15;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 4:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/1609.34;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 5:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1609.34;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 8:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*2.205;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 9:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/2.205;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 10:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/1.609;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 11:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1.609;
							printf("unidade convertida: %d", unidade);
						break;
					}
				break;	
			}
		break;
		
		case 2:
			scanf("%d", &op4);
			switch (op4){
				
				case 1:
					scanf("%d",&op2);
					switch (op2){
						case 1:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1.8+32;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 2:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = (unidade-32)/1.8;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 3:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade+273.15;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 4:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/1609.34;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 5:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1609.34;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 8:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*2.205;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 9:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/2.205;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 10:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade/1.609;
							printf("unidade convertida: %d", unidade);
						break;
						
						case 11:
							printf("digite a unidade a ser convertida: ");
							scanf("%d", &unidade);
							unidade = unidade*1.609;
							printf("unidade convertida: %d", unidade);
						break;
					}
				break;
				
				case 2:
					printf("digite 3 numeros: ");
					scanf("%d %d %d",&a, &b, &c);
					if (a=b) or (a=c) or (b=c) {
						printf("os numeros tem que ser distintos");
					}
					else{
						if (a>b){
							r = a
						}
						else{
							r = b
						}
						if (r>c){
							printf("%d", r);
						}
						else{
							printf("%d", c);
						}
						
						printf("%d", r);
						
						if (r>a){
							printd("%d", a);
						}
						else {
							printf("%d", b);
						}
					}
				break;
				
				case 3:
					printf("digite respectivamente 1 valor; 1 simbolo operacional [>] ou [<] ou [==] ou [!=]; 1 valor");
					scanf("%d %c %d",&n1, &c, &n2);
					if (c == '>'){
						if (n1>n2){
							printf("a conta %d > %d e falsa", n1, n2)
						}
					}
			}
			
	}
	
	return 0;
}
