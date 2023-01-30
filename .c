#include <stdio.h>    //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>   //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel por cuidar das strings.


int include_user()  //fun��o respons�vel por incluir novos usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	// in�cio da cria��o de vari�veis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	//final da cria��o de vari�veis
	
	printf("\tEntendido! Me informe o CPF do aluno ou funcion�rio que deseja incluir em nossa base de dados\n"); //Coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a indicar o tipo de caractere que o computador deve scanear.
	
	strcpy(arquivo, cpf); //Comando para copiar os valores das strings.
	FILE *file;
	file = fopen(arquivo, "w"); // cria o arquivo na pasta que salvamos o sistema "W" significa "Write", ou seja, cria o arquivo.
	fprintf(file, cpf); // salva o valor da v�riavel dentro do arquivo.
	fclose(file); // salva o arquivo.
	
	file = fopen(arquivo, "a"); // "a" significa que voc� est� apenas atualizando o arquivo e n�o criando um novo.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	

	
}

int consult_user()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" l� o arquivo cpf.
	
	if(file == NULL)
		{
		printf("N�o foi poss�vel abrir, o arquivo n�o foi localizado! \n");}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n \n");}
	fclose(file);
	system("pause");
	
	
}

int delet_user()
{	
	char cpf[40];

	setlocale(LC_ALL, "Portuguese");
	printf("\tOk! Me informe o CPF que deseja excluir de nossa base de dados\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){
		printf("\t O CPF digitado n�o se encontra em nossa base de dados! \n");
		system("pause");}
	else (file == cpf);{
		printf("\t CPF exclu�do com suceesso de nossa base de dados! \n");
		system("pause");}
		
	
	system("pause");
	
	}

int main()
{ 	
	int dec_user = 0; //
	int rope = 1;
	
	for (rope=1;rope=1;)
	{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t###### SISTEMA DE CART�RIO VIRTUAL DA EBAC ######\n\n\n");
	printf("\tOl�! Bem-vindo ao Cart�rio Virtual da EBAC!\n\n");
	printf("\n\tPor favor, escolha a op��o desejada no nosso menu");
	printf("\n\n\t\tVoc� deseja: \n\t 1 - Incluir novo aluno");
	printf("\n\t 2 - Consultar alunos cadastrados");
	printf("\n\t 3 - Excluir alunos cadastrados");
	printf("\n\t 4 - Finalizar o sistema\n");
	printf("Op��o:");
	
	scanf("\t%d", &dec_user);
	system("cls"); //respons�vel por limpar a tela.
	
	switch (dec_user){ //decis�o do usu�rio no menu principal
		case 1:
			include_user();
			break;
		
		case 2:
			consult_user();
			break;
		
		case 3:
			delet_user();
			break;
		case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
		default:
			printf("\tOp��o Inv�lida, por gentileza escolha entre as op��es dispon�veis\n");
			system("pause");}
	
	}	
	
}
