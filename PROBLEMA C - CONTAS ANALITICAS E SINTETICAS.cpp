/* CURSO DE CIENCIAS DA COMPUTACAO SEGUNDO PERIODO  */
/* ALUNO: RAFAEL PEREIRA DA SILVA                   */
/* DATA DE ENTREGA: 10/12/2018                      */
/* PROBLEMA C - CONTAS ANALITICAS E SINTETICAS 	   	*/
/*
  ENTRADA				SAIDA
  7 
  00000000000001 A		27.00 28.00  
  00000000000011 A 		27.00 28.00  
  00000000000111 A 		16.00 13.00 
  00000000001111 S 12.00 13.00 
  00000000001112 S 4.00 0.00 
  00000000000112 A 		11.00 15.00 
  00000000001121 S 		11.00 15.00 
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main() {

    int i, j, k, z, f, q, s=0, a=0, numeroConta[13], quant_Contas=10000, cont1=0, cont2=0, cont3=0, cont4=0, teste=0, p=0, pos[i], dif, soma1, soma2;
    int contaBancaria[quant_Contas], dig_ContasSint[quant_Contas][13], dig_ContasAnalit[quant_Contas][13], quant_Digitos=13, cond=0, pot, qN, num=0;
    int qTermos1[quant_Digitos], qTermos2[quant_Digitos], vetorNumA[quant_Contas], vetorNumS[quant_Contas], inv, comp;
    float CR_Sint[cont1], DE_Sint[cont1], CR_Analit[cont1], DE_Analit[cont1], CR[quant_Contas], DE[quant_Contas], aux1=0, aux2=0;
    char get_str[13], tipoConta;
    
    setlocale(LC_ALL, "Portuguese");

	do {

		printf (">> Digite a quantidade de contas a serem analisadas: ");
		scanf ("%d", &quant_Contas);
	
		if (quant_Contas <= 0) {
			
			printf ("\n\nInsira uma quantidade de contas validas entre o intervalo [1, 1000]!\n");
			
		}

	} while (quant_Contas <= 0);

	for (i=0; i<quant_Contas; i++) {
		
    	fflush(stdin);
    	
    	printf ("\n");
	
	    printf(">> Entre com os digitos da conta bancaria: ");
	    gets(get_str);
	 
        fflush(stdin);
	
		do {
	
			printf(">> Entre com o tipo da conta bancaria [ANALITICA(A)/SINTETICA(S)]: ");
	   		tipoConta = getchar();
	   		
	   		fflush(stdin);
	   	
		   	if (tipoConta != 'A' && tipoConta != 'S') {
		   		
		   		printf ("\n\nAtenção, insira novamente (em capslock) um tipo de conta válida [A/S]!\n");		
		   		inv=1;
		   		
			}
			
			else {
				
				inv=0;
				
			}
	   	
		} while (inv==1);
		
	   	fflush(stdin);
	   	
	   	if (tipoConta == 'S') {
	   	
			printf ("\nInsira o credito da respectiva conta sintetica: ");
			scanf ("%f", &CR_Sint[cont1]);
		   
			printf ("\nInsira o debito da respectiva conta sintetica: ");
			scanf ("%f", &DE_Sint[cont1]);
		   
			CR[i] = CR_Sint[cont1];	
			DE[i] = DE_Sint[cont1];
		   
			cont1 = cont1 + 1;
		   	
		}
		
		else {
			
			pos[cont2] = i;
			cont2 = cont2 + 1;
			
		}
		
		quant_Digitos=0;
		
	    for (j=0; j < (int) strlen(get_str); j++) {
	
			if (get_str[j] != 48 || cond==1) { 
				
				numeroConta[quant_Digitos] = get_str[j]-48;  
				quant_Digitos = quant_Digitos + 1;
				
				if (quant_Digitos==1) {
					
					cond=1;
					
				}
				
			}
	
		}
		
		qN = quant_Digitos-1;
		num=0;
		
		for (k=0; k<quant_Digitos; k++) {
			
			pot = pow (10, qN-k);
			numeroConta[k] = numeroConta[k]*pot;		
			num = num + numeroConta[k];
			
		}

		contaBancaria[i] = num;
		
		if (tipoConta == 'S') {
			
			qTermos1[cont3] = quant_Digitos; 
			cont3 = cont3 + 1;	
			vetorNumS[s]=num;
			s=s+1;
			
		}
		
		else {
			
			vetorNumA[a]=num;
			a=a+1;
			qTermos2[cont4] = quant_Digitos;
			cont4 = cont4 + 1;
			
		}
	
	}
	
	for (k=0; k<a; k++) {	
		
		soma1 = 0;
		soma2 = 0;
		
		for (z=0; z<s; z++) {
			
			dif = qTermos1[z] - qTermos2[k];
			dif = pow (10, dif);
			comp = vetorNumS[z]/dif;
			
			if (comp==vetorNumA[k]) {
		
				soma1 = soma1 + CR_Sint[z];	
				soma2 = soma2 + DE_Sint[z];
		
			}			
		
		}
		
		CR_Analit[p] = soma1;  
		DE_Analit[p] = soma2;	
		p = p+1;	
	
	}
	
	for (f=0; f<a; f++) {
		
		q = pos[f];
		CR[q] = CR_Analit[f];
		DE[q] = DE_Analit[f];
		
	}
	
	printf ("\n========================================================================================================================\n");
	
	for (f=0; f<quant_Contas; f++) {
		
		printf ("%d\t%.2f\t%.2f\n", contaBancaria[f], CR[f], DE[f]);
		
	}
	
	printf ("\n========================================================================================================================\n");
	
	system ("pause");
    return 0;
    
}
