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
	            getchar(); getchar(); 
            	jogando = 7;
				break;
        	}
				
}


    break;
    
    case '2':
    
		system("cls || clear");
    	printf("\n\n\tSelecao de niveis:\n\t[1]Nivel 1: Bem Simple\n\t[2]Nivel 2: Confuso?\n\t[3]Nivel 3: (SSS) Senha Super Secreta\n\ndigite uma opcao valida: ");
    	scanf("%d", &voce_realmente_le_o_nome_das_variaveis_uau);
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 1) {jogando = 1; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 2) {jogando = 2; jgnd = 1; break;}
    	if (voce_realmente_le_o_nome_das_variaveis_uau == 3) {jogando = 3; jgnd = 1; break;}
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
	    getchar(); getchar(); 
    	break;
    	
	}
	system("cls || clear");
} while (opcao != '4');

    return 0;
}
