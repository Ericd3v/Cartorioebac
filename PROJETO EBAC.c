#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca�ao de texto
#include <string.h> //responsavel pela strings
    
int registro () // fun��o que cadastra o usuario no sistema
{
// inicio cria��o de variavel
 char arquivo[40];
 char cpf[40];
 char nome[40];
 char sobrenome[40];
 char cargo[40];
 //final da cria��o variavel
 
	printf("Digite o CPF a ser cadastrado. \n"); //coletando dados do usuario
	scanf("%s", cpf); //ler os valores do usuarios, %s: refere as strings 
	strcpy(arquivo,cpf); //reponsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //'w' significa criar uma nova e escrever
	fprintf(file,cpf);//salva o valor
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo 
	fprintf(file,", "); // separa os dados
	fclose(file); // fechar o arquivo 
	
	printf("Digite o nome a ser cadastrado: \n"); // entrada de dados do usuario
	scanf("%s", nome); //ler os valores do usuario.
	
	file= fopen(arquivo , "a"); //abrir e procurar o arquivo.
	
	fprintf(file,nome); //procura do arquivo no banco de dados
	
	fclose(file); //fechar o banco de dados
	
	file = fopen(arquivo,"a");
	
	fprintf(file,", ");
	
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado. \n"); //entrada de dados pelo usuario
	scanf("%s", sobrenome); //leitura dos dados
	
	file = fopen(arquivo,"a"); //abertura e procura no banco de dados
	
	fprintf(file, sobrenome);
	
	fclose(file);
	
	file - fopen(arquivo,"a");
	
	fprintf(file, ", ");
	
	fclose(file); //fechamentodo arquivo
	
	printf("Digite o cargo. \n"); //entrada de dados pelo usuario
	scanf("%s",cargo);//leitura de dados do usuario
	
	file = fopen(arquivo,"a"); //abertura de arquivo no banco de dados
	fprintf(file, cargo);
	fclose(file); // fechamento do arquivo
	
	system("pause"); // pausa no sistema 
	
}


int consulta() //fun��o de consulto
{
	//inicio das variaveis
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	//fim  das variaveis
	
	printf("Digite o CPF a ser consultado \n"); //entrada de dados do usuario
	scanf("%s",cpf); //leitura de dados do usuario
	
	FILE *file; //apertura de arquivo
	file = fopen(cpf,"r");
	
	if(file==NULL) // estrutura de decis�o caso a busca seja nulo 
	{
		
	 printf("Arquivo n�o localizado.\n");
	 system("pause");
	 
	}
	while(fgets(conteudo, 200, file) != NULL )//inicio da estrutura de decis�o caso tenha o arquivo buscado 
{
		printf("\n Essas s�o as informa��es do usuario: \n ");
		printf("%s", conteudo);
		printf("\n\n"); //fim da estrutura de decis�o 
	
	system("pause"); //pausa no sistema
}
}
 
int deletar() //inicio fun��o de deletar
{
  
  setlocale(LC_ALL, "Portuguese");//definindo a linguagem
		 
  char cpf[40]; //decidindo variaveis
  
  printf("Digite o CPF a ser deletado: \n");//entrada de dado pelo usuario
  scanf("%s", cpf); // saida de dados do usuario
  
  remove(cpf); //fun��o deletar cpf
  
  FILE*file; //inicio busca de arquivo  
  file=fopen(cpf,"r"); // abertura de arquivo 
   
    if(file == NULL) //estrutura de decisao caso n�o tenha o arquivo
{
   	
   	printf("Usuario n�o se encontra no sistema. \n"); //saide de dados 
   	system("pause"); //pausa no sistems
   
}
   
  
     
}

int main () // inicio da fun��o
{
  
  int opcao=0; //definindo variaveis
  int x=1; 
  char senhadigitada[10]= "a";
  int comparacao; 
  
  printf("### CART�RIO EBAC ### \n\n");
  
  printf("Login de administrador\n\n Digite sua senha:");

  scanf("%s",senhadigitada);
  
  comparacao = strcmp(senhadigitada,"admin");

  
  if(comparacao == 0)
{
  system("cls");
	
  	for(x=1; x=1;)
{

	
   setlocale(LC_ALL, "Portuguese");
  
  //inicio da tela do menu 
   printf("\n\n >>> Cart�rio da EBAC <<< \n\n\n");
   printf("Escolha a op��o desejada do menu: \n\n");
   printf("\t1 - Registrar nomes.  \n\n");
   printf("\t2 -Consultar nomes.    \n\n");
   printf("\t3 - deletar nomes.     \n\n"); 
   printf("\t4 - Sair. \n\n");
   printf("Op��o:   ");
  
   scanf("%d", &opcao);//armazenamento do usuario
         system("cls"); //fim do menu
  
   switch(opcao) // inicio do menu 
{
   case 1:
   registro(); //chamada da fun��o registro 
   break;
  
   case 2:
   consulta(); //chamada da fun��o consultar
   break;
  
   case 3:
   deletar(); //chamada da fun��o deletar
   break;
  
   case 4: //sair do sistema 
   printf(" Obrigado por usar o Sistema!  \n");
   return 0;
   break;

   default: // caso o dado n�o seja valido
   printf("Essa op��o � invalida. \n");
   system("pause");
   break; 	 // fim do menu
}
}
}

else
  printf("Senha incorreta!");
}
