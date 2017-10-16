#include<stdio.h>
#include<stdlib.h>

typedef struct struct1{
	int info;
	struct struct1 *esq;
	struct struct1 *dir;
} no;

no* inserir(no* Raiz, no *novo);
void preOrdem(no *Raiz);
void emOrdem(no *Raiz);
void posOrdem(no *Raiz);
no* pesquisa(no *Raiz, int busca);
int eFolha(no *Elemento);

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
	printf("\n\n - Pre Ordem\n");
	preOrdem(Raiz);
	printf("\n\n - Em Ordem\n");
	emOrdem(Raiz);
	printf("\n\n - Pos Ordem\n");
	posOrdem(Raiz);
	
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

void preOrdem(no *Raiz){
	if (Raiz != NULL) {
		printf("%d\n", Raiz->info);
		preOrdem(Raiz->esq);
		preOrdem(Raiz->dir);
	}
}

void emOrdem(no *Raiz){
	if (Raiz != NULL) {
		emOrdem(Raiz->esq);
		printf("%d\n", Raiz->info);
		emOrdem(Raiz->dir);
	}
}

void posOrdem(no *Raiz){
	if (Raiz != NULL) {
		posOrdem(Raiz->esq);
		posOrdem(Raiz->dir);
		printf("%d\n", Raiz->info);
	}
}

no* pesquisa(no *Raiz, int busca)
{
	if( Raiz != NULL) {
		if(	busca == Raiz->info){
			return Raiz;	
		} else if(busca < Raiz->info) {
			pesquisa(Raiz->esq, busca);
		} else {
			pesquisa(Raiz->dir, busca);
		}
	} else {
		return NULL;
	}
}

int eFolha(no *Elemento){
	if(Elemento->esq == NULL && Elemento->dir == NULL) {
		return 1; //1 == Verdadeiro
	} else {
		return 0; //0 == Falso
	}
}

no *pai(no* Raiz, no* Elemento)
{
	no *atual, *ePai=NULL;
	atual = Raiz;
	if(Elemento == Raiz){
		return NULL;
	} else {
		while(atual != Elemento){
			ePai = atual;
			if(Elemento->info < ePai->info){
				atual = ePai->esq;
			} else {
				atual = ePai->dir;
			}
		}
		return ePai;
	}
}	
