#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void preencheVetor(int V[], int tam, int max);
void imprimeVetor(int V[], int tam);
void troca(int *A, int *B);
void quickSort(int V[], int inicio, int fim);

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
	system("pause");
	t_inicio = clock();
	quickSort(Aleatorio, 0, tam-1);
	t_final = clock();
	
	printf("\nOrdenado\n");
	system("pause");
	
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

void quickSort(int V[], int inicio, int fim){
	int pivo, i, j, meio;
   
	i = inicio;
	j = fim;
	
	meio = (i + j) / 2;
	pivo = V[meio];
	
	//Processo de particionamento ou segmentação do vetor
	do{ 
		while (V[i] < pivo) 
			i = i + 1;
		
		while (V[j] > pivo) 
			j = j - 1;
		
		if(i <= j){
			troca(&V[i], &V[j]);
			i++;
			j--;
		}
	}while(j > i);
	
	if(inicio < j) 
		quickSort(V, inicio, j);
	if(i < fim) 
		quickSort(V, i, fim);   
}

