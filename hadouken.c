#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int a, b;
	double r;
	printf ("digite 2 numeros: ");
	scanf ("%d %d", &a, &b);
	if ((a>0) && (b>0)){
		if ((a<10) && (b<10)){
			if ((a==2 || a==3 || a==5 || a==7) && (b==2 || b==3 || b==5 || b==7 )){
				r = sqrt(pow(a, 2) + pow(b, 2));
				printf ("hipotenusa: %f", r);
				}else{
				r = a*b;
				printf ("produto: %f", r);
				}
			}else{
			if (a %b == 0){
			printf ("os numeros sao divisiveis");
				}else{
				printf ("os numeros nao sao divisiveis");
				}
			}
	}else{
			printf("inverso: %d %d", a*-1, b*-1);
		}
	return 0;
}
