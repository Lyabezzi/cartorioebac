#include <stdio.h>  //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

#include <windows.h> //Respons�vel por declarar todas as fun��es do windows




int registrar()  //Fun��o respons�vel por cadastrar usu�rios
{
      //In�cio cria��o de vari�veis/string
      char arquivo[40];
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //Fim cria��o de vari�veis/string
      
      printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o de usu�rio
      scanf("%s", cpf); //%s refere-se a string
      
      strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
      
      FILE *file;  //Cria o arquivo
      file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
      fprintf(file,cpf);  //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a");  //Cria o arquivo
      fprintf(file, ","); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      printf("Digite o nome a ser cadastrado: "); //Coletando informa��o de usu�rio
      scanf("%s", nome); //%s refere-se a string
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file,nome); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o de usu�rio
      scanf("%s", sobrenome); //%s refere-se a string
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file,sobrenome); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      
      printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o de usu�rio
	  scanf("%s",cargo); //%s refere-se a string
	
	  file = fopen(arquivo, "a"); //Cria o arquivo
	  fprintf(file,cargo); //Salva o valor da vari�vel
	  fclose(file);	//Fecha o arquivo
	  
      file = fopen(arquivo, "a"); //Cria o arquivo
      fprintf(file, ","); //Salva o valor da vari�vel
      fclose(file); //Fecha o arquivo
      system("pause");    
}

int consultar()  //Fun��o respons�vel por concultar usu�rios
{
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
      
      //In�cio cria��o de vari�veis/string
      char cpf[40];
      char conteudo[200];
      //Fim cria��o de vari�veis/string
      
      printf("Digite o CPF a ser consultado: "); //Coletando informa��o de usu�rio
      scanf("%s", cpf);  //%s refere-se a string
     
      FILE *file; //Cria o arquivo
      file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
      
      if(file == NULL) //An�lise de usu�rio  inexistente
      {
      printf("N�o foi poss�vel abrir o arquivo. \n"); //Coletando informa��o de usu�rio
      }
      while(fgets(conteudo, 200 , file) != NULL) //An�lise de usu�rio existente
      
{
      printf("\nEssas s�o as informa��es do usu�rio: "); //Coletando informa��o de usu�rio
      printf("%s", conteudo);  //%s refere-se a string
      printf("\n\n"); //Respons�vel por dar espa�o �s op��es                 
} 
      system("pause"); //Respons�vel por pausar o sistema
      
      
}

int deletar()  //Fun��o respons�vel por deletar usu�rios
{
      //In�cio cria��o de vari�veis/string
      char cpf[40];
      //Fim cria��o de vari�veis/string
      
      printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o de usu�rio
      scanf("%s" ,cpf); //%s refere-se a string
      
      
      FILE *file; //Cria o arquivo
      file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
      
      if(file == NULL)  //An�lise de usu�rio  inexistente
      {
      printf("Usu�rio n�o encontrado. \n"); //Coletando informa��o de usu�rio
      system("pause"); //Respons�vel por pausar o sistema
      }
      else if (file != NULL) //An�lise de usu�rio existente
      {
      fclose(file); //Fecha o arquivo
      printf("Usu�rio deletado. \n"); //Coletando informa��o de usu�rio
      system("pause"); //Respons�vel por pausar o sistema
      remove(cpf); // Remove informa��es     
      }
}



int main()
{
    int opcao=0;  //Definindo as vari�veis
    int x=1;
    
    for (x=1;x=10;x++)
    {
        system("cls");  //Respons�vel por limpar a tela
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf(" ####  Cart�rio da EBAC  ####\n\n"); //In�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n"); //Coletando informa��o de usu�rio
        printf("\t1- Registrar momes\n\n"); //Coletando informa��o de usu�rio
        printf("\t2- Consultar nomes\n\n"); //Coletando informa��o de usu�rio
        printf("\t3- Deletar nomes\n\n"); //Coletando informa��o de usu�rio
        printf("\t4- Sair do sistema\n\n"); //Coletando informa��o de usu�rio
        printf("Op��o: "); //Final do menu
  
        scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
    
        system("cls"); //Respons�vel por limpar a tela
        
        switch(opcao) //In�cio da sele��o
        {
           case 1:
           registrar(); //Chamada de fun��es
           break;
         
           case 2:
           consultar(); //Chamada de fun��es                     
           break;
         
           case 3:
           deletar(); //Chamada de fun��es 
           break;
           
           case 4: 
           printf("Obrigado por utilizar nosso sistema/n"); //Chamada de fun��es
           return 0;
           break;
           
           default:
           printf("Op��o n�o dispon�vel\n"); 
           system("pause"); //Respons�vel por pausar o sistema       
           break;
         
        }
        
        system("pause >nul"); //Pausa o sistema at� que o usu�rio aperte qualquer tecla
    }
}
