#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100];
	int Vetor[5], i;
	
	for(i = 0; i<5; i++){
		printf("V[%d] = ", i);
		scanf("%d", &Vetor[i]);
	}
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "w"); //Abertura do arquivo para anexo
	
	fflush(stdin);
	
	fprintf(arq, "%d\n", 5);
	
	for(i = 0; i<5; i++) {
		fprintf(arq, "%d\n", Vetor[i]);	
	}
	
	
	fclose(arq);
	
	system("pause");
}
