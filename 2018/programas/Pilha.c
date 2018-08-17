#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct node{
	char delimitador;
	struct node *prox;
} Elemento;

Elemento* push(Elemento *Topo, Elemento *novo);
Elemento* pop(Elemento *Topo);
Elemento* top(Elemento *Topo);

main() {
	char trecho[100];
	char delim;
	int i;
	Elemento *Pilha, *aux, *novo;
	
	printf("Informe um trecho do codigo: ");
	scanf(" %[^\n]s", trecho);
	
	for( i=0; i<strlen(trecho); i++){
		if(trecho[i] == '(' || trecho[i] == '[' \
			|| trecho[i] == '{') {
				novo = (Elemento*) malloc(sizeof(Elemento));
				novo->delimitador = trecho[i];
				novo->prox = NULL;
				
				Pilha = push(Pilha, novo);
			}
		if (trecho[i] == ')'){
			aux = top(Pilha);
			if(aux!=NULL){
				if(aux->delimitador == '(') {
					pop(Pilha);
				} else {
					printf("Erro na posicao %d\n", i);
					break;
				}
			} else {
				printf("Erro de fechamento\n");
				break;
			}
		}
		if (trecho[i] == ']'){
			aux = top(Pilha);
			if(aux!=NULL){
				if(aux->delimitador == '[') {
					pop(Pilha);
				} else {
					printf("Erro na posicao %d\n", i);
					break;
				}
			} else {
				printf("Erro de fechamento\n");
				break;
			}
		}
		if (trecho[i] == '}'){
			aux = top(Pilha);
			if(aux!=NULL){
				if(aux->delimitador == '{') {
					pop(Pilha);
				} else {
					printf("Erro na posicao %d\n", i);
					break;
				}
			} else {
				printf("Erro de fechamento\n");
				break;
			}
		}
	}
	
	if( i == strlen(trecho)){
		if(top(Pilha) == NULL) {
			printf("O trecho esta OK\n");
		}
		else {
			printf("Erro de abertura\n");
		}
	}
	
	system("pause");
}


Elemento* push(Elemento *Topo, Elemento *novo){
	novo->prox = Topo;
	Topo = novo;
	return Topo;
}

Elemento* pop(Elemento *Topo){
	Elemento *remover;
	
	if(Topo != NULL) {
		remover = Topo;
		Topo = Topo->prox;
		
		free(remover);
	}
	
	return Topo;
}

Elemento* top(Elemento *Topo){
	return Topo;
}



