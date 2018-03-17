#include<stdio.h>
#include<stdlib.h>

//protótipo
int maximoDivisorComum(int valor1, int valor2);

main() {
	int valor1, valor2, mdc;
	
	printf("Informe o valor 1: ");
	scanf("%d", &valor1);
	printf("Informe o valor 2: ");
	scanf("%d", &valor2);
	
	mdc = maximoDivisorComum(valor1, valor2);
	
	printf("o mdc entre %d e %d e %d\n",valor1, valor2, mdc);
	
	system("pause");
}

//implementação
int maximoDivisorComum(int valor1, int valor2){
	int menor, mdc, i;
	
	if(valor1<valor2) {
		menor = valor1;
	} else {
		menor = valor2;
	}
	
	for (i=1; i<=menor; i++){
		if(valor1%i == 0 && valor2%i == 0){
			mdc = i;
		}
	}
	
	return mdc;
}
