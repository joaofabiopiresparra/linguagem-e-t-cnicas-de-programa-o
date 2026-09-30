#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // biblioteca para poder fazer um timer
#include <unistd.h>  // mesma coisa so que pra linux

#define LINHAS 15     // tamanho do level
#define COLUNAS 31

int main() {
	//level desing
    char mapa[LINHAS][COLUNAS] = {
        "##############################",
        "#                 #          #",
        "#   ###########   #   #####  #",
        "#     # S#        #   #   #  #",
        "#  #  #  #        #       #  #",
        "#  ####  #        #########  #",
        "#        #                   #",
        "##########                   #",
        "#            #########  #    #",
        "#            #          #    #",
        "#        #####  @    ####### #",
        "#    ##  #              #    #",
        "#    ##  #  #######     #    #",
        "#                            #",
        "##############################"
    };
    
    char tutorial[LINHAS][COLUNAS] = {
        "##############################",
        "#                            #",
        "#                            #",
        "#                            #",
        "#                            #",
        "#                            #",
        "#              #             #",
        "#              #             #",
        "#              #             #",
        "#              #             #",
        "#              #             #",
        "#              #             #",
        "#      @       #       S     #",
        "#              #             #",
        "##############################"
    };

    int jogador_x = 10;      //variavel de posicao vertical
    int jogador_y = 16;      //variavel de posicao horisontal
    char comando;           //variavel para receber o comando de movimentacao
    int jogando = 0;        //variavel para definicao de nivel
    int novo_x;             //variavel de nova posicao vertical
    int novo_y;             //variavel de nova posicao vertical
    int i;                  //variavel para "desenhar" o mapa/level vertical
    int j;                  //variavel para "desenhar" o mapa/level horisontal
	char opcao;
	int jgnd = 0;
	char noob;
	int voce_realmente_le_o_nome_das_variaveis_uau;

	void reiniciar_possisao(){
    	jogador_x = 10;
    	jogador_y = 16;
    	novo_x = 1;
    	novo_y = 1;
    	mapa [3][8] = 'S';
    	mapa [10][16] = '@';
	}


	do{
	

	printf("                 ______   _____   _____   ______     _   __  ____ _    __  ______   __ \n"   
		"	        / ____/  / ___/  / ___/  / ____/    / | / / /  _/| |  / / / ____/  / / \n "  
		"	       / __/     /__ /   /__ /   / __/     /  |/ /  / /  | | / / / __/    / / \n  "  
		"	      / /___    ___/ /  ___/ /  / /___    / /|  / _/ /   | |/ / / /___   / /___ \n  "
		"	     /_____/   /____/  /____/  /_____/   /_/ |_/ /___/   |___/ /_____/  /_____/ \n\n\n  "


		"	         ____    ______      _   __  _____  _    __   _____         ___ \n"
		"	        / __ /  / ____/     / | / / / __  /| |  / /  / __  /       /__ | \n"
		"	       / / / / / __/       /  |/ / / / / / | | / /  / / / /         / _/   \n" 
		"	      / /_/ / / /___      / /|  / / /_/ /  | |/ /  / /_/ /         /_/     \n " 
		"	     /_____/ /_____/     /_/ |_/ /_____/   |___/  /_____/         (_) "
	);
		
	printf("\n\n\n\t 		[1] JOGAR! \n\t 		[2] MENU DE NIVEIS \n\t 		[3] CREDITOS \n\t 		[4] SAIR \n\ndigite uma opcao valida: ");
	scanf (" %c", &opcao);
	
	switch(opcao)
	{
	
	case '1':
		
		jogador_x = 12;
    	jogador_y = 7;
		
		if (jgnd == 0){
			system("cls || clear");
			printf("\n\n\n\tparece ser sua primeira vez jogando!\n\n\t gostaria de fazer o tutorial?\n\n\t[1]Sim\n\t[2]Nao, ja sei jogar!\n\ndigite uma opcao valida: ");
			scanf(" %c", &noob);
			
			if (noob == '1'){
				while (noob == '1'){
				
        	system("cls || clear");  //limpa a tela (tanto no windows quanto no linux/mac)

        	printf("\t=== ESSE NIVEL DE NOVO ? ===\n\n"); // titulo do jogo
        	printf("\n\nTutorial!\n\nUtilize os comandos: : W (cima), S (baixo), A (esquerda), D (direita), Q (sair)\n\nSua tarefa e bem facil chegue na saida indicado por um [S] para completar o nivel\n\n"); //comandos do jogo
        
        	for (i = 0; i < LINHAS; i++) {
            	for (j = 0; j < COLUNAS - 1; j++) {          //redesenha o mapa usando o level desing como base
                	printf("%c", tutorial[i][j]);
            	}
            	printf("\n");
        	}


        	printf("\nProximo passo: "); // le a acao do jogador
        	scanf(" %c", &comando);

        	novo_x = jogador_x;                //guarda a possicao anterior do jogador
        	novo_y = jogador_y;

        	if (comando == 'w' || comando == 'W') novo_x--;
        	if (comando == 's' || comando == 'S') novo_x++;      //adiciona "movimentacao" para todos os lados na variavel "novo_x & y"
        	if (comando == 'a' || comando == 'A') novo_y--;
        	if (comando == 'd' || comando == 'D') novo_y++;
        	if (comando == 'q' || comando == 'Q') break;   // sai do jogo

        	if (tutorial[novo_x][novo_y] != '#') {            //verifica se a proxima "movimentacao" nao e uma parede
            	tutorial[jogador_x][jogador_y] = ' ';         //apaga a antiga posicao do jogador
	            jogador_x = novo_x;                       //(faz as variaveis de "movimentacao" antigas virarem as novas
	            jogador_y = novo_y;                       //serve para estabelecer a nova posicao do jogador)
            	tutorial[jogador_x][jogador_y] = '@';         //desenha a posicao atual do jogador
        	}
        	
        	    if (jogador_x == 12 && jogador_y == 23) {
        	    	system("cls || clear");
            		printf("\n\n\n\tPARABENS! Voce passou de fase!");
            		Sleep(3000);
            		noob = '2';
            		jogando = 1;
            		jgnd = 1;
					break;
        		}
			}
			}
			else {
				jgnd = 1;
				jogando = 1;
			}
		}

		reiniciar_possisao();

    	while (jogando == 1) {

        	system("cls || clear");  //limpa a tela (tanto no windows quanto no linux/mac)

        	printf("\t=== ESSE NIVEL DE NOVO ? ===\n\n"); // titulo do jogo
        	printf("\n\nNivel 1: Bem Simples. Chegue na 'S'aida\n\n"); //comandos do jogo
        
        	for (i = 0; i < LINHAS; i++) {
            	for (j = 0; j < COLUNAS - 1; j++) {          //redesenha o mapa usando o level desing como base
                	printf("%c", mapa[i][j]);
            	}
            	printf("\n");
        	}


        	printf("\nProximo passo: "); // le a acao do jogador
        	scanf(" %c", &comando);

        	novo_x = jogador_x;                //guarda a possicao anterior do jogador
        	novo_y = jogador_y;

        	if (comando == 'w' || comando == 'W') novo_x--;
        	if (comando == 's' || comando == 'S') novo_x++;      //adiciona "movimentacao" para todos os lados na variavel "novo_x & y"
        	if (comando == 'a' || comando == 'A') novo_y--;
        	if (comando == 'd' || comando == 'D') novo_y++;
        	if (comando == 'q' || comando == 'Q') break;   // sai do jogo

        	if (mapa[novo_x][novo_y] != '#') {            //verifica se a proxima "movimentacao" nao e uma parede
            	mapa[jogador_x][jogador_y] = ' ';         //apaga a antiga posicao do jogador
	            jogador_x = novo_x;                       //(faz as variaveis de "movimentacao" antigas virarem as novas
	            jogador_y = novo_y;                       //serve para estabelecer a nova posicao do jogador)
            	mapa[jogador_x][jogador_y] = '@';         //desenha a posicao atual do jogador
        	}
        	
        	        	if (jogador_x == 3 && jogador_y == 8) {
            			system("cls || clear");
            			printf("\n\n\n\tPARABENS! Voce passou de fase!");
            			Sleep(3000);                                       //verifica a vitoria
            			jogando = 2;
						break;
        	}
    	}
    	
		reiniciar_possisao();
    	
    	while (jogando == 2) {
    		
    		system("cls || clear"); 

        	printf("\t=== ESSE NIVEL DE NOVO ? ===\n\n");
        	printf("\n\nNivel 2: Confuso?\n\n");
        
        	for (i = 0; i < LINHAS; i++) {
            	for (j = 0; j < COLUNAS - 1; j++) {
                	printf("%c", mapa[i][j]);
            	}
            	printf("\n");
        	}

        	if (jogador_x == 3 && jogador_y == 8) {
            	system("cls || clear");
            	printf("\n\n\n\tPARABENS! Voce passou de fase!");
            	Sleep(3000);
            	jogando = 2;
				break;
        	}

        	printf("\nProximo passo: ");
        	scanf(" %c", &comando);

        	novo_x = jogador_x;
        	novo_y = jogador_y;

        	if (comando == 'w' || comando == 'W') novo_x++;
        	if (comando == 's' || comando == 'S') novo_x--;
        	if (comando == 'a' || comando == 'A') novo_y++;
        	if (comando == 'd' || comando == 'D') novo_y--;
        	if (comando == 'q' || comando == 'Q') break;

        	if (mapa[novo_x][novo_y] != '#') {
            	mapa[jogador_x][jogador_y] = ' ';
	            jogador_x = novo_x;
	            jogador_y = novo_y;
            	mapa[jogador_x][jogador_y] = '@';
        	}
		}
    
	
    break;
    
    case '2':
    
		system("cls || clear");
    	printf("\n\n\tSelecao de niveis:\n\t[1]Nivel 1: Bem Simple\n\t[2]Nivel 2: Confuso?\n\ndigite uma opcao valida: ");
    	scanf("%d", &voce_realmente_le_o_nome_das_variaveis_uau);
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 1) {jogando = 1; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 2) {jogando = 2; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 401){
    		system("cls || clear");
    		printf("\n\n\t      . - - - - - - .    \n"
   		"\t . '                   ' .    \n"
 		"\t.                         .  \n"
 		"\t.     ( O )     ( O )     .  \n"
        "\t.                         .  \n"
 		"\t.                         .  \n"
 		"\t.                         .  \n"
 		"\t.   |                 |   .  \n"
 		"\t.   |                 |   .  \n"
 		"\t.    ' .           . '    .  \n"
 		"\t  .      ' - - - '      .    \n"
 		"\t    ' .               . '    \n"
  		"\t       ' - - - - - '         \n\n\n\t	YOU ARE A IDIOT");
  		opcao = '4';
  		Sleep(1000);
		}
    	break;
    	
    case '3':
    	system("cls || clear");
    	printf("\n\n\n\tCreditos\n\n\tCriadores:\n\n\tJoao Fabio Pires Parra (MootStarling401)\n\n\tArthur da Silva Mota\n\n\tLucas Masaki Sversuti");
    	Sleep(5000);
    	break;
    	
	}
	system("cls || clear");
} while (opcao != '4');

    return 0;
}
