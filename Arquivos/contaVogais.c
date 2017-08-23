#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *arq;

main () {
	char Arquivo[100], Texto[100];
	char caracter;
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	
	printf("Informe o nome do Arquivo: ");
	scanf("%s", Arquivo);
	
	arq = fopen(Arquivo, "r"); //Abertura do arquivo para anexo
	
	fflush(stdin);
	
	
	while(!feof(arq)){
		caracter = toupper(getc(arq));
		switch(caracter) {
			case 'A':
				a++;
				break;
			case 'E':
				e++;
				break;
			case 'I':
				i++;
				break;
			case 'O':
				o++;
				break;
			case 'U':
				u++;
				break;
		}
	}
	
	fclose(arq);
	
	printf("A: %d\n", a);
	printf("E: %d\n", e);
	printf("I: %d\n", i);
	printf("O: %d\n", o);
	printf("U: %d\n\n", u);
	
	
	system("pause");
}
