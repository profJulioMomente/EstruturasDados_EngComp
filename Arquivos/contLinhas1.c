#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100], Texto[100];
	char caracter;
	int cont_linhas = 0;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para anexo
	
	fflush(stdin);
	
	/* solução 1 - usando getc
	while(!feof(arq)){
		caracter = getc(arq);
		if(caracter == '\n'){
			cont_linhas++;
		}
	}
	
	fclose(arq);
	
	printf("Existem %d linhas\n\n", ++cont_linhas);
	*/
	
	
	//Solução 2 - usando fgets
	while(!feof(arq)){
		fgets(Texto, 100, arq);
		cont_linhas++;
	}
	
	fclose(arq);
	
	printf("Existem %d linhas\n\n", cont_linhas);
	
	
	system("pause");
}
