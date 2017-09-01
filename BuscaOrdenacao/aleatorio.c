#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int Aleatorio (int max);

int main (){
	int maximo, ctrl, sorteio;
	
	printf("informe o valor maximo a ser sorteado (0 - limite do S.O.): ");
	scanf("%d", &maximo);
	
	do {
		puts("Sorteio de Valor");
		sorteio = Aleatorio(maximo);
		printf("O valor sorteado foi %d\n\n", sorteio);
		system("pause");
		printf("\n\nDeseja sortear outro valor? [1 - Sim, 0 - Nao] ");
		scanf("%d", &ctrl);
	} while (ctrl != 0);
	return 0;
}

int Aleatorio (int max) {
	int i, valor;
	time_t t;
	  
	srand((unsigned) time(&t));
	if(max!= 0)
		valor = (rand()%max)+1;
	else
		valor = rand()+1;
	
	      
	return valor; 
}


