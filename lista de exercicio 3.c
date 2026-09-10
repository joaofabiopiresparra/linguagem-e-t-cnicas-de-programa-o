#include <stdio.h>              //exercicios 7 8 9
#include <stdlib.h>

float calc_inss (float salario){
	if(salario<= 1412.00) return salario*0.075;
	else if(salario<= 2666.68)return salario*0.09;
	else if(salario <= 4000.00) return salario*0.12;
	else return salario*0.14;
}

float calc_irpf (float salariobase){
	if     (salariobase <= 2259.20) return salariobase;
	else if(salariobase <= 2826.65) return (salariobase*0.075)-169.44;
	else if(salariobase <= 3751.05) return (salariobase*0.15)-381.44;
	else if(salariobase <= 4664.68) return (salariobase*0.225)-662.77;
	else return (salariobase*0.275)-896;
}


int main(int argc, char *argv[]) {
	
	float valorhoras, quantidadehoras, salariobruto, salario, salariobase;
	
	salariobruto = valorhoras * quantidadehoras;
	
	printf("digite o valor das horas e a quantidade de horas trabalhadas no mes: ");
	scanf("\n %f \n %f", &valorhoras, &quantidadehoras);
	
	salario = salariobruto;
	salariobase = calc_inss(salario);
	
	
		


	printf("%f",calc_inss(salario));
	

	printf ("%f",calc_irpf(salariobase));
	
	
	return 0;
}
