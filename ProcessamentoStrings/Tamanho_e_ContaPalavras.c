#include<stdio.h>
#include<stdlib.h>

int comprimento (char S[], int tam);
int contaPalavras  (char *S, int tam);

main () {
	char Texto[200];
	int tamanho, palavras;
	
	puts("Digite uma palavra");
	gets(Texto);
	
	tamanho = comprimento(Texto, 200);
	
	palavras = contaPalavras(Texto, 200);
	
	printf("A string tem %d caracteres e %d palavras\n\n", tamanho, palavras);
	
	system("pause");
	
}

int comprimento (char S[], int tam) {
	int comp=0, i;
	
	for (i=0; i<tam; i++){
		if(S[i] == '\0'){
			return comp;
		}
		else {
			comp++;
		}
	}
	return comp;
}

int contaPalavras  (char *S, int tam) {
	int cont=0, i;
	
	for(i=0; i<tam; i++){
		if(S[i] == '\0') { //Caso encontre o final da string
			return cont;
		}
		else {
			if (S[i] != ' '){ //Ao encontrar um caracter não palavra
				if(i == 0 || S[i-1] == ' '){ //se este for o primeiro caracter da string ou se o anterior for um espaço
					cont++;
				}
			}
		}
	}
	
	return cont;
}
