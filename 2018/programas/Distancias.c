#include<stdio.h>
#include<stdlib.h>

main() {
	float Distancias[5][5];
	int i, j;
	
	//leitura das distancias
	for(i=0;i<5;i++){ //linhas
		Distancias[i][i] = 0;
		for(j=i+1;j<5;j++){ //colnas
			printf("\nInforme a distancia da cidade %d a cidade %d: ",i,j);
			scanf("%f", &Distancias[i][j]);
			Distancias[j][i]=Distancias[i][j];
		}
	}
	
	//impressão
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%.3f\t",Distancias[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
}
