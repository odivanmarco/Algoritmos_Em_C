#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  char nome[50];
  int quantidade;
  float preco;
  char estado[2];
}Produto;

void ordenarProdutos(Produto produtos[], int tamanho)
{
    Produto temp;
    // Ordenando o vetor usando o metodo Bubble Sort
    for (int i=0; i<tamanho-1; i++)
    {
        for (int j=0; j<tamanho-1-i; j++)
        {
            if (strcmp(produtos[j].nome, produtos[j+1].nome) > 0)
            {
                temp = produtos[j];
                produtos[j] = produtos[j+1];
                produtos[j+1] = temp;
            }
        }
    }
}

void carregarArquivo(char *nomeArq, Produto produtos[]){
    FILE *arq;
    arq = fopen(nomeArq,"r");
    int quant_produto;
    fscanf(arq, "%i", &quant_produto);
    produtos[quant_produto];
    int i = 0;
    while(!feof(arq)){
      fscanf(arq, "%i", &produtos[i].codigo);
      fscanf(arq, "%s", produtos[i].nome);
      fscanf(arq, "%i", &produtos[i].quantidade);
      fscanf(arq, "%f", &produtos[i].preco);
      fscanf(arq, "%s", produtos[i].estado);
        i++;
    }
    fclose(arq);
}

void relatorioProdutos(char *nomeArq, Produto produtos[], int tamanho){
      ordenarProdutos(produtos,tamanho);
      FILE *arq;
      arq = fopen(nomeArq,"w");
      for(int i=0; i<tamanho; i++){
        fprintf(arq,"%i\n", produtos[i].codigo);
        fprintf(arq,"%s\n", produtos[i].nome);
        fprintf(arq,"%i\n", produtos[i].quantidade);
        fprintf(arq,"%f\n", produtos[i].preco);
        fprintf(arq,"%s\n", produtos[i].estado);
      }
      fclose(arq);
}

void quantidadeTotal(Produto produtos[], int tamanho){
      int somaTotal = 0;
      for(int i=0; i<tamanho; i++){
        somaTotal += produtos[i].quantidade;
      }
      printf("\nQuantidade total de itens é: %i\n", somaTotal);
}

void menorEstoque(Produto produtos[], int tamanho){
      int menor=99999999;
      Produto p;
      for(int i=0; i<tamanho; i++){
        if(produtos[i].quantidade < menor){
          p = produtos[i];
          menor = produtos[i].quantidade;
        }
      }
      printf("\n%i", p.codigo);
      printf("\n%s", p.nome);
      printf("\n%i", p.quantidade);
      printf("\n%.2f", p.preco);
      printf("\n%s\n", p.estado);
}

void menorEstoqueEstado(char *estado,Produto produtos[], int tamanho){
      int menor = 999999999,verificaIgualdade;
      Produto p;
      for(int i=0; i<tamanho; i++){
        verificaIgualdade = strcmp(produtos[i].estado,estado);
        if (verificaIgualdade == 0){
          if(produtos[i].quantidade < menor){
            p = produtos[i];
            menor = produtos[i].quantidade;
          }
        }
      }
      printf("\n%i", p.codigo);
      printf("\n%s", p.nome);
      printf("\n%i", p.quantidade);
      printf("\n%.2f", p.preco);
      printf("\n%s\n", p.estado);
}

void listarPorEstado(char *estado,Produto produtos[], int tamanho){
      int verificaIgualdade;
      for(int i=0; i<tamanho; i++){
        verificaIgualdade = strcmp(produtos[i].estado,estado);
        if (verificaIgualdade == 0)
        {
          printf("\n%i", produtos[i].codigo);
          printf("\n%s", produtos[i].nome);
          printf("\n%i", produtos[i].quantidade);
          printf("\n%f", produtos[i].preco);
          printf("\n%s\n", produtos[i].estado);
        }
      }
}

void imprimeProduto(int codigo, Produto produtos[], int tamanho){
      Produto p;
      int encontrou = 0;
      for(int i=0; i<tamanho; i++){
        if(produtos[i].codigo == codigo){
          p = produtos[i];
          encontrou = 1;
        }
      }
      if(encontrou == 0){
        printf("\nProduto não encontrado\n");
      }
      else if(encontrou == 1){
          printf("\n%i", p.codigo);
          printf("\n%s", p.nome);
          printf("\n%i", p.quantidade);
          printf("\n%.2f", p.preco);
          printf("\n%s\n", p.estado);
      }
}

int main(int argc,char **argv){
    FILE *arq;
    arq = fopen(argv[1],"r");
    int quant_produto;
    fscanf(arq, "%i", &quant_produto);
    Produto produtos[quant_produto];
    carregarArquivo(argv[1], produtos);
    int option = atoi(argv[2]);

  if(option == 1){
    printf("\n-=-=-=-=-= RELATORIO DE ESTOQUE =-=-=-=-=-");
    relatorioProdutos(argv[3],produtos,quant_produto);
    printf("\nSeu relatório está pronto no arquivo %s\n", argv[3]);
  }
  else if(option == 2){
    printf("\n-=-=-=-=-= PESQUISAR PELO CÓDIGO =-=-=-=-=-");
    int codigo = atoi(argv[3]);
    imprimeProduto(codigo,produtos,quant_produto);
  }
  else if (option == 3){
    printf("\n-=-=-=-=-=  PRODUTO COM MENOR ESTOQUE =-=-=-=-=-");
    menorEstoque(produtos,quant_produto);
  }
  else if (option == 4){
    printf("\n-=-=-=-=-= LISTA DE PRODUTOS POR ESTADO =-=-=-=-=-");
    listarPorEstado(argv[3],produtos,quant_produto);
  }
  else if (option == 5){
    printf("\n-=-=-=-=-= PRODUTO COM MENOR ESTOQUE NO ESTADO =-=-=-=-=-");
    menorEstoqueEstado(argv[3],produtos,quant_produto);
  }
  else if (option == 6){
    printf("\n-=-=-=-=-= TOTAL DE ITENS NO ESTOQUE =-=-=-=-=-");
    quantidadeTotal(produtos, quant_produto);
  }
}