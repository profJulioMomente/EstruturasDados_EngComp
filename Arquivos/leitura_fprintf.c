#include<stdio.h>
#include<stdlib.h>

FILE *arq;

main () {
	char Arquivo[100];
	char palavra[100];
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	while(!feof(arq)){ //Funcao que retorna verdadeiro quando encontra o fim do arquivo
		fscanf(arq, " %[^\n]s", palavra);
		printf("%s\n", palavra);
	}
	
	
	fclose(arq); //Fechamento do arquivo
	
	system("pause");
}
