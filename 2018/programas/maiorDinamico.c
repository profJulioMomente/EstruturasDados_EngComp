#include<stdio.h>
#include<stdlib.h>

main() {
	int *Vetor;
	int tamanho, i;
	int maior = -99999;
	
	printf("Informe a quantidade de valores: ");
	scanf("%d", &tamanho);
	
	//Alocação dinâmica
	Vetor = (int*) malloc(tamanho*sizeof(int));
	
	for(i=0; i<tamanho; i++){
		printf("\nVetor[%d] = ", i);
		scanf("%d", &Vetor[i]);
	}
	
	for(i=0; i<tamanho; i++) {
		if(Vetor[i] > maior) {
			maior = Vetor[i];
		}
	}
	
	printf("O maior valor e %d\n",maior);
	
	system("pause");
	
}
