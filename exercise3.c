#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#define MAXNUM 10

main(){
    // Seta o local com lingua em portugu�s
    setlocale(LC_ALL,"portuguese");
    // Vari�veis
    int x, y, vetor[MAXNUM] = {0}, copia[MAXNUM] = {0}, oco[MAXNUM] = {0}, maior = 0, menor = 0, controle;
    float media, desvio, somatoria, auxiliar;
    // Aceita��o dos n�meros
    printf(">> Estatistica <<\n\nEntre com 10 numeros...\n");
    for(x=0; x < MAXNUM; x++){
        printf("Nro. %d:", x+1);
        scanf("%d", &vetor[x]);
    }
    // Calcula e imprime media
    for(x=0; x < MAXNUM; x++){
        media += vetor[x];
    }
    media = media / MAXNUM;
    printf("Media = %f", media);
    // Calcula e imprime desvio padr�o
    for(x=0; x < MAXNUM; x++){
        auxiliar = vetor[x] - media;
        auxiliar = auxiliar * auxiliar;
        somatoria += auxiliar;
    }
    somatoria = somatoria / MAXNUM;
    somatoria = sqrt(somatoria);
    printf("\nDesvio = %f", somatoria);
    // Acha e imprime maior valor do vetor
    maior = vetor[1];
    for(x=0; x < MAXNUM; x++){
        if (vetor[x] > maior){
            maior = vetor[x];
        }
    }
    printf("\nMaior = %d", maior);
    // Acha e imprime menor valor do vetor
    menor = vetor[1];
    for(x=0; x < MAXNUM; x++){
        if (vetor[x] < menor){
            menor = vetor[x];
        }
    }
    printf("\nMenor = %d", menor);
       
   	// Acha n�mero de ocorr�ncias do vetor
	for(x=0; x < MAXNUM; x++){
        for(y=0; y < MAXNUM; y++){
        	if (vetor[x] == vetor[y]){
        		oco[x]++;
			}
        }
	}	
	for(x=0; x < MAXNUM; x++){
		for(y=0; y < MAXNUM; y++){
			controle = 0;
			if (vetor[x] == vetor[y] && x != y){
				controle = 1;
				exit;
			}
		}
		if (controle == 1){
			continue;
		}
		printf("\nValor = %d - Ocorrencias = %d", vetor[x], oco[x]);
	}
	}
