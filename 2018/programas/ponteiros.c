#include<stdio.h>
#include<stdlib.h>

main(){
	int a;
	int *ptr; //declaração de ponteiro
	
	a = 5;
	ptr = &a;
	
	
	printf("valor de a %d -- endereco de a %d\n", a, &a);
	printf("valor de ptr %d -- endereco de ptr %d \
	-- valor apontado por ptr %d\n", ptr, &ptr, *ptr);
	
	
	system("pause");
	
}
