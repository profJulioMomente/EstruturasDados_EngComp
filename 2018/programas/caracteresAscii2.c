#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

main(){
	char Nome[50];
	int i;
	
	printf("Digite um nome: ");
	gets(Nome);
	
	
	for(i=0; i<strlen(Nome); i++){
		printf("%d\n",Nome[i]);
	}
	
	system("pause");
}
