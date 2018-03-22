#include<stdio.h>
#include<stdlib.h>

void decompor(int num, int *cent, int *dez, int *uni);

main() {
	int numero, centenas, dezenas, unidades;
	
	printf("Informe um numero inteiro: ");
	scanf("%d", &numero);
	
	decompor(numero, &centenas, &dezenas, &unidades);
	
	printf("O numero %d e composto por: \n",numero);
	printf("%d centenas, %d dezenas e %d unidades\n",centenas, dezenas, unidades);
	
	system("pause");			
}

void decompor(int num, int *cent, int *dez, int *uni){
	*cent = num/100;
	num = num%100;
	*dez = num/10;
	*uni = num%10;	
}
