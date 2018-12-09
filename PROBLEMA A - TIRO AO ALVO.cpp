/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA A - TIRO AO ALVO					   	*/
/*
  ENTRADA				SAIDA
  3 					24
  2 6 8 				30	
  1 					60
  30 
  4 
  2 3 20 30
  
*/

#include <stdio.h>

int MDC(int *num, int ntermos) {
	
	int i, maior=0, a, j, c;

	for (i=0; i<ntermos; i++) {
	
		if (num[i]>maior) {
	
			maior=num[i];
	
		}
	
	}

	for (i=1; c!=1; i++) {
	
		c=1;
		a=maior*i;
		
		for (j=0; j<ntermos; j++) {
		
			if (a%num[j]) {
		
				c=0;
		
			}
		
		}
	
	}

	return maior*(i-1); 
}

int main () {

	int freq[30], numDeObstaculos, i;
	
	do {
	
		printf ("Digite um numero inteiro de obstaculos que voce deseja de 1 a 50: ");
		scanf ("%d", &numDeObstaculos);
		
		if  (numDeObstaculos <= 0 || numDeObstaculos > 50) {
			
			printf ("\n> Digite uma nova quantidade de obstaculos no intervalo [1, 50]!\n");
			
		}
	
	} while (numDeObstaculos <= 0 || numDeObstaculos > 50);
	
	for (i=0 ; i<numDeObstaculos ; i++) {
		
		do {
		
			printf ("Digite um numero inteiro entre 1 e 30 para a frequencia do obstaculo %d: ", i+1);
			scanf ("%d", &freq[i]);
			
			if (freq[i] < 1 || freq[i] > 30) {
			
				printf ("\n> Digite uma nova frequencia para o obstaculo %d no intervalo [1, 30]!\n", i+1);
				
			}
		
		} while (freq[i] < 1 || freq[i] > 30);
	}	

	printf ("O menor tempo para se passar por todos os obstaculos sao: %d", MDC(freq, numDeObstaculos));
	
}



