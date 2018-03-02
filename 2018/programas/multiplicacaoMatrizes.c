#include<stdio.h>
#include<stdlib.h>

main() {
	float A[3][3], B[3][3], R[3][3];
	int i, j, k;
	
	//leitura da primeira matriz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("A[%d][%d]: ",i,j);
			scanf("%f", &A[i][j]);
		}
	}
	
	//leitura da segunda matriz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("B[%d][%d]: ",i,j);
			scanf("%f", &B[i][j]);
		}
	}
	
	//inicialização da matriz R
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			R[i][j] = 0.0;
		}
	}
	
	//Multiplicacao
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				R[i][j] = R[i][j] + A[i][k]*B[k][j];
			}
		}
	}
	
	
	//Impressao do resultado
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%03.3f\t\t",R[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
}
