#include<stdio.h>
#include<stdlib.h>

void verificaAprovacao(float nota1, float nota2, float nota3, float nota4);
float media(float nota1, float nota2, float nota3, float nota4);

main() {
	float nota1, nota2, nota3, nota4;
	
	printf("Informe a nota 1: ");
	scanf("%f", &nota1);
	
	printf("Informe a nota 2: ");
	scanf("%f", &nota2);
	
	printf("Informe a nota 3: ");
	scanf("%f", &nota3);
	
	printf("Informe a nota 4: ");
	scanf("%f", &nota4);
	
	verificaAprovacao(nota1,nota2,nota3,nota4);
	
	system("pause");
}

void verificaAprovacao(float nota1, float nota2, float nota3, float nota4){
	float med;
	
	med = media(nota1,nota2,nota3,nota4);
	
	if(med >= 7){
		printf("Aprovado!\n");
	} else {
		printf("Reprovado!\n");
	}
}

float media(float nota1, float nota2, float nota3, float nota4){
	float m;
	
	m = (nota1+nota2+nota3+nota4)/4.0;
	
	return m;
}

