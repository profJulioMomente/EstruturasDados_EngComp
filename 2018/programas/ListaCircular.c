
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct noLista{
	int info;
	struct noLista *prox;
} Elemento;

Elemento* criarNovo();
Elemento* inserirInicio(Elemento *Lista, Elemento *novo);
Elemento* inserirFinal(Elemento *Lista, Elemento *novo);
Elemento* inserirOrdem(Elemento *Lista, Elemento *novo);
Elemento* pesquisar(Elemento *Lista, int pesquisa);
Elemento* removerInicio(Elemento *Lista);
Elemento* removerFinal(Elemento *Lista);
Elemento* removerElemento(Elemento *Lista, int pesquisa);
void imprimirLista(Elemento *Lista);

main (){
	Elemento *Lista=NULL, *novo, *pesq;
	int i, valor, opcao;
	
	do{
		system("cls");
		printf("Escolha uma das opcoes a seguir: \n");
		printf("[1] - Inserir elemento no inicio\n");
		printf("[2] - Inserir elemento no final\n");
		printf("[3] - Inserir elemento em ordem\n");
		printf("[4] - Pesquisar elemento\n");
		printf("[5] - Remover elemento do inicio\n");
		printf("[6] - Remover elemento do final\n");
		printf("[7] - Remover elemento\n");
		printf("[8] - Imprimir a lista\n");
		printf("[0] - Sair\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		
		system("cls");
		switch(opcao){
			case 1:
				printf("Inserindo no inicio\n");
				novo = criarNovo();
				Lista = inserirInicio(Lista,novo);
				break;
			case 2:
				printf("Inserindo no final\n");
				novo = criarNovo();
				Lista = inserirFinal(Lista,novo);
				break;
			case 3:
				printf("Inserindo em ordem\n");
				novo = criarNovo();
				Lista = inserirOrdem(Lista,novo);
				break;
			case 4:
				printf("Pesquisa\n\n");
				printf("Informe o valor que deseja pesquisar: ");
				scanf("%d", &valor);
				pesq = pesquisar(Lista,valor);
				if(pesq != NULL){
					printf("Dados encontrados\n");
					printf("Valor: %d\n", pesq->info);
				} else {
					printf("Dados nao encontrados\n");
				}
				break;
			case 5:
				printf("Remover do inicio\n");
				Lista = removerInicio(Lista);
				break;
			case 6:
				printf("Remover do final\n");
				Lista = removerFinal(Lista);
				break;
			case 7:
				printf("Remover elemento\n\n");
				printf("Informe o valor que deseja remover: ");
				scanf("%d", &valor);
				Lista = removerElemento(Lista,valor);
				break;
			case 8:
				printf("Impressao da lista\n");
				imprimirLista(Lista);
				break;
			case 0:
				printf("Encerrando\n\n");
				break;
			default:
				printf("Opcao invalida\n\n");
				break;
		}
		system("pause");		
	}while(opcao != 0);
	
}

Elemento* criarNovo(){
	Elemento *novo;
	
	novo = (Elemento*) malloc(sizeof(Elemento));
	printf("Informe o valor: ");
	scanf("%d", &novo->info);
	novo->prox = novo;
	
	return novo;
}


Elemento* inserirInicio(Elemento *Lista, Elemento *novo){
	Elemento *ultimo;
	if(Lista != NULL) {
		ultimo = Lista;
		while(ultimo->prox != Lista) {
			ultimo = ultimo->prox;
		}
		ultimo->prox = novo;
		novo->prox = Lista;
	}
	Lista = novo;
	return Lista;
}

Elemento* inserirFinal(Elemento *Lista, Elemento *novo){
	Elemento *ultimo;
	if(Lista != NULL) {
		ultimo = Lista;
		while(ultimo->prox != Lista) {
			ultimo = ultimo->prox;
		}
		ultimo->prox = novo;
		novo->prox = Lista;
	} else {
		Lista = novo;
	}
	return Lista;
}


Elemento* inserirOrdem(Elemento *Lista, Elemento *novo){
	Elemento *aux, *anterior;
	if (Lista != NULL){
		aux = Lista;
		while(aux->prox != Lista && aux->info < novo->info){
			aux = aux->prox;
		}
		anterior = Lista;
		while(anterior->prox != aux){
			anterior = anterior->prox;
		}
		if(aux->info > novo->info) {
			anterior->prox = novo;
			novo->prox = aux;
			if (aux == Lista) {
				Lista = novo;
			}
		} else {
			aux->prox = novo;
			novo->prox = Lista;
		}
	} else{
		Lista = novo;
	}
	return Lista;
}

Elemento* pesquisar(Elemento *Lista, int pesquisa){
	Elemento *aux=NULL;
	if(Lista != NULL) {
		aux = Lista;
		while(aux->prox != Lista && aux->info != pesquisa) {
			aux = aux->prox;
		}
		if(aux->info != pesquisa) {
			aux = NULL;
		}
	}
	return aux;
}

Elemento* removerInicio(Elemento *Lista){
	Elemento *remover, *aux;
	if (Lista != NULL) {
		remover = Lista;
		aux = Lista;
		while(aux->prox != Lista){
			aux = aux->prox;
		}
		if (remover == aux){
			Lista = NULL;
		} else {
			Lista = Lista->prox;
			aux->prox = Lista;
		}
		free(remover);
	}
	return Lista;
}

Elemento* removerFinal(Elemento *Lista){
	Elemento *ultimo, *aux;
	if(Lista!=NULL){
		ultimo = Lista;
		while(ultimo->prox != Lista){
			ultimo = ultimo->prox;
		}
		if(Lista != ultimo) {
			aux = Lista;
			while(aux->prox != ultimo){
				aux = aux->prox;
			}
			aux->prox = Lista;
		} else {
			Lista = NULL;
		}
		free(ultimo);
	}
	return Lista;
}

Elemento* removerElemento(Elemento *Lista, int pesquisa){
	Elemento *remover, *anterior;
	if (Lista != NULL){
		remover = pesquisar(Lista, pesquisa);
		if (remover != NULL) {
			if(remover == Lista){
				if(Lista->prox == Lista){
					Lista = NULL;
				} else {
					Lista = Lista->prox;
					anterior = Lista;
					while(anterior->prox != remover){
						anterior = anterior->prox;
					}
					anterior->prox = remover->prox;
				}
			} else {
				anterior = Lista;
				while(anterior->prox != remover){
					anterior = anterior->prox;
				}
				anterior->prox = remover->prox;
			}
			free (remover);
		} else {
			printf("Elemento não encontrado\n");
		}
	} else {
		printf("Lista vazia\n");
	}
	return Lista;
}


void imprimirLista(Elemento *Lista){
	Elemento *aux;
	if (Lista != NULL) {
		aux = Lista;
		do {
			printf("%d\n", aux->info);
			aux = aux->prox;
		} while(aux != Lista);
			
	}
	
}

