#include<stdio.h>
#include<stdlib.h>
#include<string.h>


main() {
	char Palavra1[100], Palavra2[100], Palavra3[100];
	
	puts("Informe uma palavra: ");
	gets(Palavra1);
	
	//cópia da Palavra 1 para a Palavra 2
	strcpy(Palavra2, Palavra1);	
	printf("Palavra 2 %s\n",Palavra2);
	
	puts("Informe outra palavra: ");
	gets(Palavra3);
	
	strcat(Palavra1, Palavra3);
	printf("Nova palavra 1: %s\n", Palavra1);
	
	system("pause");
}
