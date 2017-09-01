#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *arq;

void Troca(int *V1, int *V2);
int* alocaVetor(int *V, int tam);
void ordenaSelecao( int *V, int tam);
void leArquivo(int *V, int tam);
int escreveArquivo(int *V, int tam);
int abrirArquivo(const char *modo);
void fecharArquivo();

main (){
	int *Vetor, tam;
	clock_t t_inicio, t_final;
	float tempo;
	char Arquivo[100];
	
	/*
	retorno da fun��o 0 = erro de abertura, 1 = sucesso na abertura
	0 <==> Falso, 1 <==> Verdade
	o s�mbolo (!) significa o operador l�gico N�O
	*/
	if(!abrirArquivo("r")){ 
		return;
	}
	
	fscanf(arq, "%d", &tam); //Leitura da quantidade de valores
	Vetor = alocaVetor(Vetor, tam);
	leArquivo(Vetor, tam);
	fecharArquivo();
	
	
	t_inicio = clock();
	ordenaSelecao(Vetor, tam);
	t_final = clock();
	
	
	tempo = ((float)t_final - (float)t_inicio)/CLOCKS_PER_SEC;
	printf("O tempo de ordenacao foi de %f segundos\n\n", tempo);
	
	
	if(!escreveArquivo(Vetor, tam)){
		return;
	}
	
	
	system("pause");
	
	return;
	
}

void Troca(int *V1, int *V2){
	int aux;
	
	aux = *V1;
	*V1 = *V2;
	*V2 = aux;
}

int* alocaVetor(int *V, int tam){ 
	V = (int*) malloc(tam*sizeof(int));
	
	return V;
}

void ordenaSelecao( int *V, int tam){
	int i, j, min;
	
	for(i=0; i<tam-1; i++){ //La�o para ordenar o vetor
		min = i;
		for(j=i+1; j<tam; j++){ //la�o para encontrar o menor valor
			if(V[j] < V[min]){
				min = j;
			}
		}
		Troca(&V[i], &V[min]);
	}
	
}


void leArquivo(int *V, int tam){
	int i;
	for (i=0; i<tam; i++){
		fscanf(arq, "%d", &V[i]);
	}
}

int abrirArquivo(const char *modo){
	char Arquivo[200];
	
	printf("Informe o nome do arquivo com extensao: ");
	scanf(" %[^\n]s", Arquivo);
	
	if((arq = fopen(Arquivo, modo))== NULL){
		printf("\nO arquivo nao pode ser aberto\n");
		return 0;
	}
	
	return 1;
}

void fecharArquivo(){
	fclose(arq);	
}


int escreveArquivo(int *V, int tam){
	int i;
	
	if(!abrirArquivo("w")){
		return 0;
	}
	fprintf(arq, "%d\n", tam);
	for(i=0; i<tam; i++){
		fprintf(arq, "%d\n", V[i]);
	}
	
	fecharArquivo();
	return 1;
}
