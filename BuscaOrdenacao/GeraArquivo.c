#include<stdio.h.>
#include<stdlib.h>
#include<time.h>
#include<locale.h>


void preencheVetor(int V[], int tam);
void imprimeVetor(int V[], int tam);

FILE *arq;

main (){
	int *V, valor;
	setlocale(LC_ALL, "portuguese");
	char Arquivo[100];
	
	printf("Digite a quantidade de valores: ");
	scanf("%d", &valor);
	
	printf("Informe o nome do arquivo com extensao: ");
	scanf(" %[^\n]s", Arquivo);
	
	V = malloc(valor*sizeof(int));
	
	if((arq = fopen(Arquivo, "w"))== NULL){
		printf("\nO arquivo nao pode ser aberto\n");
		return;
	}
	
	fprintf(arq, "%d\n", valor);
	
	preencheVetor(V, valor);
	imprimeVetor(V, valor);
	
	fclose(arq);

	system("pause");
	
}

void preencheVetor(int V[], int tam){
	int  i, max;
	time_t t = time(0);
	
	srand((unsigned) time(&t));
	for(i=0; i<tam; i++){
		V[i] = (rand())+1;
	} 
}

void imprimeVetor(int V[], int tam){
	int i;
	printf("\n\n");
	for(i=0; i<tam; i++){
		fprintf(arq, "%d\n", V[i]);
	}
}



