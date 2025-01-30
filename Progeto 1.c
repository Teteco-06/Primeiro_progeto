#include <stdio.h> //Dbiblioteca de comunicação com o usuário
#include <stdlib.h> //Ebiblioteca de alocação de espaço em memória
#include <locale.h> //Jbiblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsavel pelas strings

int registro() // 1 cadastrode nomes
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem de usuário
	
	char arquivo[40]; //Começo das strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Fim da strings
	
	printf("Digite o CPF a ser cadastrado: "); //comunicação com o usuario
	scanf("%s", cpf); //salva os dados do usuário %s salva todas as strings
	
	strcpy(arquivo, cpf); //responsavel por igualar os valores
	
	FILE *file; // cria arquivos e define file como o nome do arquivo
	file = fopen(arquivo, "w"); //composiçao do FILE * , "W"- escrever / fopen abreo arquivo
	fprintf(file,cpf); //salva o valor da variavel / sa
	fclose(file); //fecha o comando
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobre nome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
    file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar() 
{
    setlocale(LC_ALL, "Portuguese"); //defini linguagem
    
    
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o cpf para consulta: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r"); // o "r" aqui siguinifica "ler" em ingles
	
	
	if(file == NULL) // NULL = nulo // if = si
	{
	    printf("\tCPF nao localizado.\n");	
    }      
    
           
    while(fgets(conteudo, 200, file) != NULL) //while = emquanto //
    {
		printf("\n \tEssas são as informações do usuario!\n");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    

    system("pause");

}

int deletar() 
{
	char cpf[40];
	
	printf("\tDigite o CPF a ser DELETADO: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\tCPF nao encontrado.\n");
		system("pause");
	}
	
}



int main() 
    {
     int opcao = 0; //defini variavel
     int vt=1; //int: Número inteiro ( para mencionar em um texto: %i ou %d )
     
     for(vt=1;vt==1;)
    {
    	
	  system("cls");
	  
      setlocale(LC_ALL, "Portuguese");

      printf("\t@@@ Sejam bem vindos @@@\n\n\tCadastro de usuários\n\n");
      printf("\tMenu.\n\n");
      printf("\t1 - Registrar nomes.\n"); //opções
      printf("\t2 - Consultar nomes.\n"); //opções
      printf("\t3 - Deletar nome.\n\n"); //opções
      printf("\t4 - Sair do programa!\n\n");
      printf("Escolha uma opção: "); //Fim do menu

    scanf("%d", &opcao);//armazena a ecolha do usuário

    system("cls");//finalizar instruções 
    
     switch (opcao) //Switch é usado para maior armazenamento de variáveis=if
	 {
            case 1://começo de instrução
                registro();
                break;//finalizar a variavel

            case 2:
                consultar();
                break;

            case 3:
                deletar();
                break;
				
			case 4:
			    printf("\t\n\n@@@Obrigado volte sempre!@@@\n\n");
				return 0;
				break;	               

            default://se não for nenhuma das opções=else
                printf("\tOpção inválida!\n");
                system("pause");
                break;
    
    }
}
    printf("\tObrigado a todos(as) que colaboraram para que nosso sistema vá adiante!\n\tAss:MatheusLCS. Jesus Te ama!!!\n");

    return 0;
}
