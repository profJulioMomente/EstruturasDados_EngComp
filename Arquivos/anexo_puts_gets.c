#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100], Texto[100];
	char caracter;
	int i;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "a"); //Abertura do arquivo para anexo
	
	fflush(stdin);
	
	printf("Informe o texto: ");
	gets(Texto);
	
	putc('\n', arq);
	
	fputs(Texto, arq); //Escreve string no arquivo
	
	fclose(arq); //Fechamento do arquivo
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	while(!feof(arq)){
		fgets(Texto, 100, arq); //Leitura de string do arquivos
		printf("%s", Texto);
	}
	
	
	system("pause");
}
