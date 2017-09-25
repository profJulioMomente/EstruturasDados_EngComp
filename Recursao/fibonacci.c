#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n);
int fibonacci2(int n);

main(){
	int fib, n;
	
	printf("Informe um valor inteiro: ");
	scanf("%d", &n);
	if(n>=0) {
		fib = fibonacci2(n);
		
		printf("Fibonacci(%d) = %d\n\n", n, fib);
	} else {
		printf("Valor incorreto\n\n");
	}
	system("pause");
	
}

int fibonacci(int n){
	int i,fib=0, primeiroAnterior =1, segundoAnterior=0;
	
	if(n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		for(i=2; i<=n; i++){
			fib = primeiroAnterior+segundoAnterior;
			segundoAnterior = primeiroAnterior;
			primeiroAnterior = fib;
		}
		return fib;
	}
}

int fibonacci2(int n){
	if(n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fibonacci2(n-1) + fibonacci2(n-2);
	}
	
	
}
