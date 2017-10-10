#include<stdio.h>
#include<stdlib.h>

typedef struct struct1{
	int info;
	struct struct1 *esq;
	struct struct1 *dir;
} no;

no* inserir(no* Raiz, no *novo);
void imprimir(no *Raiz);

main() {
	no* Raiz = NULL, *novo;
	int i;
	
	for (i=0; i<8; i++) {
		printf("Novo no\n");
		novo = (no*) malloc(sizeof(no));
		printf("Informe a informacao: ");
		scanf("%d", &novo->info);
		novo->esq = NULL;
		novo->dir = NULL;
		
		Raiz = inserir(Raiz, novo);
	}
	
	imprimir(Raiz);
}


no* inserir(no* Raiz, no *novo){
	if(Raiz != NULL) {
		if(novo->info < Raiz->info) {
			//vai para a esquerda
			Raiz->esq = inserir(Raiz->esq, novo);
		} else {
			//vai para a direita
			Raiz->dir = inserir(Raiz->dir, novo);
		}
		return Raiz;
	} else {
		return novo;
	}
}

void imprimir(no *Raiz){
	if (Raiz != NULL) {
		printf("%d\n", Raiz->info);
		imprimir(Raiz->esq);
		imprimir(Raiz->dir);
	}
}
