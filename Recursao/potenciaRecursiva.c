#include<stdio.h>
#include<stdlib.h>

float potencia(float base, int exp);

main () {
	float base, pot;
	int exp;
	
	printf("Informe a base: ");
	scanf("%f", &base);
	
	printf("Informe o expoente: ");
	scanf("%d", &exp);
	
	pot = potencia(base, exp);
	
	printf("%f ^ %d = %f\n\n", base, exp, pot);
	
	system("pause");
}

float potencia(float base, int exp){
	if(exp == 0) {
		return 1;
	} else {
		return base * potencia(base, exp-1);
	}
}

