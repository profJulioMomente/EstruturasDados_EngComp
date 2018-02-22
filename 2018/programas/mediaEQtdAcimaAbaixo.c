#include<stdio.h>
#include<stdlib.h>

main() {
	float Notas[10], media, somaAcumulada=0;
	int i, qtdAcimaMedia=0, qtdAbaixoMedia=0;
	
	for(i=0; i<10; i++){
		printf("Informe a nota %d: ",i);
		scanf("%f", &Notas[i]);
		
		somaAcumulada = somaAcumulada + Notas[i];
	}
	
	media = somaAcumulada/10.0;
	
	for(i=0;i<10;i++){
		if(Notas[i] > media)
			qtdAcimaMedia++;
		else
			qtdAbaixoMedia++;
	}
	
	printf("A media e %.2f\n",media);
	printf("Tem %d alunos acima da media\n",qtdAcimaMedia);
	printf("Tem %d alunos abaixo da media\n",qtdAbaixoMedia);
	
	system("pause");
}
