#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void preencheVetor(int V[], int tam, int max);
void imprimeVetor(int V[], int tam);
void troca(int *A, int *B);
void selectionSort(int V[], int tam);

int main (){
	int *Aleatorio;
	int tam, max;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	Aleatorio = (int*) malloc (tam*sizeof(int));
	
	printf("\nInforme o valor maximo a ser gerado: ");
	scanf("%d", &max);
	
	preencheVetor(Aleatorio, tam ,max);
	printf("\nDesordenado\n");
	imprimeVetor(Aleatorio, tam);
	system("pause");

	selectionSort(Aleatorio, tam);

	system("pause");
	printf("\nOrdenado\n");
	imprimeVetor(Aleatorio, tam);
	
	
	system("pause");
	
}


void preencheVetor(int V[], int tam, int max){
	int  i;
	time_t t = time(0);
	
	if(max <= 0)
		max = 9999999;
	
	srand((unsigned) time(&t));
	for(i=0; i<tam; i++){
		V[i] = (rand()%max)+1;
	} 
}

void imprimeVetor(int V[], int tam) {
	int i;
	
	for (i=0; i<tam; i++) {
		printf("V[%d] = %d\n", i, V[i]);
	}
}

void troca(int *A, int *B){
	int aux;
	aux = *A;
	*A = *B;
	*B = aux;
}

void selectionSort(int V[], int tam){
	int i, j, posicaoMenor;
	for(i=0; i<(tam-1); i++){
		posicaoMenor = i;
		for(j=i+1;j<tam;j++){
			if(V[j] < V[posicaoMenor]){
				posicaoMenor = j;
			}
		}
		troca(&V[i],&V[posicaoMenor]);
	}
}
