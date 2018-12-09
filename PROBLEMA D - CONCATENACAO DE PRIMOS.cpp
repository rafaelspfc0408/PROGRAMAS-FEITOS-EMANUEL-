/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA D - CONTATENACAO DE PRIMOS 	            */
/*
  ENTRADA				SAIDA
  8 
  4842					nao 
  213 					sim
  5 					sim	
  0 					nao
  1 					nao
  13235 				sim
  41003					nao

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verdade=0;

int verificarNumero (int n) {
	
	int k = 2, EhPrimo = 1; 
	
	if (n <= 1) 
	
		EhPrimo = 0;
	
	    while (EhPrimo == 1 && k <= n / 2) {
			
			if (n % k  == 0)
			    
				EhPrimo = 0;
				k = k + 1;
		}
	
	if (EhPrimo == 1) {
			
		return 1;
				
	}
		
	else {

		return 0;		
	}

}


void troca(int vetor[], int i, int j) {

	int aux = vetor[i];

	vetor[i] = vetor[j];

	vetor[j] = aux;

}

int permuta(int vetor[], int inf, int sup) {

    int j, num=0, p, teste1, teste2, verd=0, n1, n2, nF1, nF2, t,f=1;

	p = pow (10, sup+1);

	if(inf == sup) {

		for(int i = 0; i <= sup; i++) {

			if (vetor[i] != 0) {
			
				p = p/10;
						
			}
			
			num = num + (vetor[i]*p);
			
			if (i==sup && (num >= 0 && num <= 9)) {
					
				n1 = num;
				
				teste1 = verificarNumero (n1);
				
				n2 = num;
				
				teste2 = verificarNumero (n2);
				
				if (teste1==1 && teste2==1) {

					verd=1;
					nF1= n1;
					nF2= n2;
							
				}
				
			}
			
			
			else if (i==sup && (num >= 10 && num <= 99)) {
					
				n1 = num/10;
				
				teste1 = verificarNumero (n1);
				
				n2 = num-(n1*10);
				
				teste2 = verificarNumero (n2);
				
				if (teste1==1 && teste2==1) {

					verd=1;
					nF1= n1;
					nF2= n2;
							
				}
				
			}
			
			else if (i==sup && (num >= 100 && num <= 999)) {
					
				n1 = num/10;
				
				teste1 = verificarNumero (n1);
				
				n2 = num-(n1*10);
				
				teste2 = verificarNumero (n2);
				
				if (teste1==1 && teste2==1) {

					verd=1;
					nF1= n1;
					nF2= n2;
							
				}
				
			}
			
			else if (i==sup && (num >= 1000 && num <= 9999)) {
				
				n1=num;
				
				for (j=0; j<3; j++) {
				
					n1 = n1/10;	
					teste1 = verificarNumero (n1);
					f=f*10;
					n2= num-(n1*f);
					teste2 = verificarNumero (n2);
					
					if (teste1==1 && teste2==1) {
	
						verd=1;
						nF1= n1;
						nF2= n2;
								
					}
							
				}
									
			}
			
			else if (i==sup && (num >= 10000 && num <= 99999)) {
				
				n1=num;
				
				for (j=0; j<4; j++) {
				
					n1 = n1/10;	
					teste1 = verificarNumero (n1);
					f=f*10;
					n2= num-(n1*f);
					teste2 = verificarNumero (n2);
					
					if (teste1==1 && teste2==1) {
	
						verd=1;
						nF1= n1;
						nF2= n2;
								
					}
							
				}
									
			}
	
	
		}	
	
			
		if (verd==1) {
				
			verdade = 1;
			
		}
	
	}

	else {

		for(int i = inf; i <= sup; i++) {

			troca(vetor, inf, i);

			permuta(vetor, inf + 1, sup);

			troca(vetor, inf, i);
		
		}

	}

}

int main() {

	int N, C, a, b, c, d, e, tam;
	int i, v[tam], vetNum[C], vetConc[C];
	
	printf ("Insira a quantidade de cadeias que deseja concatenar: ");
	scanf ("%d", &C);
	
	printf ("\n");
	
	for (i=0; i<C; i++) {

		verdade=0;
			
		do {
			
			printf ("Digite o numero que voce deseja concatenar: ");
			scanf ("%d", &N);
			
			vetNum[i] = N;
			
			if (N < 0 || N > 99999) {
				
				printf ("\n>> Insira um digito no intervalo entre 0 e 99999!!!\n");
				
			}
			
		} while (N < 0 || N > 99999);
		
		if (N > 0 && N < 10) {
			
			a = N;
			
			tam = 0;
			
		}	
		
		else if (N >= 10 && N <= 99) {
			
			a = N/10;
		
			b = N/10;
			b = N - b*10;
			
			tam = 1;
			
		}	
		
		else if (N >= 100 && N <= 999) {
			
			a = N/100;
			
			b = N/100;
			b = N - b*100;
			b = b/10;
			
			c = N/10;
			c = N - c*10;
			
			tam = 2;
	
		}	
		
		else if (N >= 1000 && N <= 9999) {
			
			a = N/1000;
			
			b = N/1000;
			b = N - b*1000;
			b = b/100;
			
			c = N/100;
			c = N - c*100;
			c = c/10;
			
			d = N/10;
			d = N - d*10; 
		
			tam = 3;
		
		}	
			
		else {
		
			a = N/10000;
			
			b = N/10000;
			b = N - b*10000;
			b = b/1000;
			
			c = N/1000;
			c = N - c*1000;
			c = c/100;
			
			d = N/100;
			d = N - d*100;
			d = d/10;
			 
			e = N/10;
			e = N - e*10;
		
			tam = 4;
			
		}
		
		v[0] = a;
		v[1] = b;
		v[2] = c;
		v[3] = d;
		v[4] = e;
		
		permuta(v, 0, tam);
		
		if (verdade==0) {
				
			vetConc[i] = 0;
					
		}
		
		else {
			
			vetConc[i] = 1;
			
		}
		
	}
	
	printf ("\n\n");
	
	printf ("\n\tCONCATENACOES FORMADAS\n\n");
	
	for (i=0; i<C; i++) {
		
		printf ("%d\t", vetNum[i]);
		
		if (vetConc[i] == 1) {
			
			printf("(SIM) o numero forma uma concatenacao prima\n");
			
		}
		
		else {
		
			printf("(NAO) o numero nao forma uma concatenacao prima\n");
		
		}
		
	}
	
	
	return 0;
}
