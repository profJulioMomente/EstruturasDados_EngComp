#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100];
	float nota, soma=0, media;
	int i;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	fflush(stdin);
	
	for (i=0; i<4; i++){
		fscanf(arq, "%f", &nota);
		soma += nota;
	}
	fclose(arq);
	
	arq = fopen(Arquivo, "a"); //Abertura do arquivo para anexo
	
	media = soma/4;
	
	fprintf(arq, "--\n%.2f\n", media);
	
	fclose(arq);
	
	system("pause");
}
