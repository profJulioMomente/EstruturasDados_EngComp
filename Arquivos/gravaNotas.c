#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100];
	float nota;
	int i;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "a+"); //Abertura do arquivo para anexo
	
	fflush(stdin);
	
	for (i=0; i<4; i++){
	
		printf("Informe a nota %d: ", i+1);
		scanf("%f", &nota);
		fprintf(arq, "%.2f\n", nota);
		
	}
	
	fclose(arq);
	
	system("pause");
}
