#include<stdio.h>
#include<stdlib.h>

main() {
	char Texto[200];
	int i=0,qtd=0;
	
	printf("Digite um texto: ");
	gets(Texto);
	
	while(Texto[i] != '\0'){
		qtd++;
		i++;
	}
	
	printf("O texto %s tem %d caracteres.\n", Texto, qtd);
	
	system("pause");
	
}

