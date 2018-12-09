/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA F - PARTIDAS DE TENIS DE MESA			*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
	
int main () {
	
	int i, j, k, w, P, quantP, gA, gB; 
	int X[P], O[P], A[P][j], B[P][j], T1[P], T2[P];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf ("Insira a quantidade de partidas: ");
	scanf ("%d", &P);
	
	for (i=0 ; i<P; i++) {
				
		printf ("\nInsira o número de sets ganho pelo jogador A na %dª partida: ", i+1);
		scanf ("%d", &X[i]);
		
		printf ("\nInsira o número de sets ganho pelo jogador B na %dª partida: ", i+1);
		scanf ("%d", &O[i]);
		
		quantP = X[i]+O[i];
		
		for (j=0; j<quantP; j++) {
			
			printf ("\n\n>> ATENCAO INSIRA \"-1\" PARA O PLACAR NAO ANOTADO <<\n");
	
			printf ("\nInsira a pontuação do jogador A no %dº set disputado: ", j+1);
			scanf ("%d", &A[i][j]);				
		
			printf ("\nInsira a pontuação do jogador B no %dº set disputado: ", j+1);
			scanf ("%d", &B[i][j]);				
			
		}
	
	}
	
	gA = 0;
	gB = 0;
		
	for (k=0; k<P; k++) {
		
		for (w=0; w<quantP; w++) {
						
			if ((A[k][w]!=-1) && (B[k][w]==-1)) {
			
				if ((gA < X[k])) {
					
					B[k][w] = A[k][w] - 2; 
					gA =+ 1;  
				
				}
				
				else if ((gB < O[k])) {
					
					B[k][w] = A[k][w] + 2; 
					gB =+ 1;
				
				}
			
			}
			
			else if ((A[k][w]==-1) && (B[k][w]!=-1)) {
			
				if ((gA < X[k])) {
					
					A[k][w] = B[k][w] + 2; 
					gA =+ 1;  
				
				}
				
				else if ((gB < O[k])) {
					
					A[k][w] = B[k][w] - 2; ; 
					gB =+ 1;
				
				}
				 
			}
			
			else if ((A[k][w]==-1) && (B[k][w]==-1)) {
			
				if ((gA < X[k])) {
					
					A[k][w] = 10;
					B[k][w] = 0; 
					
					gA =+ 1;  
				
				}
				
				else if ((gB < O[k])) {
					
					B[k][w] = 10+2; 
					A[k][w] = 10;
						
					gB =+ 1;
				
				}
				 
			}	
			
			T1[k] = T1[k] + A[k][w];  
			T2[k] = T2[k] + B[k][w];
			
		}
		
	}
	
	printf ("\n\n");
	
	for (i=0 ; i<P; i++) {
		
		printf ("\nPARTIDA %d:\n", i+1);
		
		quantP = X[i]+O[i];
		
		for (j=0; j<quantP; j++) {
			
			printf ("SET %d\t [ %d ¦ %d ]\n", j+1, A[i][j], B[i][j]);
		
		}
		
	}
	
	for (i=0 ; i<P; i++) {
		
		printf ("\nO Total de pontos na partida %d: jogador A[%d] X jogador B[%d]", i+1, T1[i], T2[i]);		
	
	}
}

