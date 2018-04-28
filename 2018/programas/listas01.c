
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct noLista{
	int info;
	struct noLista *prox;
} Elemento;

Elemento* inserirInicio(Elemento *Lista, Elemento *novo);
void imprimirLista(Elemento *Lista);

main (){
	Elemento *Lista=NULL, *novo;
	int i, valor;
	
	
	do{
		novo = (Elemento*) malloc(sizeof(Elemento));
		printf("Informe um inteiro: ");
		scanf("%d", &valor);
		if (valor != -1) {
			novo->info = valor;
			novo->prox = NULL;
			Lista = inserirInicio(Lista, novo);
		}
	}while(valor != -1);
	
	imprimirLista(Lista);
	
	system("pause");
}


Elemento* inserirInicio(Elemento *Lista, Elemento *novo){
	novo->prox = Lista;
	Lista = novo;
	return novo;
}


void imprimirLista(Elemento *Lista){
	Elemento *aux;
	printf("\n\nImprimindo a lista\n\n");
	aux = Lista;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux = aux->prox;
	}
	
}

