#include<stdio.h>
#include<stdlib.h>

typedef struct Struct1{
	int info;
	struct Struct1 *Esq;
	struct Struct1 *Dir;
} No;

No* inserir(No *Raiz, int Dado);
void preOrdem(No *Raiz);
void emOrdem(No *Raiz);
void posOrdem(No *Raiz);
No* pesquisa(No *Raiz, int Dado);
No* Pai(No *Filho, No *Raiz);
void Troca(No *A1, No *A2);
int eFolha(No *E);
int eEsquerda(No *Filho, No *Pai);
int eDireita(No *Filho, No *Pai);
No* remover(No *Raiz, int val);

main () {
	No *Raiz = NULL, *aux;
	int valor, opcao;
	
	
	do{
		system("cls");
		printf("[1] - Inserir\n");
		printf("[2] - preOrdem\n");
		printf("[3] - emOrdem\n");
		printf("[4] - posOrdem\n");
		printf("[5] - pesquisar\n");
		printf("[6] - Remover\n");
		printf("[0] - Terminar\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("Informe o valor que deseja inserir: ");
				scanf("%d", &valor);
				Raiz = inserir(Raiz, valor);
				break;
			case 2:
				printf("Percurso Pre Ordem:\n");
				preOrdem(Raiz);
				break;
			case 3:
				printf("Percurso Em Ordem:\n");
				emOrdem(Raiz);
				break;
			case 4:
				printf("Percurso Pos Ordem:\n");
				posOrdem(Raiz);
				break;
			case 5:
				printf("Informe o valor que deseja procurar: ");
				scanf("%d", &valor);
				aux = pesquisa(Raiz, valor);
				if(aux!=NULL)
					printf("O valor foi encontrado!!\n");
				else
					printf("O valor nao foi encontrado!!\n");
				break;
			case 6:
				printf("Informe o valor que deseja remover: ");
				scanf("%d", &valor);
				Raiz = remover(Raiz, valor);
				break;
			case 0:
				printf("Terminando ...\n");
				break;
			default:
				printf("Opcao invalida!\n");
				break;
		}
		printf("\n\n");
		system("pause");
	} while (opcao !=0);
	
	
}

No* inserir(No *Raiz, int Dado){
	No *novo;
	
	if(Raiz==NULL){
		novo = malloc(sizeof(No));
		novo->info = Dado;
		novo->Esq = NULL;
		novo->Dir = NULL;
		
		return novo;
		
	} else if(Dado < Raiz->info){
		Raiz->Esq = inserir(Raiz->Esq, Dado);
	} else {
		Raiz->Dir = inserir(Raiz->Dir, Dado);
	}
	return Raiz;
}

void preOrdem(No *Raiz){
	if(Raiz != NULL) {
		printf("%d ", Raiz->info);
		preOrdem(Raiz->Esq);
		preOrdem(Raiz->Dir);
	}
}

void emOrdem(No *Raiz){
	if(Raiz != NULL) {
		emOrdem(Raiz->Esq);
		printf("%d ", Raiz->info);
		emOrdem(Raiz->Dir);
	}
}

void posOrdem(No *Raiz){
	if(Raiz != NULL) {
		posOrdem(Raiz->Esq);
		posOrdem(Raiz->Dir);
		printf("%d ", Raiz->info);
	}
}

No* pesquisa(No *Raiz, int Dado){
	if (Raiz == NULL){
		return NULL;
	} else {
		if(Raiz->info == Dado){
			return Raiz;
		} else if(Dado < Raiz->info){
			return pesquisa(Raiz->Esq, Dado);
		} else {
			return pesquisa(Raiz->Dir, Dado);
		}
	}
	
}

No* Pai(No *Filho, No *Raiz){
	No *Atual=NULL, *ePai=NULL;
	
	if(Filho == Raiz) {
		return NULL;
	}
	else {
		Atual = Raiz;
		while(Atual != Filho){
			ePai = Atual;
			if(Filho->info <= Atual->info){
				Atual = Atual->Esq;
			}
			else {
				Atual = Atual->Dir;
			}
		}
		return ePai;
	}
}

void Troca(No *A1, No *A2){
	int aux;
	aux = A1->info;
	A1->info = A2->info;
	A2->info = aux;
}

int eFolha(No *E){
	if(E->Esq == NULL && E->Dir == NULL)
		return 1;	
	else
		return 0;
}

int eEsquerda(No *Filho, No *Pai){
	if(Pai->Esq == Filho)
		return 1;
	else
		return 0;
}

int eDireita(No *Filho, No *Pai){
	if(Pai->Dir == Filho)
		return 1;
	else
		return 0;
}

No* remover(No *Raiz, int val){
	No *item, *aux, *P;
	int troca;
	
	item = pesquisa(Raiz, val); //Pesquisa o elemento a ser removido da árvore
	
	if(item!=NULL){ //Se o valor a ser removido existir na árvore
		if(!eFolha(item)){ //Se o elemento a ser removido não for uma folha
			if(item->Esq !=NULL){ //Procura o elemento mais a Direita do filho à esquerda
				aux = item->Esq;
				while(aux->Dir !=NULL){
					aux = aux->Dir;
				}
			} else { //Procura o elemento mais a Esquerda do filho à Direita
				aux = item->Dir;
				while(aux->Esq !=NULL){
					aux = aux->Esq;
				}
			}
		} //Fim do if de verificação se o nó a ser removido é raiz ou galho
		else { //O elemento a ser removido é folha
			aux = item;
		}
		
		P = Pai(aux, Raiz); //localiza o pai do no folha a ser removido
		
		Troca(item, aux); //Troca valores entre o no a ser removido e o nó folha candidato
		
		//Nesse instante, o nó folha (aux) já possui o valor nó que será removido e este pode ser removido da árvore
		
		if(P == NULL){ // Caso o pai do nó folha a ser removido for nulo, implica que a raiz é o único nó da árvore e, portanto a árvore fica vazia
			Raiz = NULL;
		} else {
			if(eEsquerda(aux, P)){//Caso o nó que será removido seja um filho à Esquerda, ajustar o ponteiro à Esquerda do Pai
				if(aux->Esq == NULL) // Se não houver filho à Esquerda do nó a ser eliminado (aux)
					P->Esq = aux->Dir;
				else //Se houver filho à Esquerda do nó a ser eliminado
					P->Esq = aux->Esq;
			} else { // Caso o nó que será removido seja um filho à Direita, ajustar o ponteiro à Direita do Pai
				if(aux->Dir == NULL) //Se não houver filho à Direita do nó a ser eliminado
					P->Dir = aux->Esq;
				else //Se houver filho à Direita do nó a ser eliminado
					P->Dir = aux->Dir;
			}
		}
		free(aux); //liberar o espaço do elemento
	} else { //O valor a ser eliminado não existe na árvore
		printf("Nao ha elemento para ser removido\n");
	}
	return Raiz;
}
