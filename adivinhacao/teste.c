#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	/*
	int a = abs(3);
	int b = abs(-2);

	int c = abs (a*b);
	/*double pontos = (double)a / (double)b;
	printf ("%f\n", pontos);
	
	printf("%d \n",c);
	
	int segundos = time(0);
	srand(segundos);

	int n1 = rand ();
	int n2 = rand();
	printf("%d %d ", n1,n2);
	*/

	int i;
	int numero;
	printf("Digite um numero inteiro:");
	scanf("%d",&numero);	
	for(i = 1; i <=10; i++){
	int multiplicacao = numero * i;
	printf("%d x %d = %d \n", numero, i, multiplicacao);
	}


}