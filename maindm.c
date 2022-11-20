#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int movimentacao(char tab[8][8], int li, int ci, int lf, int cf, int v){
	if(tab[li][ci] == 2 && v == 0){ //Movimentacao da peca branca
		if(tab[lf][cf] == 32){ 
			if(li == lf + 1 && ci == cf + 1){
				return 1;
			}else if(li == lf + 1 && ci == cf - 1){
				return 1;
			}else if(tab[lf - 1][cf + 1] == 1 && li == lf - 2 && ci == cf + 2){
				return 5;
			}else if(tab[lf - 1][cf - 1] == 1 && li == lf - 2 && ci == cf - 2){
				return 6;
			}else if(tab[lf + 1][cf - 1] == 1 && li == lf + 2 && ci == cf - 2){
				return 7;
			}else if(tab[lf + 1][cf + 1] == 1 && li == lf + 2 && ci == cf + 2){
				return 8;
			}
		}else{
			return 20;
		}
	}else if(tab[li][ci] == 2 && v == 1){ //Movimentacao da peca do adversario
		return 3;
	}else if(tab[li][ci] == 1 && v == 1){ //Movimentacao da peca preta
		if(tab[lf][cf] == 32){
			if(li == lf - 1 && ci == cf + 1){
				return 2;
			}else if(li == lf - 1 && ci == cf - 1){
				return 2;
			}else if(tab[lf - 1][cf + 1] == 2 && li == lf - 2 && ci == cf + 2){
				return 9;
			}else if(tab[lf - 1][cf - 1] == 2 && li == lf - 2 && ci == cf - 2){
				return 10;
			}else if(tab[lf + 1][cf - 1] == 2 && li == lf + 2 && ci == cf - 2){
				return 11;
			}else if(tab[lf + 1][cf + 1] == 2 && li == lf + 2 && ci == cf + 2){
				return 12;
			}
		}else{
			return 20;
		}
	}else if(tab[li][ci] == 1 && v == 0){ //Movimentacao da peca do adversario
		return 4;
	}
}

int vitoria(char tab[8][8]){ //Verificar se um jogador ficou sem pecas
	int contb = 0;
	int contp = 0;
	int x, z;
	
	for(x = 0; x < 8; x++){
		for(z = 0; z < 8; z++){
			if(tab[x][z] == 1){
				contp++;
			}else if(tab[x][z] == 2){
				contb++;
			}
		}
	}
	if(contp == 0){ //Jogador das pecas pretas ficou sem pecas
		return 1;
	}else if(contb == 0){ //Jogador das pecas brancas ficou sem pecas
		return 2;
	}else{
		return 0;
	}
}

int main(int argc, char *argv[]) {
	
	char tab[8][8];
	char jogbra[10];
	char jogpre[10];
	int rslt = 0;
	int vez = 2;
	int con = 0;
	int i, j, li, ci, lf, cf, x, v;
   
	tab[0][0] = 1;     tab[0][1] = 254;   tab[0][2] = 1;     tab[0][3] = 254;   tab[0][4] = 1;     tab[0][5] = 254;   tab[0][6] = 1;     tab[0][7] = 254; 
	tab[1][0] = 254;   tab[1][1] = 1;     tab[1][2] = 254;   tab[1][3] = 1;     tab[1][4] = 254;   tab[1][5] = 1;     tab[1][6] = 254;   tab[1][7] = 1; 
	tab[2][0] = 1;     tab[2][1] = 254;   tab[2][2] = 1;     tab[2][3] = 254;   tab[2][4] = 1;     tab[2][5] = 254;   tab[2][6] = 1;     tab[2][7] = 254; 
	tab[3][0] = 254;   tab[3][1] = 32;    tab[3][2] = 254;   tab[3][3] = 32;    tab[3][4] = 254;   tab[3][5] = 32;    tab[3][6] = 254;   tab[3][7] = 32;  
	tab[4][0] = 32;    tab[4][1] = 254;   tab[4][2] = 32;    tab[4][3] = 254;   tab[4][4] = 32;    tab[4][5] = 254;   tab[4][6] = 32;    tab[4][7] = 254;
	tab[5][0] = 254;   tab[5][1] = 2;     tab[5][2] = 254;   tab[5][3] = 2;     tab[5][4] = 254;   tab[5][5] = 2;     tab[5][6] = 254;   tab[5][7] = 2;
	tab[6][0] = 2;     tab[6][1] = 254;   tab[6][2] = 2;     tab[6][3] = 254;   tab[6][4] = 2;     tab[6][5] = 254;   tab[6][6] = 2;     tab[6][7] = 254;
	tab[7][0] = 254;   tab[7][1] = 2;     tab[7][2] = 254;   tab[7][3] = 2;     tab[7][4] = 254;   tab[7][5] = 2;     tab[7][6] = 254;   tab[7][7] = 2; 
  
	int opcao;
	
	while(opcao != 3){ //Para o menu finalizar so com a escola do 3(sair)
	
		printf("\n\t__________________________________________________________\n");
	    printf("\t__________________________________________________________\n");
	    printf("\t__________________________________________________________\n");
	    printf("\t__________________                    ____________________\n");
	    printf("\t__________________                    ____________________\n");
	    printf("\t__________________   JOGO  DA  DAMA   ____________________\n");
	    printf("\t__________________                    ____________________\n");
	    printf("\t__________________________________________________________\n");
	    printf("\t__________________________________________________________\n");
	    printf("\t__________________________________________________________\n\n\n");
	    printf("\t\t\t\t1. Jogar \n\t\t\t\t2. Ajuda \n\t\t\t\t3. Sair\n\n");
	    printf("\t\t\t   Escolha uma opcao: ");
	    scanf("%d", &opcao);
	
	    system("cls");
	    
	    switch(opcao){
	    	case 1:{ //Inicio do jogo
	    		printf("\n\n\t\t\tDigite o nome do jogador das pecas brancas: ");
	    		scanf("%s", jogbra);
	    		printf("\n\n\t\t\tDigite o nome do jogador das pecas pretas: ");
	    		scanf("%s", jogpre);
	    		system("cls");
	    		
	    		while(rslt == 0){
	    			v = vez % 2; //Para definir o turno
	    			if(v == 0){
	    				printf("\n\t\t\tVEZ DAS PECAS BRANCAS");
	    			}else if(v == 1){
	    				printf("\n\t\t\tVEZ DAS PECAS PRETAS");
					}
	    			printf("\n\n\t\t\t  1 2 3 4 5 6 7 8\n"); //Impressao do tabuleiro
	    			for(i = 0; i < 8; i++){
	    				printf("\t\t\t%d ", i + 1);
	    				for(j = 0; j < 8; j++){
	    					printf("%c ", tab[i][j]);
						}
						printf("\n");
					}
					printf("\n\t\t\tDigite a linha da peca: ");
					scanf("%d", &li);
					li--;
					printf("\n\t\t\tDigite a coluna da peca: ");
					scanf("%d", &ci);
					ci--;
					printf("\n\t\t\tDigite a linha que deseja movimenta-la: ");
					scanf("%d", &lf);
					lf--;
					printf("\n\t\t\tDigite a coluna que deseja movimenta-la: ");
					scanf("%d", &cf);
					cf--;
					
					system("cls");
					
					con = movimentacao(tab, li, ci, lf, cf, v);

					switch(con){
						case 1:{
							tab[li][ci] = 32;
							tab[lf][cf] = 2;
							vez++;
							
							rslt = vitoria(tab);
							
							break;
						}
						case 2:{
							tab[li][ci] = 32;
							tab[lf][cf] = 1;
							vez++;
							
							rslt = vitoria(tab);
							
							break;
						}
						case 3:{
							printf("\n\t\t\tE a vez das pecas pretas!!!\n");
							break;
						}
						case 4:{
							printf("\n\t\t\tE a vez das pecas brancas!!!\n");
							break;
						}
						case 5:{
							tab[li][ci] = 32;
							tab[lf - 1][cf + 1] = 32;
							tab[lf][cf] = 2;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 6:{
							tab[li][ci] = 32;
							tab[lf - 1][cf - 1] = 32;
							tab[lf][cf] = 2;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 7:{
							tab[li][ci] = 32;
							tab[lf + 1][cf - 1] = 32;
							tab[lf][cf] = 2;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 8:{
							tab[li][ci] = 32;
							tab[lf + 1][cf + 1] = 32;
							tab[lf][cf] = 2;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 9:{
							tab[li][ci] = 32;
							tab[lf - 1][cf + 1] = 32;
							tab[lf][cf] = 1;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 10:{
							tab[li][ci] = 32;
							tab[lf - 1][cf - 1] = 32;
							tab[lf][cf] = 1;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 11:{
							tab[li][ci] = 32;
							tab[lf + 1][cf - 1] = 32;
							tab[lf][cf] = 1;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 12:{
							tab[li][ci] = 32;
							tab[lf + 1][cf + 1] = 32;
							tab[lf][cf] = 1;
							
							rslt = vitoria(tab);
							
							vez++;
							break;
						}
						case 20:{
							printf("\n\t\t\tMovimento invalido!!!");
							break;
						}
					}
				}
				if(rslt == 1){
					printf("Vitoria de %s", jogbra);
				}else if(rslt == 2){
					printf("Vitoria de %s", jogpre);
				}
				break;
			}
			case 2:{ //Informacoes do jogo
				system("cls");
				printf("\n\t\t\t\t----------------O QUE E?----------------");
				printf("\n\t\t\tDamas e um jogo no qual o objetivo e comer todas as pecas do adversario.");
				printf("\n\t\t\t\t-----------------REGRAS-----------------");
				printf("\n\t\t\tAs pecas so podem seguir em diagonal para frente, uma casa por vez\n\t\t\tPara comer outra peca pode se mover para qualquer direcao. \n\t\t\tO jogo acaba quando um jogador fica sem pecas\n\n");
				system("pause");
				system("cls");
				break;
			}
			case 3:{ //Finalizar o programa
				printf("\n\t\t\tFIM DE JOGO\n");
				break;
			}
		}
	}
	return 0;
}
