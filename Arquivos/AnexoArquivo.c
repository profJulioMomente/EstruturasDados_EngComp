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
	
	for (i=0; i< strlen(Texto); i++) {
		putc(Texto[i], arq);
	}
	
	fclose(arq); //Fechamento do arquivo
	
	
	
	system("pause");
}
