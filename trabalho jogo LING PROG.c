#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // biblioteca para poder fazer um timer
#include <unistd.h>  // mesma coisa so que pra linux
#include <conio.h>//_getch()

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
    
    char mapa2[LINHAS][COLUNAS]={
		"##############################",
		"#                           S#",
		"#                            #",
		"#,,,,,,,,               ######",
		"#,,,,,,,,,,     B            #",
		"#,,,,,,,,                    #",
		"#,,,,,                       #",
	 	"#...,,                       #",
		"#...,,                       #",
		"#===,,                       #",
		"#===,,                       #",
		"#                            #",
		"#                            #",
		"#                            #",
		"##############################"
	};
	
	char mapa2_2[LINHAS][COLUNAS]={
		"##############################",
		"#                            #",
		"#                            #",
		"#--------                    #",
		"#----------                  #",
		"#--------                    #",
		"#-----                       #",
		"#===--                       #",
		"#===--                       #",
		"#...--                       #",
		"#...--                       #",
		"#                            #",
		"#                            #",
		"#                            #",
		"##############################"
	};

	char mapa_giratorio_base[LINHAS][COLUNAS] = { // Fase 7: # e parede, espaco e caminho, S e saida.
		"##############################",
		"#@                         #",
		"# ### ## ### ### ### #      #",
		"#   #    #   #   #   #      #",
		"# # # ## # # # # # # #      #",
		"# #   #  # # # # # # #      #",
		"# ### # ## # # # # # #      #",
		"#   # #    #   #   #        #",
		"# # # #### ## ### ### ###  #",
		"# #   #    #   #   #   #    #",
		"# ### # ## # # ### # # #    #",
		"#     #  # #   #   # #      #",
		"# ### ## # #### ### # ###  S#",
		"#                          #",
		"##############################"
	};
	char mapa_giratorio[LINHAS][COLUNAS]; // Mapa da fase 7 que pode ser girado.
	int jogador_giratorio_x = 1; // Linha atual do jogador na fase 7.
	int jogador_giratorio_y = 1; // Coluna atual do jogador na fase 7.
	int giro; // Quantidade de giros sorteada para cada movimento.
	char mapa_invertido[LINHAS][COLUNAS] = { // Fase 8: paredes e passagens sao montadas ao iniciar.
		"##############################",
		"#@                          #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"##############################"
	};
	int jogador_invertido_x = 1; // Linha atual do jogador na fase 8.
	int jogador_invertido_y = 1; // Coluna atual do jogador na fase 8.
	int inverter_comandos = 0; // 0 aplica o comando normal; 1 aplica o inverso.
	char mapa_fase9_base[LINHAS][COLUNAS] = { 
		"##############################",
		"#@                          #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"#                            #",
		"##############################"
	};
	char mapa_fase9[LINHAS][COLUNAS]; 
	int jogador_fase9_x = 1; 
	int jogador_fase9_y = 1; 
	int chaves_fase9 = 0; // Numero de chaves que o jogador ja coletou.

    int jogador_x = 10;      //variavel de posicao vertical
    int jogador_y = 16;      //variavel de posicao horisontal
    char comando;           //variavel para receber o comando de movimentacao
    int jogando = 0;        //variavel para definicao de nivel
    int novo_x = jogador_x;             //variavel de nova posicao vertical
    int novo_y = jogador_y;             //variavel de nova posicao vertical
    int i;                  //variavel para "desenhar" o mapa/level vertical
    int j;                  //variavel para "desenhar" o mapa/level horisontal
	char opcao;
	int jgnd = 0;
	char noob;
	int voce_realmente_le_o_nome_das_variaveis_uau;
	char senha_correta[5] = {'s', 'e', 'n', 'h', 'a'}; 
	char senha_digitada[5]; 
	int senha_valida = 1;
	int porta_trancada = 1;
	
	int andar =1, escada;
	int blocox, blocoy, movx, movy, quedax, queday, andar_pedra, blocox2, blocoy2, andar_pedra2;

	void reiniciar_possisao(){
    	jogador_x = 10;
    	jogador_y = 16;
		mapa[novo_x][novo_y] = ' ';
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
        	//scanf(" %c", &comando);
        	comando = _getch();

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
            		printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            		printf("\n\tAperte [ENTER] para continuar...");
	            	getchar(); getchar(); 
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
        	//scanf(" %c", &comando);
        	comando = _getch();
        	
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
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            getchar(); getchar();                                        //verifica a vitoria
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
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            getchar(); getchar(); 
            	jogando = 3;
				break;
        	}

        	printf("\nProximo passo: ");
        	//scanf(" %c", &comando);
        	comando = _getch();

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
		
		reiniciar_possisao();
		if (jogando == 3){
	    	for(i=10;i<18;i++){
				mapa[5][i]='P';
			}
		}
	
	    while (jogando == 3) {
			
	        system("cls || clear"); 
	
	        printf("\t=== ESSE NIVEL DE NOVO ? ===\n\n");
	        printf("\n\nNivel 3: (SSS) Senha Super Secreta\n\n");
	        
	        for (i = 0; i < LINHAS; i++) {
	            for (j = 0; j < COLUNAS - 1; j++) {
	                printf("%c", mapa[i][j]);
	            }
	            printf("\n");
	        }
	
	        if (jogador_x == 3 && jogador_y == 8) {
            	system("cls || clear");
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            getchar(); getchar(); 
            	jogando = 4;
				for(i=10;i<18;i++){
					mapa[5][i]=' ';
				}
				senha_valida = 1;
				porta_trancada = 1;
				break;
        	}
	
	        printf("\nProximo passo: ");
	        //scanf(" %c", &comando);
	        comando = _getch();
	
	        novo_x = jogador_x;
	        novo_y = jogador_y;
	
	        if (comando == 'w' || comando == 'W') novo_x--;
	        if (comando == 's' || comando == 'S') novo_x++;
	        if (comando == 'a' || comando == 'A') novo_y--;
	        if (comando == 'd' || comando == 'D') novo_y++;
	        if (comando == 'q' || comando == 'Q'){
	        	for(i=10;i<18;i++){
					mapa[5][i]=' ';
				}
				senha_valida = 1;
				porta_trancada = 1;
				break;
			}
	
	        if (mapa[novo_x][novo_y] == 'P' && porta_trancada == 1) {
	            printf("\nDigite senha: \n");
	
	            for (i = 0; i < 5; i++) {
	                scanf(" %c", &senha_digitada[i]);
	            }
	
	            for (i = 0; i < 5; i++) {
	                if (senha_digitada[i] != senha_correta[i]) {
	                    senha_valida = 0;
	                }
	            }
	
	            if (senha_valida == 1) {
	                printf("\nBOA! A porta se abriu!\n");
	                porta_trancada = 0;
	                for(i=10;i<18;i++){
						mapa[5][i]=' ';
					} 
	                printf("Aperte [ENTER] para continuar...");
	                getchar(); getchar(); 
	            } else {
	                printf("\nERROOUUU, tente novamente.\n"); 
	                printf("Aperte [ENTER] para continuar...");
	                senha_valida = 1;
	                getchar(); getchar();
	            }
	            
	            continue; 
	        }
	
	        if (mapa[novo_x][novo_y] != '#') {
	            mapa[jogador_x][jogador_y] = ' '; 
	            jogador_x = novo_x;
	            jogador_y = novo_y;
	            mapa[jogador_x][jogador_y] = '@'; 
	        }
	    }
	    
	    //==================Arthur================================================================================================================================================================================================
	    reiniciar_possisao();
	    
	    andar_pedra=1;
	    blocox = 8;
		blocoy = 10;
	    
	    if (jogando == 4){
	    	for(i=1;i<3;i++){
				mapa2[i][24]='P';
			}
		}

		while(jogando == 4){

			system("cls||clear");
				
			printf("\nNivel 4: Voce nao parece ser pesado o suficiente\n");
			
			for (i = 0; i < LINHAS; i++) {
        		for (j = 0; j < COLUNAS - 1; j++) {
        			
		            if (i == jogador_x && j == jogador_y) {
		            printf("@");}
		            
		            else if (andar_pedra==andar && i==blocox && j==blocoy){
		            	printf("o");}
		            
			        else if (andar == 1) {
			            printf("%c", mapa2[i][j]);}
			            
			        else if (andar == 2) {
			            printf("%c", mapa2_2[i][j]);}
            	
        	}
        	printf("\n");
    	}
			
			
				printf("\nProximo passo: ");
				comando = _getch();
				
				novo_x = jogador_x;
		        novo_y = jogador_y;
				
				if (comando == 'w' || comando == 'W') novo_x--;
				if (comando == 's' || comando == 'S') novo_x++;
				if (comando == 'a' || comando == 'A') novo_y--;
				if (comando == 'd' || comando == 'D') novo_y++;
				if (comando == 'q' || comando == 'Q') break;
				
				
				if(andar==1){
					
						if (mapa2[novo_x][novo_y] != '#'&& mapa2[novo_x][novo_y] !='P'||porta_trancada==0) {
							
							if (andar_pedra==1 && novo_x==blocox && novo_y==blocoy){
								
								movx = blocox + (novo_x - jogador_x);
							    movy = blocoy + (novo_y - jogador_y);
							
							    if (movx>=0 && movx<LINHAS && movy>=0 && movy<COLUNAS-1) {
							
							        if (mapa2[movx][movy] == 'B') {
							
							            blocox = movx;
							            blocoy = movy;
							
							            porta_trancada = 0;
							            
							            for (i = 1; i < 3; i++) {
    										mapa2[i][24] = ' ';} //apaga a barreira
							        }
							
							        else if (mapa2[movx][movy] != '#' &&
							                 mapa2[movx][movy] != 'P') {
							
							            blocox = movx;
							            blocoy = movy;
							        }
							
							        else {
							            continue;
							        }
							
							        jogador_x = novo_x;
							        jogador_y = novo_y;
							    }
							}
				
						if(mapa2[novo_x][novo_y]=='='){
							printf("\ndeseja subir? (1-sim/2-nao): ");
							scanf("%d", &escada);
							
							if(escada==1){
								andar=2;
								jogador_x=6; //posição que o @ aparece no 2º andar
								jogador_y=2;
								continue;
							}
				
						}
						if (mapa2[novo_x][novo_y] != '#') {
			    		
			    		jogador_x = novo_x;
			    		jogador_y = novo_y;
			    		
						}
						
					}
				}
				
				if(andar==2){
					
					if (mapa2_2[novo_x][novo_y] != '#') {
						
						if (andar_pedra==2 && novo_x==blocox && novo_y==blocoy){
							
							blocox = novo_x;
            				blocoy = novo_y;
            				
            				movx = blocox + (novo_x - jogador_x);
            				movy = blocoy + (novo_y - jogador_y);
            				
            				if(mapa2_2[movx][movy]){//queda do bloco 
            					if (mapa2_2[movx][movy]==' '){
            						
            						quedax=4;  //printa o bloco na parte de baixo
            						queday=11;
            						
            						blocox = quedax;
							        blocoy = queday;
							        andar_pedra = 1;
            						
            						jogador_x = novo_x;
                        			jogador_y = novo_y;
								}
								
								else if (mapa2_2[movx][movy]!='#' && mapa2_2[movx][movy]!='o'){
									blocox = movx;
							        blocoy = movy;
							
							        jogador_x = novo_x;
							        jogador_y = novo_y;
								}
							}
            				
            				if (mapa2_2[movx][movy] != '#'){//movimento do bloco
            					
            					jogador_x = novo_x;
            					jogador_y = novo_y;
							}
						}
					
					else if(mapa2_2[novo_x][novo_y]=='='){
							printf("\ndeseja descer? (1-sim/2-nao): ");
							scanf("%d", &escada);
					
						if(escada==1){
							andar=1;
							jogador_x = 9;
                    		jogador_y = 4;
							continue;
						}		
					}
					
					if (mapa2_2[novo_x][novo_y] == '-') {
			        jogador_x = novo_x;
			        jogador_y = novo_y;
			    	}
				}
		}
		
		if (mapa2[jogador_x][jogador_y]=='S') {
            	system("cls || clear");
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            getchar(); getchar(); 
            	jogando = 5;
				break;
        	}
				
}
	    
	    
//2)	    
	    reiniciar_possisao();
	    
	    andar_pedra=2;
	    blocox = 4;
		blocoy = 10;
	    
	    if (jogando == 5){
	    	for(i=1;i<3;i++){
				mapa2[i][24]='P';
			}
		}

		while(jogando == 5){

			system("cls||clear");
				
			printf("\nNivel 5: Parece ter algo la em cima.\n");
			
			for (i = 0; i < LINHAS; i++) {
        		for (j = 0; j < COLUNAS - 1; j++) {
        			
		            if (i == jogador_x && j == jogador_y) {
		            printf("@");}
		            
		            else if (andar_pedra==andar && i==blocox && j==blocoy){
		            	printf("o");}
		            
			        else if (andar == 1) {
			            printf("%c", mapa2[i][j]);}
			            
			        else if (andar == 2) {
			            printf("%c", mapa2_2[i][j]);}
            	
        	}
        	printf("\n");
    	}
			
			
				printf("\nProximo passo: ");
				comando = _getch();
				
				novo_x = jogador_x;
		        novo_y = jogador_y;
				
				if (comando == 'w' || comando == 'W') novo_x--;
				if (comando == 's' || comando == 'S') novo_x++;
				if (comando == 'a' || comando == 'A') novo_y--;
				if (comando == 'd' || comando == 'D') novo_y++;
				if (comando == 'q' || comando == 'Q') break;
				
				
				if(andar==1){
					
						if (mapa2[novo_x][novo_y] != '#'&& mapa2[novo_x][novo_y] !='P'||porta_trancada==0) {
							
							if (andar_pedra==1 && novo_x==blocox && novo_y==blocoy){
								
								movx = blocox + (novo_x - jogador_x);
							    movy = blocoy + (novo_y - jogador_y);
							
							    if (movx>=0 && movx<LINHAS && movy>=0 && movy<COLUNAS-1) {
							
							        if (mapa2[movx][movy] == 'B') {
							
							            blocox = movx;
							            blocoy = movy;
							
							            porta_trancada = 0;
							            
							            for (i = 1; i < 3; i++) {
    										mapa2[i][24] = ' ';} //apaga a barreira
							        }
							
							        else if (mapa2[movx][movy] != '#' &&
							                 mapa2[movx][movy] != 'P') {
							
							            blocox = movx;
							            blocoy = movy;
							        }
							
							        else {
							            continue;
							        }
							
							        jogador_x = novo_x;
							        jogador_y = novo_y;
							    }
							}
				
						if(mapa2[novo_x][novo_y]=='='){
							printf("\ndeseja subir? (1-sim/2-nao): ");
							scanf("%d", &escada);
							
							if(escada==1){
								andar=2;
								jogador_x=6; //posição que o @ aparece no 2º andar
								jogador_y=2;
								continue;
							}
				
						}
						if (mapa2[novo_x][novo_y] != '#') {
			    		
			    		jogador_x = novo_x;
			    		jogador_y = novo_y;
			    		
						}
						
					}
				}
				
				if(andar==2){
					
					if (mapa2_2[novo_x][novo_y] != '#') {
						
						if (andar_pedra==2 && novo_x==blocox && novo_y==blocoy){
							
							blocox = novo_x;
            				blocoy = novo_y;
            				
            				movx = blocox + (novo_x - jogador_x);
            				movy = blocoy + (novo_y - jogador_y);
            				
            				if(mapa2_2[movx][movy]){//queda do bloco 
            					if (mapa2_2[movx][movy]==' '){
            						
            						quedax=4;  //printa o bloco na parte de baixo
            						queday=11;
            						
            						blocox = quedax;
							        blocoy = queday;
							        andar_pedra = 1;
            						
            						jogador_x = novo_x;
                        			jogador_y = novo_y;
								}
								
								else if (mapa2_2[movx][movy]!='#' && mapa2_2[movx][movy]!='o'){
									blocox = movx;
							        blocoy = movy;
							
							        jogador_x = novo_x;
							        jogador_y = novo_y;
								}
							}
            				
            				if (mapa2_2[movx][movy] != '#'){//movimento do bloco
            					
            					jogador_x = novo_x;
            					jogador_y = novo_y;
							}
						}
					
					else if(mapa2_2[novo_x][novo_y]=='='){
							printf("\ndeseja descer? (1-sim/2-nao): ");
							scanf("%d", &escada);
					
						if(escada==1){
							andar=1;
							jogador_x = 9;
                    		jogador_y = 4;
							continue;
						}		
					}
					
					if (mapa2_2[novo_x][novo_y] == '-') {
			        jogador_x = novo_x;
			        jogador_y = novo_y;
			    	}
				}
		}
		
		if (mapa2[jogador_x][jogador_y]=='S') {
            	system("cls || clear");
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            getchar(); getchar(); 
            	jogando = 6;
				break;
        	}
				
}

//3)
	    reiniciar_possisao();
	    
	    andar_pedra=2;
	    andar_pedra2=1;
	    blocox = 4;
		blocoy = 10;
		blocox2 = 3;
		blocoy2 = 20;
	    
	    if (jogando == 6){
	    	for(i=1;i<3;i++){
				mapa2[i][24]='P';
			}
			for(i=4;i<20;i++){
				mapa2[i][24]='#';
			}

			for(i = 1; i < 9; i++){
		    	for(j = 1; j < 10; j++){
		        	mapa2[i][j] = '#';
		    	}
			}
			for(i = 11; i < 16; i++){
				for(j = 1; j < 25; j++){
					mapa2[i][j] = '#';
				}
			}
			for(i = 12; i < 15; i++){
			    for(j = 2; j < 23; j++){
			        mapa2[i][j] = '#';
			    }
			}
			
			mapa2[9][22] = 'B';

		}

		while(jogando == 6){

			system("cls||clear");
				
			printf("\nNivel 6\n");
			
			for (i = 0; i < LINHAS; i++) {
        		for (j = 0; j < COLUNAS - 1; j++) {
        			
		            if (i == jogador_x && j == jogador_y) {
		            printf("@");}
		            
		            else if (andar_pedra==andar && i==blocox && j==blocoy){
		            	printf("o");}
		            	
		            else if (andar_pedra2==andar && i==blocox2 && j==blocoy2){
		            	printf("o");}
		            
			        else if (andar == 1) {
			            printf("%c", mapa2[i][j]);}
			            
			        else if (andar == 2) {
			            printf("%c", mapa2_2[i][j]);}
            	
        	}
        	printf("\n");
    	}
			
			
				printf("\nProximo passo: ");
				comando = _getch();
				
				novo_x = jogador_x;
		        novo_y = jogador_y;
		        
		        if (andar_pedra==1 && andar_pedra2==1 && mapa2[blocox][blocoy]=='B' && mapa2[blocox2][blocoy2]=='B'){
		        	porta_trancada=0;}
		        	
		        else{porta_trancada=1;}
		        
		        if (porta_trancada == 0) {
				    mapa2[1][24] = ' ';
				    mapa2[2][24] = ' ';
				} 
				else {
				    mapa2[1][24] = 'P';
				    mapa2[2][24] = 'P';
				}
				
				if (comando == 'w' || comando == 'W') novo_x--;
				if (comando == 's' || comando == 'S') novo_x++;
				if (comando == 'a' || comando == 'A') novo_y--;
				if (comando == 'd' || comando == 'D') novo_y++;
				if (comando == 'q' || comando == 'Q') break;
				
				
				if (andar == 1) {

				    if (novo_x < 0 || novo_x >= LINHAS || novo_y < 0 || novo_y >= COLUNAS - 1) {
				        continue;
				    }
				
				    if (mapa2[novo_x][novo_y] == '#' || (mapa2[novo_x][novo_y] == 'P' && porta_trancada == 1)) {
				        continue;
				    }
				
				    if (andar_pedra == 1 && novo_x == blocox && novo_y == blocoy) {
				
				        movx = blocox + (novo_x - jogador_x);
				        movy = blocoy + (novo_y - jogador_y);
				
				        if (movx < 0 || movx >= LINHAS || movy < 0 || movy >= COLUNAS - 1) {
				            continue;
				        }
				
				        if (mapa2[movx][movy] == '#' || (mapa2[movx][movy] == 'P' && porta_trancada == 1) || (andar_pedra2 == 1 && movx == blocox2 && movy == blocoy2)) {
				            continue;
				        }
				
				        blocox = movx;
				        blocoy = movy;
				
				        jogador_x = novo_x;
				        jogador_y = novo_y;
				    }
				
				    else if (andar_pedra2 == 1 && novo_x == blocox2 && novo_y == blocoy2) {  //evitar colisão
				
				        movx = blocox2 + (novo_x - jogador_x);
				        movy = blocoy2 + (novo_y - jogador_y);
				
				        if (movx < 0 || movx >= LINHAS || movy < 0 || movy >= COLUNAS - 1) {
				            continue;
				        }
				
				        if (mapa2[movx][movy] == '#' || (mapa2[movx][movy] == 'P' && porta_trancada == 1) || (andar_pedra == 1 && movx == blocox && movy == blocoy)) {
				            continue;
				        }
				
				        blocox2 = movx;
				        blocoy2 = movy;
				
				        jogador_x = novo_x;
				        jogador_y = novo_y;
				    }
				
				    else {
				
				        if (mapa2[novo_x][novo_y] == '=') {
				
				            printf("\ndeseja subir? (1-sim/2-nao): ");
				            scanf("%d", &escada);
				
				            if (escada == 1) {
				                andar = 2;
				                jogador_x = 6;
				                jogador_y = 2;
				            }
				
				            continue;
				        }
				
				        jogador_x = novo_x;
				        jogador_y = novo_y;
				    }
				}
				
				if(andar==2){
					
					if (mapa2_2[novo_x][novo_y] != '#') {
						
						if (andar_pedra==2 && novo_x==blocox && novo_y==blocoy){
							
							blocox = novo_x;
            				blocoy = novo_y;
            				
            				movx = blocox + (novo_x - jogador_x);
            				movy = blocoy + (novo_y - jogador_y);
            				
            				if(mapa2_2[movx][movy]){//queda do bloco 
            					if (mapa2_2[movx][movy]==' '){
            						
            						quedax=4;  //printa o bloco na parte de baixo
            						queday=11;
            						
            						blocox = quedax;
							        blocoy = queday;
							        andar_pedra = 1;
            						
            						jogador_x = novo_x;
                        			jogador_y = novo_y;
								}
								
								else if (mapa2_2[movx][movy]!='#' && mapa2_2[movx][movy]!='o'){
									blocox = movx;
							        blocoy = movy;
							
							        jogador_x = novo_x;
							        jogador_y = novo_y;
								}
							}
            				
            				if (mapa2_2[movx][movy] != '#'){//movimento do bloco
            					
            					jogador_x = novo_x;
            					jogador_y = novo_y;
							}
						}
					
					else if(mapa2_2[novo_x][novo_y]=='='){
							printf("\ndeseja descer? (1-sim/2-nao): ");
							scanf("%d", &escada);
					
						if(escada==1){
							andar=1;
							jogador_x = 9;
                    		jogador_y = 4;
							continue;
						}		
					}
					
					if (mapa2_2[novo_x][novo_y] == '-') {
			        jogador_x = novo_x;
			        jogador_y = novo_y;
			    	}
				}
		}
		
		if (andar_pedra == 1 && andar_pedra2 == 1 && mapa2[blocox][blocoy] == 'B' && mapa2[blocox2][blocoy2] == 'B'){
			porta_trancada = 0;}
			
		else{ porta_trancada = 1;}
		
		if (porta_trancada == 0){
			mapa2[1][24] = ' ';
    		mapa2[2][24] = ' ';
		}
		else{
			mapa2[1][24] = 'P';
    		mapa2[2][24] = 'P';
		}
		
		if (mapa2[jogador_x][jogador_y]=='S') {
            	system("cls || clear");
            	printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
            	printf("\n\tAperte [ENTER] para continuar...");
	            _getch(); _getch(); 
            	jogando = 7;
				break;
        	}
				
}
////////////////////////////////////////////////////////lucas///////////////////////////////////////////////////////////////////////////////////////////////////////
	reiniciar_possisao();

	if (jogando == 7) { // Inicia a fase 7 se ela foi selecionada.
		for (i = 0; i < LINHAS; i++) { // Copia o mapa original para o mapa usado na partida.
			for (j = 0; j < COLUNAS; j++) {
				mapa_giratorio[i][j] = mapa_giratorio_base[i][j];
			}
		}
		for (i = 0; i < LINHAS; i++) { // Completa linhas curtas e remove @ do mapa fixo.
			for (j = 0; j < COLUNAS - 1; j++) {
				if (mapa_giratorio[i][j] == '\0') {
					mapa_giratorio[i][j] = ' ';
				} else if (mapa_giratorio[i][j] == '@') {
					mapa_giratorio[i][j] = ' ';
				}
			}
			mapa_giratorio[i][0] = '#';
			mapa_giratorio[i][COLUNAS - 2] = '#';
		}
		for (j = 0; j < COLUNAS - 1; j++) { // Fecha as bordas superior e inferior.
			mapa_giratorio[0][j] = '#';
			mapa_giratorio[LINHAS - 1][j] = '#';
		}
		jogador_giratorio_x = 1; // Posicao inicial: linha 1.
		jogador_giratorio_y = 1;

		while (jogando == 7) { // Continua ate vencer ou sair.
			system("cls || clear");
			printf("\n\nNivel 7: Labirinto Giratorio\n");
			printf("\n\nUse as teclas [W] [A] [S] [D] para se movimentar e [Q] para sair do jogo.\n");

			for (i = 0; i < LINHAS; i++) { // Desenha o mapa e sobrepoe @ ao jogador.
				for (j = 0; j < COLUNAS - 1; j++) {
					if (i == jogador_giratorio_x && j == jogador_giratorio_y) {
						printf("@");
					} else {
						printf("%c", mapa_giratorio[i][j]);
					}
				}
				printf("\n");
			}

			printf("\nProximo passo: ");
			comando = _getch(); // Le uma tecla sem precisar apertar Enter.

			if (comando == 'q' || comando == 'Q') {
				jogando = 0; // Encerra a partida.
				break;
			}

			novo_x = jogador_giratorio_x; // Calcula o destino a partir da posicao atual.
			novo_y = jogador_giratorio_y;
			if (comando == 'w' || comando == 'W') novo_x--; // W sobe; S desce.
			else if (comando == 's' || comando == 'S') novo_x++;
			else if (comando == 'a' || comando == 'A') novo_y--; // A vai a esquerda; D vai a direita.
			else if (comando == 'd' || comando == 'D') novo_y++;

			if (novo_x >= 0 && novo_x < LINHAS && // Impede sair dos limites ou atravessar paredes.
				novo_y >= 0 && novo_y < COLUNAS - 1 &&
				mapa_giratorio[novo_x][novo_y] != '#') {
				jogador_giratorio_x = novo_x; // Confirma o movimento valido.
				jogador_giratorio_y = novo_y;

				if (mapa_giratorio[jogador_giratorio_x][jogador_giratorio_y] == 'S') { // S conclui a fase.
					system("cls || clear");
					printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
					printf("\n\tAperte [ENTER] para continuar...");
					_getch();
					jogando = 8;
					break;
				}
			}

			giro = rand() % 3 + 1; // Sorteia de 1 a 3 giros de 180 graus.
			while (giro > 0) {
				char temp[LINHAS][COLUNAS]; // Guarda temporariamente o mapa transformado.
				for (i = 0; i < LINHAS; i++) {
					for (j = 0; j < COLUNAS - 1; j++) {
						temp[LINHAS - 1 - i][COLUNAS - 2 - j] = mapa_giratorio[i][j]; // Vira linha e coluna.
					}
				}
				for (i = 0; i < LINHAS; i++) { // Copia o mapa virado de volta.
					for (j = 0; j < COLUNAS - 1; j++) {
						mapa_giratorio[i][j] = temp[i][j];
					}
					mapa_giratorio[i][COLUNAS - 1] = '\0';
				}

				novo_x = LINHAS - 1 - jogador_giratorio_x; // Atualiza tambem a posicao do jogador.
				novo_y = COLUNAS - 2 - jogador_giratorio_y;
				jogador_giratorio_x = novo_x;
				jogador_giratorio_y = novo_y;
				giro--; // Diminui um giro do total sorteado.
			}
		}
	}

	reiniciar_possisao();

	if (jogando == 8) { // Inicia a fase 8 se ela foi selecionada.
		for (i = 0; i < LINHAS; i++) { // Preenche casas vazias e remove @ do mapa fixo.
			for (j = 0; j < COLUNAS - 1; j++) {
				if (mapa_invertido[i][j] == '\0') {
					mapa_invertido[i][j] = ' ';
				} else if (mapa_invertido[i][j] == '@') {
					mapa_invertido[i][j] = ' ';
				}
			}
			mapa_invertido[i][0] = '#';
			mapa_invertido[i][COLUNAS - 2] = '#';
		}
		for (j = 0; j < COLUNAS - 1; j++) { // Fecha as bordas superior e inferior.
			mapa_invertido[0][j] = '#';
			mapa_invertido[LINHAS - 1][j] = '#';
		}
		for (i = 1; i < LINHAS - 1; i++) { // Cria paredes verticais entre os corredores.
			for (j = 5; j <= 25; j += 5) {
				mapa_invertido[i][j] = '#';
			}
		}
		mapa_invertido[11][5] = ' '; // Abre passagens alternadas para formar um zigue-zague.
		mapa_invertido[2][10] = ' ';
		mapa_invertido[11][15] = ' ';
		mapa_invertido[2][20] = ' ';
		mapa_invertido[11][25] = ' ';
		mapa_invertido[13][27] = 'S'; // Coloca a saida no fim do ultimo corredor.
		jogador_invertido_x = 1; // Posicao inicial do jogador.
		jogador_invertido_y = 1;
		inverter_comandos = 0;

		while (jogando == 8) { // Continua ate vencer ou sair.
			system("cls || clear");
			printf("\n\nNivel 8: Comandos Invertidos\n");
			printf("\n\nUse as teclas [W] [A] [S] [D] para se movimentar e [Q] para sair do jogo.\n");

			for (i = 0; i < LINHAS; i++) { // Desenha o mapa com @ na posicao do jogador.
				for (j = 0; j < COLUNAS - 1; j++) {
					if (i == jogador_invertido_x && j == jogador_invertido_y) {
						printf("@");
					} else {
						printf("%c", mapa_invertido[i][j]);
					}
				}
				printf("\n");
			}

			printf("\nProximo passo: ");
			comando = _getch(); // Le uma tecla sem esperar Enter.

			if (comando == 'q' || comando == 'Q') {
				jogando = 0; // Encerra o jogo.
				break;
			}

			novo_x = jogador_invertido_x; // Calcula o destino a partir da posicao atual.
			novo_y = jogador_invertido_y;

			if (comando != 'w' && comando != 'W' && // Ignora teclas diferentes de W, A, S e D.
				comando != 'a' && comando != 'A' &&
				comando != 's' && comando != 'S' &&
				comando != 'd' && comando != 'D') {
				continue;
			}

			if (inverter_comandos) { // A cada turno, o comando pode agir ao contrario.
				if (comando == 'w' || comando == 'W') novo_x++; // W/S e A/D trocam de direcao.
				else if (comando == 's' || comando == 'S') novo_x--;
				else if (comando == 'a' || comando == 'A') novo_y++;
				else if (comando == 'd' || comando == 'D') novo_y--;
			} else {
				if (comando == 'w' || comando == 'W') novo_x--;
				else if (comando == 's' || comando == 'S') novo_x++;
				else if (comando == 'a' || comando == 'A') novo_y--;
				else if (comando == 'd' || comando == 'D') novo_y++;
			}

			inverter_comandos = !inverter_comandos; // Alterna o modo para o proximo turno.

			if (novo_x >= 0 && novo_x < LINHAS && // Bloqueia paredes e destinos fora do mapa.
				novo_y >= 0 && novo_y < COLUNAS - 1 &&
				mapa_invertido[novo_x][novo_y] != '#') {
				jogador_invertido_x = novo_x; // Confirma o movimento valido.
				jogador_invertido_y = novo_y;

				if (mapa_invertido[jogador_invertido_x][jogador_invertido_y] == 'S') { // S conclui a fase.
					system("cls || clear");

					printf("\n\n\n\tPARABENS! Voce passou de fase!\n");
					printf("\n\tAperte [ENTER] para continuar...");
					_getch();
					jogando = 9;
					break;
				}
			}
		}
	}

	reiniciar_possisao();

	if (jogando == 9) { // Inicia a fase 9 se ela foi selecionada.
		for (i = 0; i < LINHAS; i++) { // Copia o mapa-base para iniciar uma partida limpa.
			for (j = 0; j < COLUNAS; j++) {
				mapa_fase9[i][j] = mapa_fase9_base[i][j];
			}
			for (j = 0; j < COLUNAS - 1; j++) { // Preenche casas vazias e remove @ do mapa.
				if (mapa_fase9[i][j] == '\0' || mapa_fase9[i][j] == '@') {
					mapa_fase9[i][j] = ' ';
				}
			}
			mapa_fase9[i][0] = '#';
			mapa_fase9[i][COLUNAS - 2] = '#';
		}
		for (j = 0; j < COLUNAS - 1; j++) { // Fecha as bordas superior e inferior.
			mapa_fase9[0][j] = '#';
			mapa_fase9[LINHAS - 1][j] = '#';
		}

		for (i = 2; i <= 12; i += 2) { // Cria barreiras horizontais nas linhas pares.
			for (j = 1; j < COLUNAS - 2; j++) {
				mapa_fase9[i][j] = '#';
			}
		}

		mapa_fase9[2][2] = ' '; // Abre passagens em pontos diferentes do labirinto.
		mapa_fase9[2][24] = ' ';
		mapa_fase9[4][2] = ' ';
		mapa_fase9[4][18] = ' ';
		mapa_fase9[6][6] = ' ';
		mapa_fase9[6][26] = ' ';
		mapa_fase9[8][10] = ' ';
		mapa_fase9[8][24] = ' ';
		mapa_fase9[10][2] = ' ';
		mapa_fase9[10][26] = ' ';
		mapa_fase9[4][2] = 'C'; // Coloca as tres chaves nos corredores.
		mapa_fase9[8][10] = 'C';
		mapa_fase9[12][2] = 'C';
		mapa_fase9[12][26] = 'P'; // A porta P protege a saida S.
		mapa_fase9[12][27] = 'S';
		mapa_fase9[12][28] = '#';
		mapa_fase9[11][27] = '#';
		mapa_fase9[13][27] = '#';
		jogador_fase9_x = 1; // Reinicia o jogador no inicio do mapa.
		jogador_fase9_y = 1;
		chaves_fase9 = 0;

		while (jogando == 9) { // Continua ate vencer ou sair.
			system("cls || clear");
			printf("\n\nNivel 9: O Cofre das Tres Chaves\n");
			printf("\nUse [W] [A] [S] [D] para andar e [Q] para sair.\n");
			printf("Chaves: %d/3\n\n", chaves_fase9);

			for (i = 0; i < LINHAS; i++) { // Desenha o mapa e sobrepoe @ ao jogador.
				for (j = 0; j < COLUNAS - 1; j++) {
					if (i == jogador_fase9_x && j == jogador_fase9_y) {
						printf("@");
					} else {
						printf("%c", mapa_fase9[i][j]);
					}
				}
				printf("\n");
			}

			printf("\nProximo passo: ");
			comando = _getch(); // Le uma tecla sem esperar Enter.

			if (comando == 'q' || comando == 'Q') {
				break;
			}

			novo_x = jogador_fase9_x; // Calcula o destino a partir da posicao atual.
			novo_y = jogador_fase9_y;
			
			if (comando == 'w' || comando == 'W') novo_x--;
			else if  (comando == 's' || comando == 'S') novo_x++;
			else if (comando == 'a' || comando == 'A') novo_y--;
			else if (comando == 'd' || comando == 'D') novo_y++;
			else continue;

			if (novo_x < 0 || novo_x >= LINHAS || // Cancela destinos fora do mapa ou em paredes.
				novo_y < 0 || novo_y >= COLUNAS - 1 ||
				mapa_fase9[novo_x][novo_y] == '#') {
				continue;
			}

			if (mapa_fase9[novo_x][novo_y] == 'P' && chaves_fase9 < 3) { // Porta bloqueada sem as 3 chaves.
				continue;
			}

			jogador_fase9_x = novo_x; // Confirma o movimento permitido.
			jogador_fase9_y = novo_y;

			if (mapa_fase9[jogador_fase9_x][jogador_fase9_y] == 'C') { // Coleta a chave ao pisar nela.
				mapa_fase9[jogador_fase9_x][jogador_fase9_y] = ' ';
				chaves_fase9++;
				if (chaves_fase9 == 3) {
					mapa_fase9[12][26] = ' '; // Abre a porta ao coletar a ultima chave.
				}
			}

			if (mapa_fase9[jogador_fase9_x][jogador_fase9_y] == 'S' && // S so vale depois das tres chaves.
				chaves_fase9 == 3) {
				system("cls || clear");
				printf("\n\n\n\tPARABENS! Voce completou a fase 9!\n");
				printf("\n\tAperte [ENTER] para continuar...");
				_getch();
				jogando = 0;
				break;
			}
		}
	}
		
	reiniciar_possisao();
	    break;
    
    case '2':
    
		system("cls || clear");
    	printf("\n\n\tSelecao de niveis:\n\t[1]Nivel 1: Bem Simple\n\t[2]Nivel 2: Confuso?\n\t[3]Nivel 3: (SSS) Senha Super Secreta\n\t[7]Nivel 7: Labirinto Giratorio\n\t[8]Nivel 8: Comandos Invertidos\n\t[9]Nivel 9: Cofre das Tres Chaves\n\ndigite uma opcao valida: ");
    	scanf("%d", &voce_realmente_le_o_nome_das_variaveis_uau);
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 1) {jogando = 1; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 2) {jogando = 2; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 3) {jogando = 3; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 7) {jogando = 7; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 8) {jogando = 8; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 9) {jogando = 9; jgnd = 1; break;}

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
    	printf("\n\n\n\tCreditos\n\n\tCriadores:\n\n\tJoao Fabio Pires Parra (MootStarling401)\n\n\tArthur da Silva Mota\n\n\tLucas Masaki Sversuti\n");
        printf("\n\tAperte [ENTER] para continuar...");
	    _getch(); _getch(); 
    	break;
    	
	}

	system("cls || clear");
} while (opcao != '4');

    return 0;
}
