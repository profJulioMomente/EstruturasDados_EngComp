#include<stdio.h>
#include<stdlib.h>

float soma(float valor1, float valor2);
void soma2(float valor1, float valor2);
float soma3();
void soma4();
	
main() {
	float a, b, s;
	
	/*printf("Informe o valor a: ");
	scanf("%f", &a);
	
	printf("Informe o valor b: ");
	scanf("%f", &b);
	*/
	
	//s = soma3();
	s = soma(a,b);
	//printf("soma = %f\n",s);
	
	//soma2(a,b);
	
	soma4();
	soma4();
	system("pause");
}

float soma(float valor1, float valor2){
	float resultado;
	
	resultado = valor1+valor2;
	return resultado;
}

void soma2(float valor1, float valor2){
	float resultado;
	
	resultado = valor1+valor2;
	printf("Soma = %f\n", resultado);
}

float soma3(){
	float valor1, valor2, resultado;
	
	printf("Informe o valor1: ");
	scanf("%f", &valor1);
	
	printf("Informe o valor 2: ");
	scanf("%f", &valor2);
	
	resultado = valor1+valor2;
	return resultado;
}

void soma4(){
	float valor1, valor2, resultado;
	
	printf("Informe o valor1: ");
	scanf("%f", &valor1);
	
	printf("Informe o valor 2: ");
	scanf("%f", &valor2);
	
	resultado = valor1+valor2;
	printf("Soma = %f\n", resultado);
}

