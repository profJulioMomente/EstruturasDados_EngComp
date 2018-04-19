#include<stdio.h>
#include<stdlib.h>

main() {
	char Texto[100];
	int i=0, qtdPalavras=0;
	
	puts("Escreva um texto: ");
	gets(Texto);
	
	while(Texto[i] != '\0'){
		if(Texto[i] != ' '){
			if(i == 0) {
				qtdPalavras++;
			} else if (Texto[i-1] == ' '){
				qtdPalavras++;
			}
		}
		i++;
	}
	printf("A qtd de palavras e: %d\n",qtdPalavras);
	system("pause");	
}
