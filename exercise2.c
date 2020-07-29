#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OCO 10


main(){
// Variáveis
	char materia[20];
	int i;
	float media_total;
	char str1[]="Complementar";
    char str2[]="Aprovado";
// Estrutura dos alunos
	struct cadastro{
		int matricula;	
		char nome[20];
		float nota1;
		float nota2;
		float nota3;
		float media;
		char situacao[20];
	};
	struct cadastro alunos[OCO];
// Inicio da rotina	
	printf(">> Calculo de Notas <<");
	printf("\n\nInforme o nome da turma:");
	gets(materia);
	printf("\nInforme os dados solicitados dos alunos (digite -1 na matrícula para sair)...");
// Aceita os dados	
	for (i=0; i<OCO; i++){		
	  	printf("\n\nMatrícula: ", (i+1));
  		scanf("%d", &alunos[i].matricula);
// Se o código de matrícula for -1		
		if(alunos[i].matricula == -1){
  			break;
		}
		fflush(stdin);
  		printf("\nNome: ");
  		gets(alunos[i].nome);
  		printf("\nNota 1: ");
  		scanf("%f", &alunos[i].nota1);
  		printf("\nNota 2: ");
  		scanf("%f", &alunos[i].nota2);
  		printf("\nNota 3: ");
  		scanf("%f", &alunos[i].nota3);
		alunos[i].media = alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3;
		alunos[i].media = alunos[i].media / 3;
		media_total += alunos[i].media;
// Se o aluno tiver nota menor que 7, está em avaliação complementar		
		if (alunos[i].media < 7){
			strcpy (alunos[i].situacao,str1);
		} else {
			strcpy (alunos[i].situacao,str2);
		} 
	}
// Lista os alunos
	printf("\n\nListagem...\nMatricula | Nome | Nota 1 | Nota 2 | Nota 3 | Media | Situacao");		 
	for (i=0; i<OCO; i++){		
  		if(alunos[i].matricula == -1){
  			break;
		}
	  	printf("\n  %d  |  %s  | %.1f | %.1f | %.1f | %.1f | %s ", alunos[i].matricula, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].media, alunos[i].situacao);
	}
// Calcula media total da turma
	media_total = media_total / i;
	printf("\nMedia Turma %s : %.2f\n\n", materia, media_total);
	system("pause");		
}
