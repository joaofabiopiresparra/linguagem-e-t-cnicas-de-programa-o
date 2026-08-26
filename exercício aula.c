#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int a, b, c, r;
	printf("insira 3 valores: ");
	scanf("%d %d %d", &a, &b, &c);
	if(a>b){
		r=a;
	}else{
		r=b;
	}
	if(r<c){
		r=c;
	}
	printf("%d\n",r);
	if(r%2==0) printf("o numero e par"); else printf("o numero e impar");
	return 0;
}
