#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

void converteMaiusculo(char *S);
void contaOcorrencias(char *Str);
void inicializaVetor(int *V, int tam);

main () {
	char Texto[200];
	
	puts("Digite um texto");
	gets (Texto);
	
	contaOcorrencias(Texto);
	
	system("pause");
	
}

void contaOcorrencias(char *Str) {
	int Letras[26];
	int i;
	
	converteMaiusculo(Str);
	inicializaVetor(Letras, 26);
	
	for (i = 0; i<strlen(Str); i++) {
		Letras[Str[i]-65]++;
	}
	
	for(i=0; i<26; i++) {
		printf("%c = %d\n", i+65, Letras[i]);
	}
	
}

void converteMaiusculo(char *S){
	int i;
	
	for(i=0; i<strlen(S); i++) {
		S[i] = toupper(S[i]);
	}
}

void inicializaVetor(int *V, int tam){
	int i;
	for (i=0; i<tam; i++){
		V[i] = 0;
	}
}
