#include<stdio.h>
#include<stdlib.h>

int BuscaBinariaRecursiva(int V[], int Ini, int Fim, int busca);

main () {
	int Vetor[10], i, pos, busca;
	
	for(i=0; i<10; i++){
		printf("V[%d]: ", i);
		scanf("%d", &Vetor[i]);
	}
	while(1){ 
		printf("\nInforme o valor a ser procurado: ");
		scanf("%d", &busca);
		
		pos = BuscaBinariaRecursiva(Vetor, 0, 9, busca);
		
		if(pos!= -1){
			printf("O valor esta na posicao %d\n", pos);
		}
		else {
			printf("Valor nao encontrado\n");
		}
		system("pause");
	}
}



int BuscaBinariaRecursiva(int V[], int Ini, int Fim, int busca){
	int meio;
	
	if (Ini <= Fim) {
		meio = (Ini + Fim)/2;
		
		if( V[meio] == busca){
			return meio;
		} else if (V[meio] < busca){
			return BuscaBinariaRecursiva(V, meio+1, Fim, busca);
		} else {
			return BuscaBinariaRecursiva(V, Ini, meio-1, busca);
		}
	}
	else {
		return -1;
	}
}

