#include <stdio.h>

typedef struct{
  char nome[30];
  char endereco[50];
  char cidade[50];
  char estado[50];
  char cep[50];
}Pessoa;

Pessoa preenchestructs(){
    Pessoa pessoaP;
    int tamanho=4;
    printf("\nDigite o nome: ");
      scanf("%s", pessoaP.nome);    
    printf("\nDigite o endereço: ");
      scanf("%s", pessoaP.endereco);
    printf("\nDigite a cidade: ");
      scanf("%s", pessoaP.cidade);
    printf("\nDigite o estado: ");
      scanf("%s", pessoaP.estado);
    printf("\nDigite o cep: ");
      scanf("%s", pessoaP.cep);
    return pessoaP;
}

Pessoa imprimirPessoas(Pessoa *pessoaP){
    int tamanho = 4;
    for(int i=0; i<tamanho; i++){
        printf("\n%s",pessoaP->nome );
        printf("\n%s",pessoaP->endereco);
        printf("\n%s",pessoaP->cidade);
        printf("\n%s",pessoaP->estado);
        printf("\n%s",pessoaP->cep);
        pessoaP++;
    }
}

Pessoa alterarPessoas(Pessoa *pessoasP){
    char nome[30];
    printf("Qual o nome da pessoa que você deseja alterar? ");
        setbuf(stdin,NULL);
        scanf("%s", nome);
    for (int i = 0; i < 4; i++)
    {
        if(pessoasP->nome == nome){
            printf("\nDigite o nome: ");
                scanf("%s", pessoasP->nome);    
            printf("\nDigite o endereço: ");
                scanf("%s", pessoasP->endereco);
            printf("\nDigite a cidade: ");
                scanf("%s", pessoasP->cidade);
            printf("\nDigite o estado: ");
                scanf("%s", pessoasP->estado);
            printf("\nDigite o cep: ");
                scanf("%s", pessoasP->cep);
        }
        pessoasP++;
    }
    printf("%s", nome);
    printf("%s", pessoasP->nome);
}


int main(){
    Pessoa pessoas[4];
    int option;
    while(option != 0){
        printf("\nDigite 1 para cadastrar pessoas");
        printf("\nDigite 2 para alterar dados de alguém");
        printf("\nDigite 3 para listar");
        printf("\nDigite 0 para sair");
        printf("\nOpção: ");
        scanf("%i", &option);

        if (option == 1)
        {
        for(int i=0; i<4; i++){
            pessoas[i] = preenchestructs();
        }
        }else
        if (option == 2)
        {
             alterarPessoas(pessoas);
        }else
        if (option == 3)
        {
             imprimirPessoas(pessoas);
        }
    }
    printf("Saindo");

    return 0;
  }

   