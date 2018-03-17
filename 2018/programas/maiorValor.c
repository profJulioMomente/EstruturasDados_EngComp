#include<stdio.h>
#include<stdlib.h>

//Protótipo da função
int maiorValor(int quantidade);

main() {
	int qtdValores, maior, i;
	
	for (i=0; i<3; i++) {
		printf("Informe a quantidade de valores: ");
		scanf("%d", &qtdValores);
		
		//chamada a função
		maior = maiorValor(qtdValores);
	
		printf("O maior valor e %d\n", maior);
	}
	
	system("pause");
}

int maiorValor(int quantidade) {
	int valor, maior, i;
	
	for (i=0; i<quantidade; i++){
		printf("Informe o valor %d: ", i);
		scanf("%d", &valor);
		if (i==0) {
			maior = valor;
		} else {
			if (valor > maior) {
				maior = valor;
			}
		}
	}
	
	return maior;
	
}
