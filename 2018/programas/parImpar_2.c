#include<stdio.h>
#include<stdlib.h>

main () {
	int valor;
	
	printf("Informe o valor: ");
	scanf("%d", &valor);
	
	printf("O valor e %s \n", valor%2==0?"par":"impar");
	
	system("pause");
}
