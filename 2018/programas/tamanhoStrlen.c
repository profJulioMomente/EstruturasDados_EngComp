#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main() {
	char Texto[100];
	int i=0, qtdPalavras=0;
	
	puts("Escreva um texto: ");
	gets(Texto);
	
	printf("Qtd caracteres: %d\n", strlen(Texto));
	
	for(i=0; i<strlen(Texto); i++){
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
