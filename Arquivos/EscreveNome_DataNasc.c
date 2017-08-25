#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

FILE *arq;

main () {
	char Arquivo[100], Nome[100], Data[15];
	char novo;
	
	printf("Informe o nome do arquivo com a extensao: ");
	gets(Arquivo);
	
	arq = fopen(Arquivo, "a+");
	
	do{
		fflush(stdin);
		system("cls");
		printf("Informe o Nome: ");
		gets(Nome);
		printf("Informe a data de nascimento (dd/mm/aaaa): ");
		gets(Data);
		
		fprintf(arq, "%s\n", Nome);
		fprintf(arq, "%s\n", Data);
		
		printf("\nDeseja inserir um novo regisrtro (S/N)? ");
		scanf(" %c", &novo);
		
		novo = toupper(novo);
		
	}while(novo!='N');
	
	fclose(arq);
	
	system("pause");
	
}
