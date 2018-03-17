#include<stdio.h>
#include<stdlib.h>
void troca(int *valor1, int *valor2);

main(){
	int A, B;
	printf("Informe o valor A: ");
	scanf("%d", &A);	
	printf("Informe o valor B: ");
	scanf("%d", &B);
	
	printf("A: %d -- B: %d\n\n",A,B);
	printf("&A: %d -- &B: %d\n\n",&A,&B);
	
	troca(&A, &B);
	
	printf("A: %d -- B: %d\n\n",A,B);
	printf("&A: %d -- &B: %d\n\n",&A,&B);
	system("pause");
}

void troca(int *valor1, int *valor2){
	int aux;
	aux = *valor1;
	*valor1 = *valor2;
	*valor2 = aux;	
}
