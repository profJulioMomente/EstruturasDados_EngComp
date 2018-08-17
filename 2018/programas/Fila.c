#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct node{
	int valor;
	struct node *prox;
} Elemento;

Elemento* queue(Elemento* Tail, Elemento *novo);
Elemento* dequeue(Elemento *Head);
Elemento* head(Elemento *Head);

main() {
	Elemento *Fila_I, *Fila_F, *aux, *novo;
	int i;
	
	for(i=0; i<5; i++){
		novo = (Elemento*) malloc(sizeof(Elemento));
		printf("Informe o  valor: ");
		scanf(" %d", &novo->valor);
		novo->prox = NULL;
		
		Fila_F = queue(Fila_F, novo);
		if(Fila_I == NULL) {
			Fila_I = Fila_F;
		}
	}
	printf("\n\n");
	system("pause");
	printf("\n\n");
	
	for (i=0; i<5; i++) {
		aux = head(Fila_I);
		if(aux!=NULL) {
			printf("Atendendo %d\n", aux->valor);
			
			Fila_I = dequeue(Fila_I);
			
			if(Fila_I == NULL) {
				Fila_F = Fila_I;
			}
		}
	}
	
	
	
	system("pause");
}

Elemento* queue(Elemento* Tail, Elemento *novo){
	if(Tail!=NULL){
		Tail->prox = novo;
	}  
	Tail = novo;
	
	return Tail;		
}

Elemento* dequeue(Elemento *Head){
	Elemento *remover;
	
	if(Head!=NULL){
		remover = Head;
		Head = Head->prox;
		
		free(remover);
	}
	
	return Head;
	
}

Elemento* head(Elemento *Head){
	return Head;
}
