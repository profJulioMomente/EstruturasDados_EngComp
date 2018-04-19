#include<stdio.h>
#include<stdlib.h>

main() {
	float *Vetor;
	int tamanho, i;
	float media, soma=0;
	
	printf("Informe a quantidade de valores: ");
	scanf("%d", &tamanho);
	
	//Alocação dinâmica
	Vetor = (float*) malloc(tamanho*sizeof(float));
	
	for(i=0; i<tamanho; i++){
		printf("\nVetor[%d] = ", i);
		scanf("%f", &Vetor[i]);
	}
	
	
	for(i=0; i<tamanho; i++){
		soma = soma + Vetor[i];
	}
	media = soma/tamanho;
	
	printf("A media e %f\n", media);
	
	system("pause");
	
}
