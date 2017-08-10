#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

void converteMaiusculo(char *S);
void converteMinusculo(char *S, int tam);
void converteInteiro(char *S);
void converteReal(char *S);
void converteString(char *S);
void copia(char *Destino, char *Origem);
void comparacao(char *Str1, char *Str2);
void juntaStrings(char *Primeira, char *Segunda);

main () {
	char Texto[200], Txt2[200];
	char Inteiro[10], Real[10], Res[10];
	
	setlocale(LC_ALL, "portuguese");
	
	puts("Informe um texto.");
	gets(Texto);
	
	puts("Informe outro texto.");
	gets(Txt2);
	
	//converteMaiusculo(Texto);
	
	//converteMinusculo(Texto, 200);
	
	//puts(Texto);
	
	//converteInteiro(Inteiro);
	//converteReal(Real);
	//converteString(Res);
	
	//copia(Txt2, Texto);
	
	//comparacao(Texto, Txt2);
	
	juntaStrings(Texto, Txt2);
	
	//puts(Txt2);
	puts("\n\n");
	system("pause");
	
}


void converteMaiusculo(char *S){
	int i;
	
	for(i=0; i<strlen(S); i++) {
		S[i] = toupper(S[i]);
	}
}

void converteMinusculo(char *S, int tam){
	int i;
	
	for(i=0; i<tam; i++) {
		if( S[i] != '\0')
			S[i] = tolower(S[i]);
		else
			break;
	}
}

void converteInteiro(char *S){
	int resultado;
	
	printf("Informe um valor inteiro: ");
	gets(S);
	
	resultado = atoi(S);
	
	printf("%d\n", resultado+1);
}

void converteReal(char *S){
	float resultado;
	
	printf("Informe um valor real (usando ,): ");
	gets(S);
	
	resultado = atof(S);
	
	printf("%.3f\n", resultado);
}

void converteString(char *S){
	int entrada, i;
	
	printf("Informe um valor inteiro: ");
	scanf("%d", &entrada);
	
	itoa(entrada, S, 10);
	
	for (i = 0; i<strlen(S); i++){
		printf("S[%d] = %c\n", i, S[i]);
	}
}

void copia(char *Destino, char *Origem) {
	
	strcpy(Destino, Origem);
}

void comparacao(char *Str1, char *Str2){
	int resultado;
	
	resultado = strcmp(Str1, Str2);
	
	if( resultado < 0 ) {
		puts("Str1 vem antes de Str2");
		puts(Str1);
		puts(Str2);
	} else if( resultado > 0) {
		puts("Str2 vem antes de Str1");
		puts(Str2);
		puts(Str1);
	} else { //resultado == 0
		puts("Str1 e identica a Str2");
		puts(Str1);
		puts(Str2);
	}
	
}

void juntaStrings(char *Primeira, char *Segunda){
	//Junta a segunda no final da primeira
	
	strcat(Primeira, Segunda);
	
	puts(Primeira);
}
