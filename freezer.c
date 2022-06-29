#include <stdio.h>

typedef struct{
  char marca[30];
  int litros;
  int garantia;
  float consumo;
}freezer;

int main(void) {
  int option=9;
  int posicao=0;
  freezer f[5];
  int maior=0;
  freezer aux;
  while(option!=0){
    if(posicao==5){
      printf("\nSaindo adicionou o máximo de freezes!");
      printf("\nO freezer com maior capacidade é %s com capacidade de %i litros:", aux.marca, aux.litros);
      break;
    }
    printf("\nDigite 1 para incluir um freezer: ");
    printf("\nDigite 2 para ver freezer com maior garantia: ");
    printf("\nDigite 0 para sair do programa!\n");
    scanf("%i", &option);
    
    switch(option){
      case 1:
        printf("\nDigite a marca do freezer: ");
        scanf("%s",f[posicao].marca);
        printf("\nDigite a capacidade em litros: ");
        scanf("%i", &f[posicao].litros);
        printf("\nDigite quantos meses de garantia o freezer tem: ");
        scanf("%i",&f[posicao].garantia);
        printf("\nDigite o consumo do freezer mensal: ");
        scanf("%f",&f[posicao].consumo);
        posicao ++;
      break;

      case 2:
        for(int i=0; i<posicao; i++){
          if(f[i].litros > maior){
            aux = f[i];
          }
        }
        printf("\nO freezer com maior capacidade é %s com capacidade de %i litros:", aux.marca, aux.litros);
      break;

      case 0:
        printf("\nSaindo\n");
        option = 0;
      break;
    }
  }

  
    
  
  return 0;
}