#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void geraValores(int *Vetor, int tam, int max);

main(){
	int maximo, *Vetor, tam, i;
	
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	
	Vetor = (int*) malloc(tam*sizeof(int));
	
	printf("informe o valor maximo a ser sorteado (0 - limite do S.O.): ");
	scanf("%d", &maximo);
	
	geraValores(Vetor, tam, maximo);
	
	for(i=0; i<tam; i++){
		printf("V[%d] = %d\n",i, Vetor[i]);
	}
	
	system("pause");
}

void geraValores(int *Vetor, int tam, int max){
	int i, valor;
	time_t t;
	  
	srand((unsigned) time(&t));
	for(i=0; i<tam; i++) {
		if(max!= 0)
			Vetor[i] = (rand()%max)+1;
		else
			Vetor[i] = rand()+1;
	}
	
}
