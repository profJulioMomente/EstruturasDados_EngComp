#include<stdio.h>
#include<stdlib.h>

main () {
	int opcao;
	printf("Escolha uma das opcoes desejadas: \n");
	printf("[1] - Adicao\n");
	printf("[2] - Subtracao\n");
	printf("[3] - Multiplicacao\n");
	printf("[4] - Divisao\n");
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			printf("\nADICAO\n");
			break;
		case 2:
			printf("\nSUBTRACAO\n");
			break;
		case 3:
			printf("\nMULTIPLICACAO\n");
			break;
		case 4:
			printf("\nDIVISAO\n");
			break;
		default:
			printf("\nOpcao invalida\n");
			break;
	}
	
	system("pause");
}
