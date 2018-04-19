#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct structPessoa {
	char Nome[100];
	int idade;
	float salario;
} Pessoa;

Pessoa cadastro(Pessoa P);

main(){
	Pessoa P1, P2[5];
	
	P1 = cadastro(P1);
	
	printf("Dados de Pessoa P1\n");
	printf("Nome: %s\n", P1.Nome);
	printf("Idade: %d\n", P1.idade);
	printf("Salario: %.2f\n", P1.salario);
	
	system("pause");
}

Pessoa cadastro(Pessoa P){
	fflush(stdin);
	printf("Informe o nome: ");
	gets(P.Nome);
	
	printf("Informe a idade: ");
	scanf("%d", &P.idade);
	
	printf("Informe o salario: ");
	scanf("%f", &P.salario);
	
	return P;
}
