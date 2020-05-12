#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){


	printf("	          P  /_\\  P                                  \n");         
	printf("	         /_\\_|_|_/_\\                                \n");
	printf("	     n_n | ||. .|| | n_n         Bem vindo ao    	  \n");
	printf("	     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!	  \n");
	printf("	    |" "  |  |_|  |"  " |                       	  \n");
	printf("	    |_____| ' _ ' |_____|                             \n");
	printf("	          \\__|_|__/								  \n");



	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();

	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Facil , (2) Medio, (3) Dificil\n");
	scanf("%d", &nivel);

	int numerodetentativas;

	switch (nivel){
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 10;
			break;
		default:
			numerodetentativas = 5;
			break;
	}

	int i;

	for(i = 1; i <= numerodetentativas; i++){

		printf("Tentativa %d \n", tentativas);
		printf("Qual e o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi: %d \n", chute);

	if (chute < 0) {
		printf("Voce nao pode chutar numeros negativos\n");
		continue;
	}

  		acertou = (chute == numerosecreto);
  		int maior = (chute > numerosecreto);	
	
  	if (acertou){
  		break;
  	}

  	else if (maior){
  		printf("\nOps, voce errou, tente novamente!\n");
  		printf("Seu chute foi maior que o numero secreto\n");
  	}
  	else {
  		printf("\nOps, voce errou, tente novamente!\n");
  		printf("Seu chute foi menor que o numero secreto\n");
  	}
  	
  	tentativas ++;

  	double pontosperdidos = abs(chute - numerosecreto) / (double)2;
  	pontos = pontos - pontosperdidos;
  }

  printf ("Fim de jogo!\n");

  if (acertou){


		printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
		
  		printf("Voce ganhou!\n");
  		printf("Voce acertou em %d tentativas!\n", tentativas);
  		printf("Total de pontos: %.2f\n", pontos);

  }
  	else{
  		printf("Voce perdeu! Tente novamente\n");

        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
  } 
}
