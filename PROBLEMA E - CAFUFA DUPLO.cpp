/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA E - CAFUFA DUPLO                        */

/*ENTRADA 		       			SAIDA  
  20 7 5						5 2 3 0 0 0
								1, 2, 3, 4, Cafufa, 6, Cafufa, 8, 9, 
								Cafufa, 11, 12, 13, Cafufa, Cafufa, 16, Cafufa, 
								18, 19, Cafufa. 

*/

#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int n, pn,i, Qnum, num1, num2;
	
	do {
	
		printf (">> Insira um digito para o intervalo entre [1, 1000]: ");
		scanf ("%d", &Qnum);
	
		if (Qnum < 0 || Qnum > 1000) {
		
			printf ("\n> Este digito nao pertence ao intervalo [1, 1000], insira novamente!\n");
			
		}
	
	} while (Qnum < 0 || Qnum > 1000);
	
	do {
	
		printf ("\n>> Insira o primeiro digito do jogo entre [1, 10]: ");
		scanf ("%d", &num1);
	
		if (num1 < 0 || num1 > 10) {
			
			printf ("\n> Insira um numero inteiro no intervalo [1, 10]!\n");
			
		}
	
	} while (num1 < 0 || num1 > 10);
	
	do {
	
		printf ("\n>> Insira o segundo digito do jogo entre [1, 10] e diferente de %d: ", num1);
		scanf ("%d", &num2);
	
		if ((num2 < 0 || num2 > 10) || num1==num2) {
			
			printf ("\n> Insira um numero inteiro diferente no intervalo [1, 10]!\n");
			
		}
	
	} while ((num2 < 0 || num2 > 10) || num1==num2);
	
	printf ("\n");
	
	for (n=1; n<=Qnum; n++) {
	
		if ((n%num1==0 || n%num2==0) || ((pn==num1) || (pn==num2))) {
		
			printf ("  Cafufa  ", n);		
			
		}
		
		else {
			
			printf ("  %d  ", n);
			
		}
		
		if (n%10==0) {
		
			printf ("\n");
		
		}
		
	}
	
	printf ("\b\b.");
	
	return 0;
	
}
