#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "forca.h"



char palavrasecreta [TAMANHO_PALAVRA];
char chutes [26];
int chutesdados = 0;


void abertura() {
	printf("**********************\n");
	printf("*   Jogo de Forca    *\n");
	printf("**********************\n\n");
}

void chuta(){
	char chute;
	printf("Qual a letra? ");
	scanf(" %c", &chute);
	 if(letraexiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", 
            chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", 
            chute);
    }
	chutes[chutesdados] = chute;
	chutesdados++;
	}

int jachutou(char letra){
	int achou = 0;
	int j;
	for(j = 0; j < chutesdados; j++){
		if(chutes[j] == letra){
			achou = 1;
			break;
			}
		}
	return achou;
}

void desenhaforca() {

	int erros = chuteserrados();

	printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
	    (erros>=1?'_':' '), (erros>=1?')':' '));
	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
	    (erros>=2?'|':' '), (erros>=3?'/': ' '));
	printf(" |       %c     \n", (erros>=2?'|':' '));
	printf(" |      %c %c   \n", (erros>=4?'/':' '), 
	    (erros>=4?'\\':' '));
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");

	printf("Você já deu %d chutes\n", chutesdados);
	int i;
	for(i = 0; i < strlen(palavrasecreta); i++) {

		if(jachutou(palavrasecreta[i])) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}

	}
	printf("\n");
}

void adicionapalavra(){

	setlocale(LC_ALL,"");
	char quer;
	printf("Você deseja adicionar uma nova palavra no jogo? (S ou N)\n");
	scanf(" %c", &quer);

	if (quer == 'S'){
		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra?\n");
		scanf("%s", novapalavra);
	
		FILE* f;
		f = fopen("palavras.txt", "r+");
		if (f == 0){
		printf("Desculpe, banco de dados não disponível\n");
		exit(1);
	}

		int qtd;
		fscanf(f,"%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);
		fclose(f);
	}
}

void escolhepalavra(){
	FILE* f;

	f = fopen("palavras.txt", "r");
	if (f == 0){
		printf("Desculpe, banco de dados não disponível\n");
		exit(1);
	}
	srand(time(0));

	int qtddepalavras;
	fscanf(f,"%d", &qtddepalavras);

	int randomico = rand() % qtddepalavras;
	int i;
	for(i = 0; i <= randomico; i++){
		fscanf(f, "%s", palavrasecreta);
	}

	fclose(f);
}

int acertou (){
	int i;
	for (i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}

	return 1;
}
int letraexiste(char letra) {
	int j;
    for(j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }

    return 0;
}
int chuteserrados(){
	int i,j;
	int erros = 0;
	for(i = 0; i < chutesdados; i++){
		int existe = 0;

		for (j = 0; j < strlen(palavrasecreta); j++){
		if(chutes[i] == palavrasecreta[j]){
			existe = 1;
			break;
			}	
		}

		if(!existe) erros ++;
	}
	return erros;
}

int enforcou (){
	
	return chuteserrados() >= 5;
}

int main(){

	setlocale(LC_ALL,"");
	escolhepalavra();
	abertura();

	do {
		
		desenhaforca ();
		chuta();

	} while (!acertou() && !enforcou());

	if(acertou()) {
    printf("\nParabéns, você ganhou!\n\n");
    printf("A palavra foi **%s**\n\n", palavrasecreta);

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");

	} else {
    printf("\nVocê foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavrasecreta);

    printf("    _______________         \n");
    printf("   /               \\       \n"); 
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");
	}

	adicionapalavra();
}
