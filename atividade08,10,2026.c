#include <stdio.h>
#include <stdlib.h>

int main() {
	int valores[10];
	int maior, menor,i;
	printf("digite 10 numeros: ");
	for(i=0;i<10;i++){
	    scanf("%d\n",&valores[i]);
	}
	for(i=1,maior=valores[0];i<5;i++){
		if(maior<valores[i]){
			maior = valores[i];
		}
	}
	for(i=6,menor=valores[5];i<10;i++){
		if(maior<valores[i]){
			menor = valores[i];
		}
	}
	printf("maior numero dos 5 primeiros: %d", maior);
	printf("\nmaior numero dos 5 ultimos: %d", menor);
return 0;
}
