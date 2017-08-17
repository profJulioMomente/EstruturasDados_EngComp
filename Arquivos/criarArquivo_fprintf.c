#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100], Texto[100];
	int i;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "w"); //Abertura do arquivo para escrita
	
	fflush(stdin);
	
	printf("Informe o texto: ");
	gets(Texto);
	
	fprintf(arq, "%s\n%d", Texto, 2017);
	
	fclose(arq); //Fechamento do arquivo
	
	system("pause");
}
