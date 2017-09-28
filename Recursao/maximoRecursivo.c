#include<stdio.h>
#include<stdlib.h>


int maximo(int V[], int Inicio, int Fim);

main() {
	int Vetor[10], max, i;
	
	for (i=0; i<10; i++){
		printf("V[%d]: ", i);
		scanf("%d", &Vetor[i]);
	}
	
	max = maximo(Vetor, 0, 9);
	
	printf("O maximo valor e: %d\n\n", max);
	
	system("pause");
	
}

int maximo(int V[], int Inicio, int Fim){
	int maior;

	if(	Inicio == Fim){
		return V[Inicio];
	} else {
		maior = maximo(V, Inicio, Fim-1);
		if( maior > V[Fim]){
			return maior;
		} else {
			return V[Fim];
		}
	}
	
}

