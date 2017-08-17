#include<stdio.h>
#include<stdlib.h>

FILE *arq;

main () {
	char Arquivo[100];
	char caracter;
	int cont =0;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	while(!feof(arq)){ //Funcao que retorna verdadeiro quando encontra o fim do arquivo
		caracter = getc(arq);
		cont++;
	}
	
	printf("O arquivo tem %d caracteres\n\n", cont);
	
	fclose(arq); //Fechamento do arquivo
	
	system("pause");
}
