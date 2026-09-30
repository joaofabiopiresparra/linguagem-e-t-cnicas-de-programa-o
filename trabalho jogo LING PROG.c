#include <stdio.h>
#include <stdlib.h>

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

    int jogador_x = 10;      //variavel de posicao vertical
    int jogador_y = 16;      //variavel de posicao horisontal
    char comando;           //variavel para receber o comando de movimentacao
    int jogando = 1;        //variavel para definicao de nivel
    int novo_x;             //variavel de nova posicao vertical
    int novo_y;             //variavel de nova posicao vertical
    int i;                  //variavel para "desenhar" o mapa/level vertical
    int j;                  //variavel para "desenhar" o mapa/level horisontal

	printf("                 ______   _____   _____   ______     _   __  ____ _    __  ______   __ \n"   
		"	        / ____/  / ___/  / ___/  / ____/    / | / / /  _/| |  / / / ____/  / / \n "  
		"	       / __/     /__ /   /__ /   / __/     /  |/ /  / /  | | / / / __/    / / \n  "  
		"	      / /___    ___/ /  ___/ /  / /___    / /|  / _/ /   | |/ / / /___   / /___ \n  "
		"	     /_____/   /____/  /____/  /_____/   /_/ |_/ /___/   |___/ /_____/  /_____/ \n\n\n  "


		"	         ____    ______      _   __  ____ _    __  ____          ___ \n"
		"	        / __ /  / ____/     / | / / / __ / |  / / / __ /        /__ | \n"
		"	       / / / / / __/       /  |/ / / / / / | / / / / / /         / _/   \n" 
		"	      / /_/ / / /___      / /|  / / /_/ /| |/ / / /_/ /         /_/     \n " 
		"	     /_____/ /_____/     /_/ |_/  /____/ |___/  /____/         (_) "
	);
		
	printf("\n\n\n\t[1] JOGAR! \n\t[2] MENU DE NIVEIS \n\t[3] CREDITOS");

    /*while (jogando = 1) {
        system("cls || clear");  //limpa a tela (tanto no windows quanto no linux/mac)

        printf("\t=== ESSE NIVEL DE NOVO ===\n"); // titulo do jogo
        printf("Comandos: W (cima), S (baixo), A (esquerda), D (direita), Q (sair)\n\n"); //comandos do jogo
        
        for (i = 0; i < LINHAS; i++) {
            for (j = 0; j < COLUNAS - 1; j++) {          //redesenha o mapa usando o level desing como base
                printf("%c", mapa[i][j]);
            }
            printf("\n");
        }

        if (jogador_x == 3 && jogador_y == 8) {
            printf("\nPARABENS! Voce passou de fase!\n"); //verifica a vitoria
            break;
        }

        printf("\nProximo passo: "); // le a acao do jogador
        scanf(" %c", &comando);

        novo_x = jogador_x;                //guarda a possicao anterior do jogador
        novo_y = jogador_y;

        if (comando == 'w' || comando == 'W') novo_x--;
        if (comando == 's' || comando == 'S') novo_x++;      //adiciona "movimentacao" para todos os lados na variavel "novo_x & y"
        if (comando == 'a' || comando == 'A') novo_y--;
        if (comando == 'd' || comando == 'D') novo_y++;
        if (comando == 'q' || comando == 'Q') jogando = 0;   // sai do jogo

        if (mapa[novo_x][novo_y] != '#') {            //verifica se a proxima "movimentacao" nao e uma parede
            mapa[jogador_x][jogador_y] = ' ';         //apaga a antiga posicao do jogador
            jogador_x = novo_x;                       //(faz as variaveis de "movimentacao" antigas virarem as novas
            jogador_y = novo_y;                       //serve para estabelecer a nova posicao do jogador)
            mapa[jogador_x][jogador_y] = '@';         //desenha a posicao atual do jogador
        }
    }*/

    return 0;
}
