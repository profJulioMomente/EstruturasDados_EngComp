#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

main(){
	char Texto[200];
	int i, ContaLetras[26];	
	
	printf("Digite um texto: ");
	gets(Texto);
	
	for(i=0; i<26; i++){
		ContaLetras[i] = 0;
	}
	
	for(i=0; i<strlen(Texto); i++){
		Texto[i] = toupper(Texto[i]);
		
		if(Texto[i] >=65 && Texto[i]<=90){
			ContaLetras[Texto[i]-65]++;
		}
	}
	
	puts("Quantidade de ocorrencias:");
	for(i=0; i<26; i++){
		printf("%c = %d\n", (i+65), ContaLetras[i]);
	}
	system("pause");
}
