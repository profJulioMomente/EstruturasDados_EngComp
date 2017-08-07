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

main () {
	char Texto[200];
	char Inteiro[10], Real[10], Res[10];
	
	setlocale(LC_ALL, "portuguese");
	
	//puts("Informe um texto.");
	//gets(Texto);
	
	//converteMaiusculo(Texto);
	
	//converteMinusculo(Texto, 200);
	
	//puts(Texto);
	
	//converteInteiro(Inteiro);
	//converteReal(Real);
	converteString(Res);
	
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
