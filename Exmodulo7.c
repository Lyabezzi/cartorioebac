#include <stdio.h>  //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

#include <windows.h> //Responsável por declarar todas as funções do windows




int registrar()  //Função responsável por cadastrar usuários
{
      //Início criação de variáveis/string
      char arquivo[40];
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //Fim criação de variáveis/string
      
      printf("Digite o CPF a ser cadastrado: "); //Coletando informação de usuário
      scanf("%s", cpf); //%s refere-se a string
      
      strcpy(arquivo, cpf); // Responsável por copiar os valores das string
      
      FILE *file;  //Cria o arquivo
      file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
      fprintf(file,cpf);  //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a");  //Cria o arquivo
      fprintf(file, ","); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      printf("Digite o nome a ser cadastrado: "); //Coletando informação de usuário
      scanf("%s", nome); //%s refere-se a string
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file,nome); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação de usuário
      scanf("%s", sobrenome); //%s refere-se a string
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file,sobrenome); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      
      printf("Digite o cargo a ser cadastrado: "); //Coletando informação de usuário
	  scanf("%s",cargo); //%s refere-se a string
	
	  file = fopen(arquivo, "a"); //Cria o arquivo
	  fprintf(file,cargo); //Salva o valor da variável
	  fclose(file);	//Fecha o arquivo
	  
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da variável
      fclose(file); //Fecha o arquivo
      system("pause");    
}

int consultar()  //Função responsável por concultar usuários
{
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
      
      //Início criação de variáveis/string
      char cpf[40];
      char conteudo[200];
      //Fim criação de variáveis/string
      
      printf("Digite o CPF a ser consultado: "); //Coletando informação de usuário
      scanf("%s", cpf);  //%s refere-se a string
     
      FILE *file; //Cria o arquivo
      file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
      
      if(file == NULL) //Análise de usuário  inexistente
      {
      printf("Não foi possível abrir o arquivo. \n"); //Coletando informação de usuário
      }
      while(fgets(conteudo, 200 , file) != NULL) //Análise de usuário existente
      
{
      printf("\nEssas são as informações do usuário: "); //Coletando informação de usuário
      printf("%s", conteudo);  //%s refere-se a string
      printf("\n\n"); //Responsável por dar espaço ás opções                 
} 
      system("pause"); //Responsável por pausar o sistema
      
      
}

int deletar()  //Função responsável por deletar usuários
{
      //Início criação de variáveis/string
      char cpf[40];
      //Fim criação de variáveis/string
      
      printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação de usuário
      scanf("%s" ,cpf); //%s refere-se a string
      
      
      FILE *file; //Cria o arquivo
      file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
      
      if(file == NULL)  //Análise de usuário  inexistente
      {
      printf("Usuário não encontrado. \n"); //Coletando informação de usuário
      system("pause"); //Responsável por pausar o sistema
      }
      else if (file != NULL) //Análise de usuário existente
      {
      fclose(file); //Fecha o arquivo
      printf("Usuário deletado. \n"); //Coletando informação de usuário
      system("pause"); //Responsável por pausar o sistema
      remove(cpf); // Remove informações     
      }
}



int main()
{
    int opcao=0;  //Definindo as variáveis
    int x=1;
    
    for (x=1;x=10;x++)
    {
        system("cls");  //Responsável por limpar a tela
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf(" ####  Cartório da EBAC  ####\n\n"); //Início do menu
        printf("Escolha a opção desejada do menu:\n\n"); //Coletando informação de usuário
        printf("\t1- Registrar momes\n\n"); //Coletando informação de usuário
        printf("\t2- Consultar nomes\n\n"); //Coletando informação de usuário
        printf("\t3- Deletar nomes\n\n"); //Coletando informação de usuário
        printf("\t4- Sair do sistema\n\n"); //Coletando informação de usuário
        printf("Opção: "); //Final do menu
  
        scanf("%d" , &opcao); //Armazenando a escolha do usuário
    
        system("cls"); //Responsável por limpar a tela
        
        switch(opcao) //Início da seleção
        {
           case 1:
           registrar(); //Chamada de funções
           break;
         
           case 2:
           consultar(); //Chamada de funções                     
           break;
         
           case 3:
           deletar(); //Chamada de funções 
           break;
           
           case 4: 
           printf("Obrigado por utilizar nosso sistema/n"); //Chamada de funções
           return 0;
           break;
           
           default:
           printf("Opção não disponível\n"); 
           system("pause"); //Responsável por pausar o sistema       
           break;
         
        }
        
        system("pause >nul"); //Pausa o sistema até que o usuário aperte qualquer tecla
    }
}
