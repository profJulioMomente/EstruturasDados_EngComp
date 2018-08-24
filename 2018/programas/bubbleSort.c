#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void preencheVetor(int V[], int tam, int max);
void imprimeVetor(int V[], int tam);
void troca(int *A, int *B);
void bubbleSort(int V[], int tam);

int main (){
	int *Aleatorio;
	int tam, max;
	float tempo;
	clock_t t_inicio, t_final;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	Aleatorio = (int*) malloc (tam*sizeof(int));
	
	printf("\nInforme o valor maximo a ser gerado: ");
	scanf("%d", &max);
	
	preencheVetor(Aleatorio, tam ,max);
	printf("\nDesordenado\n");
	//imprimeVetor(Aleatorio, tam);
	//system("pause");
	
	t_inicio = clock();
	bubbleSort(Aleatorio, tam);
	t_final = clock();
	
	//system("pause");
	printf("\nOrdenado\n");
	//imprimeVetor(Aleatorio, tam);
	
	tempo = ((float)t_final - (float)t_inicio)/CLOCKS_PER_SEC;
	printf("O tempo de ordenacao foi de %f segundos\n\n", tempo);
	
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

void bubbleSort(int V[], int tam){
	int i, j;
	
	for(i=1; i<tam; i++){
		for(j=0;j<(tam-i);j++){
			if(V[j]>V[j+1]){
				troca(&V[j], &V[j+1]);
			}
		}
	}
}
