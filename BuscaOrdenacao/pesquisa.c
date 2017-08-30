#include<stdio.h>
#include<stdlib.h>

int pesquisaVetor( int Vetor[], int tam, int busca);
int buscaBinaria(int Vetor[], int tam, int busca);

main () {
	int Vetor[10];
	int i, busca, resultado;
	
	for(i=0; i<10; i++){
		printf("V[%d] = ",i);
		scanf("%d", &Vetor[i]);
	}
	
	printf("Informe o valor a ser pesquisado: ");
	scanf("%d", &busca);
	
	resultado = buscaBinaria(Vetor, 10, busca);
	
	/*if(resultado == -1){
		printf("O valor %d nao foi encontrado\n", busca);
	}
	else {
		printf("O valor %d foi encontrado na posicao %d\n\n", busca, resultado);
	}
	*/
	
	printf("Foram necessarias %d pesquisas\n\n", resultado);
		
	system("pause");
}

int pesquisaVetor( int Vetor[], int tam, int busca){
	int i;
	
	for(i=0; i<tam; i++){
		if(Vetor[i] == busca){
			return i;
		}
	}
	return -1;
}

int buscaBinaria(int Vetor[], int tam, int busca){
	int inicio=0, fim=tam-1, meio;
	int contador =0;
	
	while(inicio<=fim){
		meio = (inicio+fim)/2;	
		contador++;
		if(Vetor[meio] == busca){
			return contador;
		} else if(Vetor[meio] < busca){
			inicio = meio + 1;
		} else {
			fim = meio - 1;
		}
	}
	
	
	return contador;
	
}
