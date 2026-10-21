#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int op, i, maior;
	int valor[5];
//	switch (op){
//		case 1:
			for(i=0;i<=4;i++){
				printf("digite o %d numero: ",i+1);
				scanf("%d", &valor[i]);
			}
			for(i=4;i>=0;i--){
				printf("%d, ",valor[i]);
			}
			for(i=0,maior=valor[0];i<=4;i++){
				if(maior<valor[i]){
					maior = valor[i];
				}
			}
//	}
	return 0;
}
