#include<stdio.h>
#include<stdlib.h>

FILE *arq;

main () {
	char Arquivo[100];
	char caracter;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	/*while(!feof(arq)){ //Funcao que retorna verdadeiro quando encontra o fim do arquivo
		caracter = getc(arq);
		printf("%c", caracter);
	}*/
	
	do {
		caracter = getc(arq);
		printf("%c", caracter);
	} while (caracter != EOF); //EOF - Caracter que marca o fim do arquivo
	
	fclose(arq); //Fechamento do arquivo
	
	system("pause");
}
