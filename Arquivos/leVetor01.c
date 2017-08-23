#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *arq;

main () {
	char Arquivo[100];
	int *Vetor, tam, i;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para leitura
	
	fflush(stdin);
	
	fscanf(arq, "%d", &tam);
	
	Vetor = (int*) malloc(tam*sizeof(int));
	
	
	for(i = 0; i<tam; i++) {
		fscanf(arq, "%d", &Vetor[i]);	
	}
	
	
	fclose(arq);
	
	for(i = 0; i<tam; i++) {
		printf("V[%d] = %d\n", i, Vetor[i]);	
	}
	
	system("pause");
}
