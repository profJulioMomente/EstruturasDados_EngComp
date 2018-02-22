#include<stdio.h>
#include<stdlib.h>

main () {
	float n1, n2, n3, n4, media;
	
	printf("Informe a primeira nota: ");
	scanf("%f", &n1);
	printf("Informe a segunda nota: ");
	scanf("%f", &n2);
	printf("Informe a teceira nota: ");
	scanf("%f", &n3);
	printf("Informe a quarta nota: ");
	scanf("%f", &n4);
	
	media = (n1+n2+n3+n4)/4;
	
	if(media>=7) {
		printf("\nAprovado\n");
	} else if (media < 4) {
		printf("\nReprovado\n");
	} else {
		printf("\nExame\n");
	}
	
	system("pause");
}
