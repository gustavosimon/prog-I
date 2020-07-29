//Nome:Gustavo André Simon
//Professor: Prof. Me. Daniel Bauermann
//Disciplina:Programação I
//Trabalho IV alocação dinâmica, funções e arquivos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Calcula a media dos valores dos vetores
float mediaValores(float *vetor1, float *vetor2, int x, int y){
	int i = 0, j = 0, notas;
	float soma, media;
// Percorre vetor do primeiro arquivo
	for(i=0; i < x; i++){
		soma += vetor1[i];
	}
// Percorre vetor do segundo arquivo
	for(j=0; j < y; j++){
		soma += vetor2[j];
	}
	notas = x + y;
	media = soma / notas;
	return media;
}
// Calcula o desvio padrão dos valores dos vetores
float desvioPadrao(float *vetor1, float *vetor2, int x, int y, float media_valores){
	int i = 0, j = 0;
	float auxiliar = 0, somatoria = 0, auxiliar2 = 0, somatoria2 = 0;
// Calcula desvio padrão
	for(i=0; i < x; i++){
        auxiliar = vetor1[i] - media_valores;
        auxiliar = auxiliar * auxiliar;
        somatoria += auxiliar;
	}
// Percorre vetor do segundo arquivo
	for(j=0; j < y; j++){
        auxiliar2 = vetor2[j] - media_valores;
        auxiliar2 = auxiliar2 * auxiliar2;
        somatoria2 += auxiliar2;
	}
	somatoria += somatoria2;
    somatoria = somatoria / ((x + y) - 1);
    somatoria = sqrt(somatoria);
    return somatoria;
}
int main() {
// Variáveis de uso do programa
   char arq1[20], arq2[20], arq3[20], arq4[20];
   float *vetor1, *vetor2, media_valores, desvio_padrao;
   int x, y, i, j=0;
// Declara os arquivos
   FILE* arquivo1;
   FILE* arquivo2;
   FILE* arquivo3;
   FILE* arquivo4;
// Se não conseguiu alocar memória
   if (!(vetor1=malloc(sizeof(float)))) {
      printf("Erro na alocacao de memoria!\n");
      return -1;
   }
// Se não conseguiu alocar memória
   if (!(vetor2=malloc(sizeof(float)))) {
      printf("Erro na alocacao de memoria!\n");
      return -1;
   }
// Imprime o cabeçalho
   printf(">> Trabalho 4 - GUSTAVO ANDRÉ SIMON <<\n");
// Recebe o nome do arquivo 1   
   printf("Nome do arquivo de entrada 1:");
   scanf("%s", &arq1);
// Recebe o nome do arquivo 2   
   printf("Nome do arquivo de entrada 2:");
   scanf("%s", &arq2);
// Recebe o nome do arquivo agrupado   
   printf("\nNome do arquivo agrupado:");
   scanf("%s", &arq3);
// Recebe o nome do arquivo de resultados   
   printf("Nome do arquivo resultado:");
   scanf("%s", &arq4);
// Abertura dos arquivos em modo leitura          
   arquivo1=fopen(arq1, "rt");
   if (arquivo1 == NULL)
      {printf("Problemas na ABERTURA do arquivo\n");
       return -1;}
   arquivo2=fopen(arq2, "rt");
   if (arquivo2 == NULL)
      {printf("Problemas na ABERTURA do arquivo\n");
      return -1;}
//Leitura do arquivo 1   
   x=0;
   printf("\nLendo arquivo de entrada 1 ...");
   while((fscanf(arquivo1,"%f\n", &vetor1[x]))!=EOF){
   	    vetor1 = realloc(vetor1, sizeof(float));
		x++;
   }
//Leitura do arquivo 2   
   y=0;
   printf("\nLendo arquivo de entrada 2 ...");
   while((fscanf(arquivo2,"%f\n", &vetor2[y]))!=EOF){
   	    vetor2 = realloc(vetor2, sizeof(float));	
		y++;
   }
   printf("\nProcessando dados ... ok!"); 
// Busca media dos valores dos vetores     
   media_valores = mediaValores(vetor1, vetor2, x, y);
// Busca desvio padrão
   desvio_padrao = desvioPadrao(vetor1, vetor2, x, y, media_valores);
   printf("\nGravando arquivo agrupado ..."); 
// Cria e abre o arquivo agrupado em modo de escrita (arquivo 3)
   arquivo3=fopen(arq3,"w");
   if (arquivo3 == NULL)
      {printf("Problemas na CRIAÇÃO do arquivo\n");
      return -1;}
// Escreve arquivo agrupado   
   for(i=0; i < x; i++){
   	  fprintf(arquivo3,"%.2f\n",vetor1[i]);
   } 
   for(j=0; j < y; j++){
   	  fprintf(arquivo3,"%.2f\n",vetor2[j]);
   }
   printf("\nGravando arquivo com resultado ...");  
// Cria e abre o arquivo agrupado em modo de escrita (arquivo 3)
   arquivo4=fopen(arq4,"w");
   if (arquivo4 == NULL)
      {printf("Problemas na CRIAÇÃO do arquivo\n");
      return -1;}
// Grava as informações no arquivo de resultado
   fprintf(arquivo4,"Quantidade de valores lidos: %d\n", x+y);
   fprintf(arquivo4,"Quantidade arquivo 1: %d\n", x);
   fprintf(arquivo4,"Quantidade arquivo 2: %d\n\n", y);
   fprintf(arquivo4,"Média dos valores: %f\n", media_valores);
   fprintf(arquivo4,"Desvio padrao: %f\n", desvio_padrao);
   printf("\nFim da execução!");  
// Fecha os arquivos abertos pelo programa
   fclose(arquivo1);
   fclose(arquivo2);
   fclose(arquivo3);
// Sucesso
   return 0;   
};
