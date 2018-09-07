#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void preencheVetor(int V[], int tam, int max);
void imprimeVetor(int V[], int tam);
void troca(int *A, int *B);
void bubbleSort(int V[], int tam);
int buscaBinaria(int V[], int tam, int busca);
int buscaBinariaRecursiva(int V[], int inicio, int fim, int busca);

int main (){
	int *Aleatorio;
	int tam, max, busca,pos;
	float tempo;
	clock_t t_inicio, t_final;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	Aleatorio = (int*) malloc (tam*sizeof(int));
	
	printf("\nInforme o valor maximo a ser gerado: ");
	scanf("%d", &max);
	
	preencheVetor(Aleatorio, tam ,max);
	printf("\nDesordenado\n");
	imprimeVetor(Aleatorio, tam);
	system("pause");
	
	t_inicio = clock();
	bubbleSort(Aleatorio, tam);
	t_final = clock();
	
	system("pause");
	printf("\nOrdenado\n");
	imprimeVetor(Aleatorio, tam);
	
	tempo = ((float)t_final - (float)t_inicio)/CLOCKS_PER_SEC;
	printf("O tempo de ordenacao foi de %f segundos\n\n", tempo);
	
	while(1){
		printf("Digite o valor que deseja buscar: ");
		scanf("%d", &busca);
		pos = buscaBinariaRecursiva(Aleatorio,0,tam-1,busca);
		if(pos == -1){
			printf("valor nao encontrado\n");
		} else {
			printf("valor encontrado na posicao %d\n",pos);
		}
		system("pause");
	}
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

int buscaBinaria(int *V, int tam, int busca){
	int meio, inicio, fim;
	inicio = 0;
	fim = tam-1;
	do {
		meio = (inicio + fim)/2;
		if(V[meio] == busca)
			return meio;
		else if(V[meio] > busca){
			fim = meio-1;
		} else {
			inicio = meio+1;
		}
	} while(inicio <= fim);
	
	return -1;
}

int buscaBinariaRecursiva(int V[], int inicio, int fim, int busca)
{
	int meio;
	
	if (inicio > fim) {
		return -1;
	} else {
		meio = (inicio + fim)/2;
		if(V[meio] == busca){
			return meio;
		} else if(V[meio] > busca){
			return buscaBinariaRecursiva(V,inicio,meio-1,busca);
		} else {
			return buscaBinariaRecursiva(V,meio+1,fim,busca);
		}
	}
}

int maiorValor(int V[], int tam){
	int maior,i;
	
	for(i=0;i<tam;i++){
		if (i==0) {
			maior = V[i];
		} else  if (V[i] > maior) {
			maior = V[i];
		}
	}
	return maior;
}

int maiorValorRecursivo(int V[], int inicio, int fim){
	int maior;
	
	if(inicio == fim) {
		return V[inicio];
	} else {
		maior = maiorValorRecursivo(V,inicio, fim-1);
		if (V[fim] > maior){
			return V[fim];
		} else {
			return maior;
		}
	}
}
