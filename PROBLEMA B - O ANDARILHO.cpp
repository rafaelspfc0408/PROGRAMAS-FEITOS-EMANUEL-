/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA B - O ANDARILHO   					   	*/
/*
  ENTRADA				SAIDA
  3 					12
  10 2 4 5 				5	
  2 					20
  5 5 5 
  4 
  10 5 10 5 10 0
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	
	int i, j, k, pontoAleatorio, desvio, direcao[100], distancia[100], num=0, maiorDistancia=0, esq=0;
	
	do {
	
		printf (">> Digite a quantidade de desvios: ");
		scanf ("%d", &desvio);
		
		if (desvio < 0) {
			
			printf ("\nInsira novamente uma quantidade de desvios positiva!\n");
			
		}

	} while (desvio < 0);
	
	desvio = desvio+1;
	
	printf ("\n");
	
	srand((unsigned)time(NULL));
	
	pontoAleatorio = (rand()) % 10;
	
	if (pontoAleatorio%2==0) {
		
		esq=1;
		
	}
	
	for (i=0; i<desvio; i++) {
	
		if (esq==1) {
	
			printf (">> Digite a quantidade de passos para esquerda: ");
			esq=0;
		
		}
		
		else {
		
			printf (">> Digite a quantidade de passos para direita: ");
			esq=1;
		
		}
		
		scanf ("%d", &direcao[i]);
	
	}
	
	desvio = desvio-1;

	for (j=0; j<desvio; j++) {
		
		if (j==0) {
			
			num = direcao[j] - direcao[j+1]; 
			
		}
	
		else if (j%2!=0) {
			
			num = num + direcao[j+1]; 
		
		}
		
		else {
			
			num = num - direcao[j+1];
			
		}
		
		if (num<0) {
			
			num = num*(-1);
			
		}
		
		distancia[j] = num;
		
	}
	
	printf ("\n\n");
	
	for (k=0; k<desvio; k++) {

		if (maiorDistancia <= distancia[k]) {
		
			maiorDistancia = distancia[k];
		
		}
		
	}
	
	printf ("\n\n> A maior distancia ao ponto de origem eh: %d", maiorDistancia);
	
}
