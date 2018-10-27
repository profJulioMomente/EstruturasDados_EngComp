#include<stdio.h>
#include<stdlib.h>

typedef struct struct1{
	int info;
	struct struct1 *esq;
	struct struct1 *dir;
} no;


no* inserirElemento(no* Raiz, int valor);
void preOrdem(no* Raiz);
void emOrdem(no* Raiz);
void posOrdem(no* Raiz);
no* pesquisaElemento(no* Raiz, int busca);
void troca(no* Elemento1, no* Elemento2);
int eFolha(no* Elemento);
int eFilhoDireita(no* Filho, no* Pai);
no *localizarPai(no* Elemento, no* Raiz);
no* removerElemento(no* Raiz, int valor);

main() {
	no* Arvore, *aux;
	int valor, opcao;
	
	do{
		system("cls");
		printf("[1] - inserir elemento\n");
		printf("[2] - preOrdem\n");
		printf("[3] - emOrdem\n");
		printf("[4] - posOrdem\n");
		printf("[5] - pesquisa\n");
		printf("[6] - remover\n");
		printf("[0] - terminar\n");
		printf("Informe a opcao desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\ninforme o valor a ser inserido: ");
				scanf("%d", &valor);
				Arvore = inserirElemento(Arvore, valor);
				break;
			case 2:
				preOrdem(Arvore);
				break;
			case 3:
				emOrdem(Arvore);
				break;
			case 4:
				posOrdem(Arvore);
				break;
			case 5:
				printf("\ninforme o valor a ser pesquisado: ");
				scanf("%d", &valor);
				aux = pesquisaElemento(Arvore, valor);
				if(aux != NULL) {
					printf("elemento localizado, %d\n",aux->info);
				} else {
					printf("elemento nao encontrado\n");
				}
				break;
			case 6:
				printf("\ninforme o valor a ser removido: ");
				scanf("%d", &valor);
				Arvore = removerElemento(Arvore, valor);
				break;
			case 0:
				printf("Finalizando\n");
				break;
			default:
				printf("Opcao invalida\n");
				break;
		}
		printf("\n");
		system("pause");
		
	}while(opcao!=0);
	
}

no* inserirElemento(no* Raiz, int valor){
	no *novo;
	
	if (Raiz == NULL) {
		novo = (no*) malloc (sizeof(no));
		novo->info = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		Raiz = novo;
	} else {
		if (valor < Raiz->info) {
			Raiz->esq = inserirElemento(Raiz->esq, valor);
		} else {
			Raiz->dir = inserirElemento(Raiz->dir, valor);
		}
	}
	return Raiz;
}

void preOrdem(no* Raiz){
	if(Raiz != NULL){
		printf("%d - ",Raiz->info);
		preOrdem(Raiz->esq);
		preOrdem(Raiz->dir);
	}
}

void emOrdem(no* Raiz){
	if(Raiz != NULL){
		emOrdem(Raiz->esq);
		printf("%d - ",Raiz->info);
		emOrdem(Raiz->dir);
	}
}

void posOrdem(no* Raiz){
	if(Raiz != NULL){
		posOrdem(Raiz->esq);
		posOrdem(Raiz->dir);
		printf("%d - ",Raiz->info);
	}
}

no* pesquisaElemento(no* Raiz, int busca){
	if (Raiz == NULL) {
		return NULL;
	} else {
		if(busca == Raiz->info){
			return Raiz;
		} else if (busca < Raiz->info){
			return pesquisaElemento(Raiz->esq,busca);
		} else {
			return pesquisaElemento(Raiz->dir,busca);
		}
	}
}

void troca(no* Elemento1, no* Elemento2){
	int aux;
	aux = Elemento1->info;
	Elemento1->info = Elemento2->info;
	Elemento2->info = aux;
}

int eFolha(no* Elemento){
	if (Elemento->esq == NULL && Elemento->dir == NULL){
		return 1;
	} else {
		return 0;
	}
}

int eFilhoDireita(no* Filho, no* Pai){
	if(Pai->dir == Filho) {
		return 1;
	} else {
		return 0;
	}
}

no *localizarPai(no* Elemento, no* Raiz){
	no *Pai, *aux;
	
	if (Elemento == Raiz){
		return NULL;
	} else {
		aux = Raiz;
		while (aux!=Elemento){
			Pai = aux;
			if(Elemento->info < aux->info){
				aux = aux->esq;
			} else {
				aux = aux->dir;
			}
		}
		return Pai;
	}
}

no* removerElemento(no* Raiz, int valor){
	no *elementoLocalizado=NULL, *elementoCandidato=NULL, *Pai = NULL;
	
	if (Raiz != NULL) {
		elementoLocalizado = pesquisaElemento(Raiz, valor);
		if (elementoLocalizado != NULL) {
			if (eFolha(elementoLocalizado)) {
				elementoCandidato = elementoLocalizado;
			} else {
				if(elementoLocalizado->esq != NULL){
					elementoCandidato = elementoLocalizado->esq;
					while(elementoCandidato->dir != NULL){
						elementoCandidato = elementoCandidato->dir;
					}
				} else {
					elementoCandidato = elementoLocalizado->dir;
					while(elementoCandidato->esq != NULL){
						elementoCandidato = elementoCandidato->esq;
					}
				}
			}
			Pai = localizarPai(elementoCandidato, Raiz);
			troca(elementoLocalizado, elementoCandidato);
			
			if (Pai == NULL) {
				Raiz = NULL;
			} else {
				if(eFilhoDireita(elementoCandidato, Pai)){
					if(elementoCandidato->esq != NULL) {
						Pai->dir = elementoCandidato->esq;
					} else {
						Pai->dir = elementoCandidato->dir;
					}
				} else {
					if(elementoCandidato->esq != NULL) {
						Pai->esq = elementoCandidato->esq;
					} else {
						Pai->esq = elementoCandidato->dir;
					}
				}
			}
			free(elementoCandidato);
		}
	}
	return Raiz;
}

