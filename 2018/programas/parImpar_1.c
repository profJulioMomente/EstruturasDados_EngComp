#include<stdio.h>
#include<stdlib.h>

main () {
	int valor;
	
	printf("Informe o valor: ");
	scanf("%d", &valor);
	
	if(valor%2 == 0) {
		printf("\npar\n");
	} else {
		printf("\nimpar\n");
	}
	
	system("pause");
}
