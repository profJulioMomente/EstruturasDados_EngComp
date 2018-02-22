#include<stdio.h>
#include<stdlib.h>

main () {
	int numeroPessoas, idade, somaAcumulada=0, qtdMaiores=0, i;
	float media;
	
	printf("Informe o numero de pessoas: ");
	scanf("%d", &numeroPessoas);
	
	for (i=0; i<numeroPessoas; i++){
		printf("\nInforme a idade: ");
		scanf("%d", &idade);
		
		somaAcumulada = somaAcumulada + idade;
		
		if(idade >= 18)
			qtdMaiores++;
	}
	
	media = somaAcumulada/numeroPessoas;
	
	printf("A media de idade e %f\n", media);
	printf("Tem %d pessoas acima de 18 anos\n", qtdMaiores);
	
	system("pause");
}
