#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
Comentário de 
várias
linhas
*/
FILE *arq;

main () {
	char Arquivo[100], Nome[100], Data[15];
	int dia, mes, ano;
	
	printf("Informe o nome do arquivo com a extensao: ");
	gets(Arquivo);
	
	arq = fopen(Arquivo, "r");
	
	while(!feof(arq)){
		fgets(Nome, 100, arq);
		fgets(Data, 15, arq);
		
		dia = atoi(&Data[0]);
		mes = atoi(&Data[3]);
		ano = atoi(&Data[6]);
		
		if(ano <1977){
			printf("%s\n", Nome);
		} else if(ano == 1977 && mes < 8){
			printf("%s\n", Nome);
		} else if (ano == 1977 && mes == 8 && dia <=24){
			printf("%s\n", Nome);
		}
	}
	
	fclose(arq);
	
	system("pause");
}
