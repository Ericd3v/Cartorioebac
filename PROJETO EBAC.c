#include <stdio.h> //biblioteca de comunicação com usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocaçao de texto
#include <string.h> //responsavel pela strings
    
int registro () // função que cadastra o usuario no sistema
{
// inicio criação de variavel
 char arquivo[40];
 char cpf[40];
 char nome[40];
 char sobrenome[40];
 char cargo[40];
 //final da criação variavel
 
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
int consulta() //função de consumo
{
	//inicio das variaveis
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	//fim  das variaveis
	
	printf("Digite o CPF a ser consultado \n"); //entrada de dados do usuario
	scanf("%s",cpf); //leitura de dados do usuario
	
	FILE*file; //apertura de arquivo
	file=fopen(cpf,"r");
	
	if(file==NULL) // estrutura de decisão caso a busca seja nulo 
	{
	 printf("Arquivo não localizado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL )//inicio da estrutura de decisão caso tenha o arquivo buscado 
	{
		printf("\n Essas são as informações do usuario: \n ");
		printf("%s", conteudo);
		printf("\n\n"); //fim da estrutura de decisão 
	
	system("pause"); //pausa no sistema
}
 
int deletar() //inicio função de deletar
{
	//decidindo variaveis 
 char cpf[40]; 
  
  printf("Digite o CPF a ser deletado: \n");//entrada de dado pelo usuario
  scanf("%s", cpf); // saida de dados do usuario
  
  remove(cpf); //função deletar cpf
  FILE*file; //inicio busca de arquivo  
  file=fopen(cpf,"r"); // abertura de arquivo 
   
   if(file == NULL) //estrutura de decisao caso não tenha o arquivo
   {
   	printf("Usuario não se encontra no sistema. \n"); //saide de dados 
   	system("pause"); //pausa no sistems
   }
   if(file =! NULL) //estrutura de decisao caso o arquivo seja encontrado no sistema
   {
  	printf("Usuario deletado do sistema \n"); //saida de dados 
  	system("pause"); //pausa no sistema
   }  
}

int main () // inicio da função
{
  int opcao=0; 
  int x=1; //definindo variaveis
  for(x=1; x=1;)
{
	  system("cls");
	
  setlocale(LC_ALL, "Portuguese");
  
  //inicio da tela do menu 
  printf(">>> Cartório da EBAC <<< \n");
  printf("Escolha a opção desejada do menu: \n");
  printf("\t1 - Registrar nomes.   \n");
  printf("\t2 -Consultar nomes.    \n");
  printf("\t3 - deletar nomes;     \n"); 
  printf("Opção:   ");
  scanf("%d",&opcao);//armazenamento do usuario
         system("cls"); //fim do menu
  
 switch(opcao)// inicio do menu
{
  case 1:
  	registro(); //chamada da função registro 
  break;
  
  case 2:
  consulta(); //chamada da função consultar
  break;
  
  case 3:
  deletar(); //chamada da função deletar
  break;
  
  default: // caso o dado não seja valido
  printf("Essa opção é invalida. \n");
  system("pause");
  break; 	 // fim do menu
  }
}
}
